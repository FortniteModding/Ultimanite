/*
Lunar / Ultimanite
Copyright (C) 2021 Daniele Giompaolo

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "framework.h"
#include "gameplay.h"
#include "patterns.h"

void Setup()
{
	Util::SetupConsole();

	EEngineVersion CurrentVersion = EEngineVersion::None;

	auto GObjectsAddress = Util::FindPattern(UE_4_20_GOBJECTS);
	auto ToStringAddress = Util::FindPattern(UE_4_20_FNAME_TOSTRING);
	auto GetFirstPlayerControllerAddress = Util::FindPattern(UE_4_20_GETFIRSTPLAYERCONTROLLER);
	auto SpawnActorFromClassAddress = Util::FindPattern(UE_4_20_SPAWNACTORFROMCLASS);
	auto LoadObjectAddress = Util::FindPattern(UE_4_20_LOADOBJECT);
	auto ConstructObjectAddress = Util::FindPattern(UE_4_20_CONSTRUCTOBJECT);
	auto FreeAddress = Util::FindPattern(UE_4_20_FREE);

	if (GObjectsAddress && ToStringAddress && GetFirstPlayerControllerAddress && SpawnActorFromClassAddress && ConstructObjectAddress && FreeAddress)
	{
		if (!LoadObjectAddress)
		{
			LoadObjectAddress = Util::FindPattern("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 48 8B EC 48 83 EC 78 33 C0");
			CurrentVersion = EEngineVersion::UE_4_20;
		}
		else
		{
			CurrentVersion = EEngineVersion::UE_4_20;
		}
		
	}

	// not able to find any version yet, lets try again
	if (CurrentVersion == EEngineVersion::None)
	{
		GObjectsAddress = Util::FindPattern(UE_4_21_GOBJECTS);
		ToStringAddress = Util::FindPattern(UE_4_21_FNAME_TOSTRING);
		GetFirstPlayerControllerAddress = Util::FindPattern(UE_4_21_GETFIRSTPLAYERCONTROLLER);
		SpawnActorFromClassAddress = Util::FindPattern(UE_4_21_SPAWNACTORFROMCLASS);
		LoadObjectAddress = Util::FindPattern(UE_4_21_LOADOBJECT);
		ConstructObjectAddress = Util::FindPattern(UE_4_21_CONSTRUCTOBJECT);
		FreeAddress = Util::FindPattern(UE_4_21_FREE);

		if (GObjectsAddress && ToStringAddress && GetFirstPlayerControllerAddress && SpawnActorFromClassAddress && LoadObjectAddress && ConstructObjectAddress && FreeAddress)
		{
			CurrentVersion = EEngineVersion::UE_4_21;
		}
	}

	// not able to find any version yet, lets try again
	if (CurrentVersion == EEngineVersion::None)
	{
		GObjectsAddress = Util::FindPattern(UE_4_22_GOBJECTS);
		ToStringAddress = Util::FindPattern(UE_4_22_FNAME_TOSTRING);
		GetFirstPlayerControllerAddress = Util::FindPattern(UE_4_22_GETFIRSTPLAYERCONTROLLER);
		SpawnActorFromClassAddress = Util::FindPattern(UE_4_22_SPAWNACTORFROMCLASS);
		LoadObjectAddress = Util::FindPattern(UE_4_22_LOADOBJECT);
		ConstructObjectAddress = Util::FindPattern(UE_4_22_CONSTRUCTOBJECT);
		FreeAddress = Util::FindPattern(UE_4_22_FREE);

		if (GObjectsAddress && ToStringAddress && GetFirstPlayerControllerAddress && SpawnActorFromClassAddress && LoadObjectAddress && ConstructObjectAddress && FreeAddress)
		{
			CurrentVersion = EEngineVersion::UE_4_22;
		}
	}

	if (CurrentVersion == EEngineVersion::None)
	{
		printf("Unsupported Engine version!\n");
		return;
	}

	auto ObjectsOffset = *(int32_t*)(GObjectsAddress + 3);
	auto FinalObjectsAddress = GObjectsAddress + 7 + ObjectsOffset;

	if (CurrentVersion >= EEngineVersion::UE_4_21)
	{
		// support recent version of GObjects
		GlobalObjects = decltype(GlobalObjects)(FinalObjectsAddress);
	}
	else
	{
		// support legacy version of GObjects
		ObjObjects = decltype(ObjObjects)(FinalObjectsAddress);
	}

	FNameToString = decltype(FNameToString)(ToStringAddress);
	GetFirstPlayerController = decltype(GetFirstPlayerController)(GetFirstPlayerControllerAddress);
	SpawnActor = decltype(SpawnActor)(SpawnActorFromClassAddress);
	StaticConstructObjectInternal = decltype(StaticConstructObjectInternal)(ConstructObjectAddress);
	StaticLoadObjectInternal = decltype(StaticLoadObjectInternal)(LoadObjectAddress);
	FreeInternal = decltype(FreeInternal)(FreeAddress);

	auto CurrentEngineVersion = std::stof(RuntimeOptions::GetFortniteVersion());

	if (7.4 <= CurrentEngineVersion && !strstr(RuntimeOptions::GetFortniteVersion().c_str(), "8"))
	{
		ProcessEvent = decltype(ProcessEvent)(FindObject(L"FortEngine_")->VTableObject[0x41]);
	}
	else
	{
		ProcessEvent = decltype(ProcessEvent)(FindObject(L"FortEngine_")->VTableObject[0x40]);
	}

	// we are ready to enter a game
	Game::Setup();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		Setup();
	}

	return TRUE;
}
