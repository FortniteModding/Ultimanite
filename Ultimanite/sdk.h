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

#pragma once
#include "framework.h"

namespace Globals
{
	inline UObject* Controller;
	inline UObject* GameState;
	inline UObject* GameMode;
	inline UObject* CheatManager;
	inline UObject* Pawn;
	inline UObject* PawnClass;
	inline UObject* BattleBusClass;
	inline UObject* PlayerState;
	inline UObject* FortInventory;
	inline UObject* Quickbar;
	inline TArray<UObject*>* ItemInstances;
	inline UObject* GamePlayStatics;
	inline UObject* World;
	inline duk_context* DukContext;
	inline UObject* ChestsSound;
	inline UObject* AmmoBoxSound;
	inline const char* FortniteVersion;
	inline UObject* InviteToilet;
	inline __int64 BuildingOffset;
	inline bool bCanBuild;
	inline bool _bCanBuild;

	//THIS IS TEMPORARY!!!!
	inline UObject* BotController;
	inline UObject* BotPawn;
	inline FVector BotTarget;
}

namespace Offsets
{
	DWORD ItemInstancesOffset;
	DWORD ItemEntriesOffset;
	DWORD ItemEntryOffset;
	DWORD WorldInventoryOffset;
	DWORD QuickBarOffset;
	DWORD GamePhaseOffset;
	DWORD StrongMyHeroOffset;
	DWORD CharacterMeshOffset;
	DWORD HeroCharacterPartsOffset;
	DWORD AdditionalDataOffset;
	DWORD PlayerStateOffset;
	DWORD PlayerStatePawnOffset;
	DWORD FortItemEntryOffset;
	DWORD PrimaryPickupItemEntryOffset;
	DWORD InventoryOffset;
	DWORD CountOffset;
	DWORD ItemDefinitionOffset;
	DWORD CharacterPartsOffset;
	DWORD MovementStyleOffset;
	DWORD bWantsToSprintOffset;
	DWORD bInAircraftOffset;
	DWORD bInfiniteAmmo;
	DWORD SlotsOffset;
	DWORD PrimaryQuickbarOffset;
	DWORD MinimapCircleBrushOffset;
	DWORD MinimapSafeZoneBrushOffset;
	DWORD MinimapBackgroundBrushOffset;
	DWORD MinimapNextCircleBrushOffset;
	DWORD FloatingIslandBrushOffset;
	DWORD FloatingIslandBrushActivatedOffset;
	DWORD FullMapCircleBrushOffset;
	DWORD FullMapNextCircleBrushOffset;
	DWORD MinimapSafeZoneFinalPosBrushOffset;
	DWORD bReadyToStartMatchOffset;
	DWORD bClientPawnIsLoadedOffset;
	DWORD bHasClientFinishedLoadingOffset;
	DWORD bHasServerFinishedLoadingOffset;
	DWORD CurrentBuildableClassOffset;
	DWORD LastBuildLocationOffset;
	DWORD LastBuildRotationOffset;
	DWORD PreferredQuickbarSlotOffset;
	DWORD ItemGuidOffset;
	DWORD CurrentFocusedSlotOffset;
	DWORD OverriddenBackpackSizeOffset;
	DWORD GameViewportOffset;
	DWORD ViewportConsoleOffset;
	DWORD CurrentPlaylistDataOffset;
	DWORD WeaponActorClassOffset;
	DWORD WeaponDataOffset;
	DWORD ItemEntryGuidOffset;
	DWORD AmmoCountOffset;
	DWORD CurrentWeaponOffset;
	DWORD AbilitySystemComponentOffset;
	DWORD DurationPolicyOffset;
	DWORD GrantedAbilitiesOffset;
	DWORD AbilityOffset;
	DWORD TextRenderOffset;
	DWORD DynamicFoundationTypeOffset;
	DWORD CheatManagerOffset;
	DWORD RoleOffset;
	DWORD bAlreadySearchedOffset;
	DWORD TargetedBuildingOffset;
	DWORD AuthorityGameMode;
	DWORD InteractionText;
	DWORD CurrentlyBeingEditedOffset;
	DWORD BuildPreviewMarkerOffset;
	DWORD CurrentResourceTypeOffset;
}

static void SetupOffsets()
{
	Offsets::ItemInstancesOffset = FindOffset(_(L"ArrayProperty /Script/FortniteGame.FortItemList.ItemInstances"));
	Offsets::ItemEntriesOffset = FindOffset(_(L"ArrayProperty /Script/FortniteGame.FortItemList.ReplicatedEntries"));
	Offsets::ItemEntryOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortWorldItem.ItemEntry"));
	Offsets::WorldInventoryOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPlayerController.WorldInventory"));
	Offsets::GamePhaseOffset = FindOffset(_(L"EnumProperty /Script/FortniteGame.FortGameStateAthena.GamePhase"));
	Offsets::StrongMyHeroOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPlayerControllerAthena.StrongMyHero"));
	Offsets::CharacterMeshOffset = FindOffset(_(L"ObjectProperty /Script/Engine.Character.Mesh"));
	Offsets::CharacterPartsOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPlayerState.CharacterParts"));
	Offsets::AdditionalDataOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.CustomCharacterPart.AdditionalData"));
	Offsets::PlayerStateOffset = FindOffset(_(L"ObjectProperty /Script/Engine.Controller.PlayerState"));
	Offsets::PlayerStatePawnOffset = FindOffset(_(L"ObjectProperty /Script/Engine.Pawn.PlayerState"));
	Offsets::FortItemEntryOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortWorldItem.ItemEntry"));
	Offsets::PrimaryPickupItemEntryOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortPickup.PrimaryPickupItemEntry"));
	Offsets::CountOffset = FindOffset(_(L"IntProperty /Script/FortniteGame.FortItemEntry.Count"));
	Offsets::ItemDefinitionOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortItemEntry.ItemDefinition"));
	Offsets::MovementStyleOffset = FindOffset(_(L"ByteProperty /Script/FortniteGame.FortPawn.CurrentMovementStyle"));
	Offsets::bWantsToSprintOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bWantsToSprint"));
	Offsets::bInfiniteAmmo = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bInfiniteAmmo"));
	Offsets::CurrentWeaponOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPawn.CurrentWeapon"));
	Offsets::bInAircraftOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerStateAthena.bInAircraft"));
	Offsets::SlotsOffset = FindOffset(_(L"ArrayProperty /Script/FortniteGame.QuickBar.Slots"));
	Offsets::PrimaryQuickbarOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortQuickBars.PrimaryQuickBar"));
	Offsets::CurrentFocusedSlotOffset = FindOffset(_(L"IntProperty /Script/FortniteGame.QuickBar.CurrentFocusedSlot"));
	Offsets::MinimapBackgroundBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.MinimapBackgroundBrush"));
	Offsets::MinimapSafeZoneBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.MinimapSafeZoneBrush"));
	Offsets::MinimapCircleBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.MinimapCircleBrush"));
	Offsets::MinimapNextCircleBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.MinimapNextCircleBrush"));
	Offsets::FloatingIslandBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.FloatingIslandBrush"));
	Offsets::FloatingIslandBrushActivatedOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.FloatingIslandBrushActivated"));
	Offsets::FullMapCircleBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.FullMapCircleBrush"));
	Offsets::FullMapNextCircleBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.FullMapNextCircleBrush"));
	Offsets::MinimapSafeZoneFinalPosBrushOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortGameStateAthena.MinimapSafeZoneFinalPosBrush"));
	Offsets::bReadyToStartMatchOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bReadyToStartMatch"));
	Offsets::bClientPawnIsLoadedOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bClientPawnIsLoaded"));
	Offsets::bHasClientFinishedLoadingOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bHasClientFinishedLoading"));
	Offsets::bHasServerFinishedLoadingOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.FortPlayerController.bHasServerFinishedLoading"));
	Offsets::CurrentBuildableClassOffset = FindOffset(_(L"ClassProperty /Script/FortniteGame.FortPlayerController.CurrentBuildableClass"));
	Offsets::LastBuildLocationOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortPlayerController.LastBuildPreviewGridSnapLoc"));
	Offsets::LastBuildRotationOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortPlayerController.LastBuildPreviewGridSnapRot"));
	Offsets::PreferredQuickbarSlotOffset = FindOffset(_(L"IntProperty /Script/FortniteGame.FortWorldItemDefinition.PreferredQuickbarSlot"));
	Offsets::ItemGuidOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortItemEntry.ItemGuid"));
	Offsets::OverriddenBackpackSizeOffset = FindOffset(_(L"IntProperty /Script/FortniteGame.FortPlayerController.OverriddenBackpackSize"));
	Offsets::GameViewportOffset = FindOffset(_(L"ObjectProperty /Script/Engine.Engine.GameViewport"));
	Offsets::ViewportConsoleOffset = FindOffset(_(L"ObjectProperty /Script/Engine.GameViewportClient.ViewportConsole"));
	Offsets::CurrentPlaylistDataOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortGameStateAthena.CurrentPlaylistData"));
	Offsets::InventoryOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortInventory.Inventory"));
	Offsets::WeaponActorClassOffset = FindOffset(_(L"SoftClassProperty /Script/FortniteGame.FortWeaponItemDefinition.WeaponActorClass"));
	Offsets::WeaponDataOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortWeapon.WeaponData"));
	Offsets::ItemEntryGuidOffset = FindOffset(_(L"StructProperty /Script/FortniteGame.FortWeapon.ItemEntryGuid"));
	Offsets::AmmoCountOffset = FindOffset(_(L"IntProperty /Script/FortniteGame.FortWeapon.AmmoCount"));
	Offsets::AbilitySystemComponentOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPawn.AbilitySystemComponent"));
	Offsets::DurationPolicyOffset = FindOffset(_(L"EnumProperty /Script/GameplayAbilities.GameplayEffect.DurationPolicy"));
	Offsets::GrantedAbilitiesOffset = FindOffset(_(L"ArrayProperty /Script/GameplayAbilities.GameplayEffect.GrantedAbilities"));
	Offsets::AbilityOffset = FindOffset(_(L"ClassProperty /Script/GameplayAbilities.GameplayAbilitySpecDef.Ability"));
	Offsets::TextRenderOffset = FindOffset(_(L"ObjectProperty /Script/Engine.TextRenderActor.TextRender"));
	Offsets::DynamicFoundationTypeOffset = FindOffset(_(L"EnumProperty /Script/FortniteGame.BuildingFoundation.DynamicFoundationType"));
	Offsets::CheatManagerOffset = FindOffset(_(L"ObjectProperty /Script/Engine.PlayerController.CheatManager"));
	Offsets::RoleOffset = FindOffset(_(L"ByteProperty /Script/Engine.Actor.Role"));
	Offsets::bAlreadySearchedOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.BuildingContainer.bAlreadySearched"));
	Offsets::TargetedBuildingOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPlayerController.TargetedBuilding"));
	Offsets::AuthorityGameMode = FindOffset(_(L"ObjectProperty /Script/Engine.World.AuthorityGameMode"));
	Offsets::InteractionText = FindOffset(_(L"TextProperty /Script/FortniteGame.BuildingActor.InteractionText"));
	Offsets::CurrentlyBeingEditedOffset = FindOffset(_(L"BoolProperty /Script/FortniteGame.BuildingSMActor.bCurrentlyBeingEdited"));
	Offsets::BuildPreviewMarkerOffset = FindOffset(_(L"ObjectProperty /Script/FortniteGame.FortPlayerController.BuildPreviewMarker"));
	Offsets::CurrentResourceTypeOffset = FindOffset(_(L"ByteProperty /Script/FortniteGame.FortPlayerController.CurrentResourceType"));
}

enum class EFortQuickBars : uint8_t
{
	Primary, Secondary, Max_None, EFortQuickBars_MAX
};

enum class EGameplayEffectDurationType : uint8_t
{
	Instant, Infinite, HasDuration, EGameplayEffectDurationType_MAX
};

struct FSlateBrush
{
	unsigned char Unk00[0x48];
	UObject* ObjectResource; // 0x08
};

struct QuickbarSlot
{
	TArray<struct FGuid> Items;
	bool bEnabled;
	char Unk00[0x7];
};

struct InventoryPointer
{
	UObject* Inventory;
};

struct QuickBarPointer
{
	UObject* QuickBar;
};

enum class EDynamicFoundationType : uint8_t
{
	Static = 0, StartEnabled_Stationary = 1, StartEnabled_Dynamic = 2, StartDisabled = 3, EDynamicFoundationType_MAX = 4
};

namespace Kismet
{
	static auto FStringToFName(FString inString) -> FName
	{
		static auto lib = FindObject(L"KismetStringLibrary /Script/Engine.Default__KismetStringLibrary");
		static auto func = FindObject(L"Function /Script/Engine.KismetStringLibrary.Conv_StringToName");

		struct Params
		{
			FString s;
			FName ret;
		};

		Params params;
		params.s = inString;

		ProcessEvent(lib, func, &params);

		return params.ret;
	}

	static auto FStringToFText(FString inString) -> FText
	{
		static auto lib = FindObject(L"KismetTextLibrary /Script/Engine.Default__KismetTextLibrary");
		static auto func = FindObject(L"Function /Script/Engine.KismetTextLibrary.Conv_StringToText");

		struct Params
		{
			FString s;
			FText ret;
		};

		Params params;
		params.s = inString;

		ProcessEvent(lib, func, &params);

		return params.ret;
	}

	static auto FNameToFString(FName InName)
	{
		static auto lib = FindObject(L"KismetStringLibrary /Script/Engine.Default__KismetStringLibrary");
		static auto func = FindObject(L"Function /Script/Engine.KismetStringLibrary.Conv_NameToString");

		struct
		{
			FName In;
			FString ret;
		} Params;

		Params.In = InName;

		ProcessEvent(lib, func, &Params);

		return Params.ret;
	}

	static FSlateBrush NoResourceBrush()
	{
		static UObject* Default__WidgetBlueprintLibrary = FindObject(L"WidgetBlueprintLibrary /Script/UMG.Default__WidgetBlueprintLibrary");
		static UObject* NoResourceBrush = FindObject(L"Function /Script/UMG.WidgetBlueprintLibrary.NoResourceBrush");

		FSlateBrush ReturnValue;
		ProcessEvent(Default__WidgetBlueprintLibrary, NoResourceBrush, &ReturnValue);

		return ReturnValue;
	}

	static UObject* Conv_SoftClassReferenceToClass(TSoftObjectPtr<UObject*> SoftPtr)
	{
		static UObject* Default__KismetSystemLibrary = FindObject(L"KismetSystemLibrary /Script/Engine.Default__KismetSystemLibrary");
		static UObject* Conv_SoftClassReferenceToClass = FindObject(L"Function /Script/Engine.KismetSystemLibrary.Conv_SoftClassReferenceToClass");

		struct
		{
			TSoftObjectPtr<UObject*> SoftClassReference;
			UObject* Class;
		} Params;

		Params.SoftClassReference = SoftPtr;

		ProcessEvent(Default__KismetSystemLibrary, Conv_SoftClassReferenceToClass, &Params);

		return Params.Class;
	}

	static void ExecuteConsoleCommand(FString Cmd)
	{
		static UObject* Default__KismetSystemLibrary = FindObject(L"KismetSystemLibrary /Script/Engine.Default__KismetSystemLibrary");
		static UObject* Conv_SoftClassReferenceToClass = FindObject(L"Function /Script/Engine.KismetSystemLibrary.ExecuteConsoleCommand");

		struct
		{
			UObject* WorldContextObject;
			FString Command;
			UObject* SpecificPlayer;
		} Params;

		Params.WorldContextObject = GetWorld();
		Params.Command = Cmd;
		Params.SpecificPlayer = Globals::Controller;

		ProcessEvent(Default__KismetSystemLibrary, Conv_SoftClassReferenceToClass, &Params);
	}

	static void Say(FString Msg)
	{
		static UObject* World = GetWorld();
		static UObject* AuthorityGameMode = *reinterpret_cast<UObject**>(__int64(World) + __int64(Offsets::AuthorityGameMode));

		static UObject* Say = FindObject(L"Function /Script/Engine.GameMode.Say");

		ProcessEvent(AuthorityGameMode, Say, &Msg);
	}
}

namespace Weapon
{
	static void OnRep_ReplicatedWeaponData(UObject* Weapon)
	{
		static UObject* OnRep_ReplicatedWeaponData = FindObject(L"Function /Script/FortniteGame.FortWeapon.OnRep_ReplicatedWeaponData");

		ProcessEvent(Weapon, OnRep_ReplicatedWeaponData, nullptr);
	}

	static void ClientGivenTo(UObject* Weapon, UObject* Pawn)
	{
		static UObject* ClientGivenTo = FindObject(L"Function /Script/FortniteGame.FortWeapon.ClientGivenTo");

		ProcessEvent(Weapon, ClientGivenTo, &Pawn);
	}

	static void OnRep_AmmoCount(UObject* Weapon)
	{
		static UObject* OnRep_AmmoCount = FindObject(L"Function /Script/FortniteGame.FortWeapon.OnRep_AmmoCount");
		int OldAmmoCount = 0;

		ProcessEvent(Weapon, OnRep_AmmoCount, &OldAmmoCount);
	}
}

namespace GameMode
{
	static void StartMatch(UObject* InGameMode)
	{
		static UObject* StartMatch = FindObject(L"Function /Script/Engine.GameMode.StartMatch");

		ProcessEvent(InGameMode, StartMatch, nullptr);
	}
}

namespace RuntimeOptions
{
	static FString GetGameVersion()
	{
		static UObject* Default__FortRuntimeOptions = FindObject(L"FortRuntimeOptions /Script/FortniteGame.Default__FortRuntimeOptions");
		static UObject* GetGameVersion = FindObject(L"Function /Script/FortniteGame.FortRuntimeOptions.GetGameVersion");

		if (GetGameVersion)
		{
			FString GameVersion;
			ProcessEvent(Default__FortRuntimeOptions, GetGameVersion, &GameVersion);

			return GameVersion;
		}
		return L"Unknown";
	}

	static std::string GetFortniteVersion()
	{
		void* Result;
		static auto Add = Util::FindPattern(_("40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8B C8 41 B8 04 ? ? ? 48 8B D3"));
		auto String = reinterpret_cast<FString* (__fastcall*)(void*)>(Add)(&Result)->ToString();
		return String.substr(34, 4);
	}
}

namespace Building
{
	static bool IsInBuildMode()
	{
		static auto func = FindObject(L"Function /Script/FortniteGame.FortPlayerController.IsInBuildMode");

		bool poop;

		ProcessEvent(Globals::Controller, func, &poop);
		return poop;
	}

	static void InitializeBuildingActor(UObject* BuildingActor)
	{
		static UObject* InitializeKismetSpawnedBuildingActor = FindObject(L"Function /Script/FortniteGame.BuildingActor.InitializeKismetSpawnedBuildingActor");

		struct Params
		{
			UObject* BuildingOwner;
			UObject* SpawningController;
		};

		Params params;
		params.BuildingOwner = BuildingActor;
		params.SpawningController = Globals::Controller;

		ProcessEvent(BuildingActor, InitializeKismetSpawnedBuildingActor, &params);
	}
	
	static void K2_SetCurrentResourceType(UObject* Controller, EFortResourceType ResourceType)
	{
		static UObject* K2_SetCurrentResourceType = FindObject(L"Function /Script/FortniteGame.FortKismetLibrary.K2_SetCurrentResourceType");
		static UObject* FortKismetLib = FindObject(L"FortKismetLibrary /Script/FortniteGame.Default__FortKismetLibrary");

		struct 
		{
			UObject* Controller;
			EFortResourceType Resource;
		} params;

		params.Controller = Controller;
		params.Resource = ResourceType;

		ProcessEvent(FortKismetLib, K2_SetCurrentResourceType, &params);
	}
}

namespace AActor
{
	static FVector GetLocation(UObject* Target)
	{
		static auto K2_GetActorLocation = FindObject(L"Function /Script/Engine.Actor.K2_GetActorLocation");

		struct
		{
			FVector ret;
		} Params;

		ProcessEvent(Target, K2_GetActorLocation, &Params);

		return Params.ret;
	}

	static FRotator GetRotation(UObject* Target)
	{
		static auto K2_GetActorRotation = FindObject(L"Function /Script/Engine.Actor.K2_GetActorRotation");

		struct
		{
			FRotator ret;
		} Params;

		ProcessEvent(Target, K2_GetActorRotation, &Params);

		return Params.ret;
	}

	static void SetActorScale3D(UObject* Target, FVector NewScale3D = {})
	{
		static auto SetActorScale3D = FindObject(L"Function /Script/Engine.Actor.SetActorScale3D");

		ProcessEvent(Target, SetActorScale3D, &NewScale3D);
	}


	static void Destroy(UObject* Target)
	{
		static auto K2_DestroyActor = FindObject(L"Function /Script/Engine.Actor.K2_DestroyActor");

		ProcessEvent(Target, K2_DestroyActor, nullptr);
	}

	static auto K2_SetActorRotation(UObject* Target, FRotator NewRotation)
	{
		static auto K2_SetActorRotation = FindObject(L"Function /Script/Engine.Actor.K2_SetActorRotation");

		struct
		{
			FRotator NewRotation;
			bool bTeleportPhysics;
			bool ret;
		} Params;

		Params.NewRotation = NewRotation;
		Params.bTeleportPhysics = false;

		ProcessEvent(Target, K2_SetActorRotation, &Params);

		return Params.ret;
	}
}

//TODO: Move to a class for multiplayer.
namespace Player
{
	static void Jump(UObject* Pawn)
	{
		static UObject* Jump = FindObject(L"Function /Script/Engine.Character.Jump");

		ProcessEvent(Pawn, Jump, nullptr);
	}

	static void AddMovementInput(UObject* botPawn, FVector Target)
	{
		static UObject* AddMovementInput = FindObject(L"Function /Script/Engine.Pawn.AddMovementInput");

		struct
		{
			FVector WorldDirection;
			float ScaleValue;
			bool bForc;
		} Params;

		Params.ScaleValue = 1;
		Params.bForc = true;
		Params.WorldDirection = Target;

		ProcessEvent(botPawn, AddMovementInput, &Params);
	}

	static bool CanJump(UObject* Pawn)
	{
		static UObject* Jump = FindObject(L"Function /Script/Engine.Character.CanJump");

		bool ReturnValue;

		ProcessEvent(Pawn, Jump, &ReturnValue);

		return ReturnValue;
	}

	static void SwitchLevel(UObject* InController, FString URL)
	{
		static UObject* SwitchLevel = FindObject(L"Function /Script/Engine.PlayerController.SwitchLevel");

		ProcessEvent(InController, SwitchLevel, &URL);
	}

	static void ServerReadyToStartMatch(UObject* InController)
	{
		static UObject* ServerReadyToStartMatch = FindObject(L"Function /Script/FortniteGame.FortPlayerController.ServerReadyToStartMatch");

		ProcessEvent(InController, ServerReadyToStartMatch, nullptr);
	}

	static void Possess(UObject* InController, UObject* InPawn)
	{
		static UObject* Possess = FindObject(L"Function /Script/Engine.Controller.Possess");

		ProcessEvent(InController, Possess, &InPawn);
	}

	static void SetControlRotation(UObject* InController, FRotator InRotator)
	{
		static UObject* SetControlRotation = FindObject(L"Function /Script/Engine.Controller.SetControlRotation");

		ProcessEvent(InController, SetControlRotation, &InRotator);
	}

	static FGuid GetItemGuid(UObject* FortItem)
	{
		static UObject* GetItemGuid = FindObject(L"Function /Script/FortniteGame.FortItem.GetItemGuid");
		FGuid ReturnValue;

		ProcessEvent(FortItem, GetItemGuid, &ReturnValue);
		return ReturnValue;
	}

	static void AddItemToQuickBars(UObject* ItemDefinition, EFortQuickBars Quickbar, int Slot)
	{
		static UObject* AddItemToQuickBars = FindObject(L"Function /Script/FortniteGame.FortPlayerController.AddItemToQuickBars");

		struct
		{
			UObject* ItemDefinition;
			EFortQuickBars Quickbar;
			int Slot;
		} Params;

		Params.ItemDefinition = ItemDefinition;
		Params.Quickbar = Quickbar;
		Params.Slot = Slot;


		ProcessEvent(Globals::Controller, AddItemToQuickBars, &Params);
	}

	static UObject* CreateTemporaryItemInstanceBP(UObject* ItemDefinition, int Count, int Level)
	{
		static UObject* CreateTemporaryItemInstanceBP = FindObject(L"Function /Script/FortniteGame.FortItemDefinition.CreateTemporaryItemInstanceBP");

		struct
		{
			int Count;
			int Level;
			UObject* ReturnValue;
		} Params;

		Params.Count = Count;
		Params.Level = Level;

		ProcessEvent(ItemDefinition, CreateTemporaryItemInstanceBP, &Params);

		return Params.ReturnValue;
	}

	static void SetOwningControllerForTemporaryItem(UObject* Item, UObject* Controller)
	{
		static UObject* SetOwningControllerForTemporaryItem = FindObject(L"Function /Script/FortniteGame.FortItem.SetOwningControllerForTemporaryItem");

		ProcessEvent(Item, SetOwningControllerForTemporaryItem, &Controller);
	}

	static void BP_ApplyGameplayEffectToSelf(UObject* AbilitySystemComponent, UObject* GameplayEffectClass)
	{
		static UObject* BP_ApplyGameplayEffectToSelf = FindObject(_(L"Function /Script/GameplayAbilities.AbilitySystemComponent.BP_ApplyGameplayEffectToSelf"));

		struct
		{
			UObject* GameplayEffectClass;
			float Level;
			FGameplayEffectContextHandle EffectContext;
			FActiveGameplayEffectHandle ret;
		} Params;

		Params.EffectContext = FGameplayEffectContextHandle();
		Params.GameplayEffectClass = GameplayEffectClass;
		Params.Level = 1.0;

		ProcessEvent(AbilitySystemComponent, BP_ApplyGameplayEffectToSelf, &Params);
	}

	static void GrantGameplayAbility(UObject* TargetPawn, UObject* GameplayAbilityClass)
	{
		UObject** AbilitySystemComponent = reinterpret_cast<UObject**>(__int64(TargetPawn) + static_cast<__int64>(Offsets::AbilitySystemComponentOffset));
		static UObject* DefaultGameplayEffect = FindObject(_(L"GE_Athena_PurpleStuff_C /Game/Athena/Items/Consumables/PurpleStuff/GE_Athena_PurpleStuff.Default__GE_Athena_PurpleStuff_C"));
		if (!DefaultGameplayEffect)
		{
			DefaultGameplayEffect = FindObject(_(L"GE_Athena_PurpleStuff_Health_C /Game/Athena/Items/Consumables/PurpleStuff/GE_Athena_PurpleStuff_Health.Default__GE_Athena_PurpleStuff_Health_C"));
		}

		TArray<struct FGameplayAbilitySpecDef>* GrantedAbilities = reinterpret_cast<TArray<struct FGameplayAbilitySpecDef>*>(__int64(DefaultGameplayEffect) + static_cast<__int64>(Offsets::GrantedAbilitiesOffset));

		// overwrite current gameplay ability with the one we want to activate
		GrantedAbilities->operator[](0).Ability = GameplayAbilityClass;

		// give this gameplay effect an infinite duration
		*reinterpret_cast<EGameplayEffectDurationType*>(__int64(DefaultGameplayEffect) + static_cast<__int64>(Offsets::DurationPolicyOffset)) = EGameplayEffectDurationType::Infinite;

		// apply modified gameplay effect to ability system component
		static auto GameplayEffectClass = FindObject(_(L"BlueprintGeneratedClass /Game/Athena/Items/Consumables/PurpleStuff/GE_Athena_PurpleStuff.GE_Athena_PurpleStuff_C"));
		if (!GameplayEffectClass)
		{
			GameplayEffectClass = FindObject(_(L"BlueprintGeneratedClass /Game/Athena/Items/Consumables/PurpleStuff/GE_Athena_PurpleStuff_Health.GE_Athena_PurpleStuff_Health_C"));
		}
		BP_ApplyGameplayEffectToSelf(*AbilitySystemComponent, GameplayEffectClass);
	}

	static void SetOwner(UObject* TargetActor, UObject* NewOwner)
	{
		static UObject* SetOwner = FindObject(L"Function /Script/Engine.Actor.SetOwner");

		ProcessEvent(TargetActor, SetOwner, &NewOwner);
	}

	static void ServerChoosePart(UObject* Target, TEnumAsByte<EFortCustomPartType> Type, UObject* ChosenCharacterPart)
	{
		static UObject* ServerChoosePart = FindObject(L"Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart");

		struct
		{
			TEnumAsByte<EFortCustomPartType> Type;
			UObject* ChosenCharacterPart;
		} Params;

		Params.Type = Type;
		Params.ChosenCharacterPart = ChosenCharacterPart;

		ProcessEvent(Target, ServerChoosePart, &Params);
	}

	static void SetSkeletalMesh(UObject* InPawn, UObject* NewMesh)
	{
		auto SkeletalMeshComp = *(UObject**)(__int64(InPawn) + Offsets::CharacterMeshOffset);

		static auto fn = FindObject(L"Function /Script/Engine.SkinnedMeshComponent.SetSkeletalMesh");

		struct
		{
			UObject* NewMesh;
			bool bReinitPos;
		} Params;

		Params.NewMesh = NewMesh;
		Params.bReinitPos = false;

		ProcessEvent(SkeletalMeshComp, fn, &Params);
	}

	static FGuid GetGuid(UObject* Target)
	{
		static UObject* GetItemGuid = FindObject(L"Function /Script/FortniteGame.FortItem.GetItemGuid");

		FGuid ReturnValue;

		ProcessEvent(Target, GetItemGuid, &ReturnValue);

		return ReturnValue;
	}

	static UObject* GetItemDefinition(UObject* Target)
	{
		static UObject* GetItemGuid = FindObject(L"Function /Script/FortniteGame.FortItem.GetItemDefinitionBP");

		UObject* ReturnValue;

		ProcessEvent(Target, GetItemGuid, &ReturnValue);

		return ReturnValue;
	}

	static void ClientInternalEquipWeapon(UObject* Pawn, UObject* FortWeapon)
	{
		static UObject* ClientInternalEquipWeapon = FindObject(L"Function /Script/FortniteGame.FortPawn.ClientInternalEquipWeapon");

		ProcessEvent(Pawn, ClientInternalEquipWeapon, &FortWeapon);
	}

	static void EquipWeaponByDefinition(UObject* Pawn, UObject* WeaponDefinition, FGuid ItemGuid)
	{
		TSoftObjectPtr<UObject*>* SoftWeaponActorClass = reinterpret_cast<TSoftObjectPtr<UObject*>*>(__int64(WeaponDefinition) + static_cast<__int64>(Offsets::WeaponActorClassOffset)); // TODO: change 0x708
		UObject* WeaponActorClass = Kismet::Conv_SoftClassReferenceToClass(*SoftWeaponActorClass);

		if (WeaponActorClass)
		{
			UObject* CurrentWeaponActor = SpawnActorEasy(GetWorld(), WeaponActorClass, {}, {});

			// set owner of weapon actor
			SetOwner(CurrentWeaponActor, Globals::Pawn);

			// set weapon definition and GUID
			*reinterpret_cast<UObject**>(__int64(CurrentWeaponActor) + static_cast<__int64>(Offsets::WeaponDataOffset)) = WeaponDefinition;
			*reinterpret_cast<FGuid*>(__int64(CurrentWeaponActor) + static_cast<__int64>(Offsets::ItemEntryGuidOffset)) = ItemGuid;

			// replicate weapon data and ammo, then give weapon to pawn
			Weapon::OnRep_ReplicatedWeaponData(CurrentWeaponActor);
			Weapon::ClientGivenTo(CurrentWeaponActor, Pawn);

			// equip weapon
			ClientInternalEquipWeapon(Pawn, CurrentWeaponActor);
		}
	}

	// deprecated, use EquipWeaponByDefinition
	static UObject* EquipWeaponDefinition(UObject* Target, UObject* ItemDefinition, FGuid ItemGuid)
	{
		static UObject* GetItemGuid = FindObject(L"Function /Script/FortniteGame.FortPawn.EquipWeaponDefinition");

		struct
		{
			UObject* ItemDefinition;
			FGuid ItemGuid;
			UObject* ReturnValue;
		} params;

		params.ItemDefinition = ItemDefinition;
		params.ItemGuid = ItemGuid;

		ProcessEvent(Target, GetItemGuid, &params);

		return params.ReturnValue;
	}

	static void EmptySlot(UObject* Target, int Slot)
	{
		static UObject* EmptySlot = FindObject(L"Function /Script/FortniteGame.FortQuickBars.EmptySlot");

		struct
		{
			EFortQuickBars QuickbarIndex;
			int Slot;
		} params;

		params.QuickbarIndex = EFortQuickBars::Primary;
		params.Slot = Slot;

		ProcessEvent(Target, EmptySlot, &params);
	}

	static void ServerSetClientHasFinishedLoading(UObject* Target)
	{
		static UObject* ServerSetClientHasFinishedLoading = FindObject(L"Function /Script/FortniteGame.FortPlayerController.ServerSetClientHasFinishedLoading");

		bool HasFinishedLoading = true;

		ProcessEvent(Target, ServerSetClientHasFinishedLoading, &HasFinishedLoading);
	}

	static void ShowBuildingFoundation(UObject* BuildingFoundation, EDynamicFoundationType DynamicFoundationType)
	{
		if (BuildingFoundation)
		{
			EDynamicFoundationType* CurrentFoundationType = reinterpret_cast<EDynamicFoundationType*>(__int64(BuildingFoundation) + static_cast<__int64>(Offsets::DynamicFoundationTypeOffset));

			*CurrentFoundationType = DynamicFoundationType;
		}
	}

	static void K2_TeleportTo(UObject* Actor, FVector DestLocation, FRotator DestRotation)
	{
		static UObject* K2_TeleportTo = FindObject(L"Function /Script/Engine.Actor.K2_TeleportTo");

		struct
		{
			FVector DestLocation;
			FRotator DestRotation;
		} Params;

		Params.DestLocation = DestLocation;
		Params.DestRotation = DestRotation;

		ProcessEvent(Actor, K2_TeleportTo, &Params);
	}

	UObject* GetVehicle()
	{
		static UObject* GetVehicle = FindObject(L"Function /Script/FortniteGame.FortPlayerPawn.GetVehicle");

		UObject* ReturnValue;

		ProcessEvent(Globals::Pawn, GetVehicle, &ReturnValue);
		

		return ReturnValue;
	}

	bool IsInVehicle()
	{
		static UObject* IsInVehicle = FindObject(L"Function /Script/FortniteGame.FortPlayerPawn.IsInVehicle");

		bool ReturnValue;

		ProcessEvent(Globals::Pawn, IsInVehicle, &ReturnValue);
		

		return ReturnValue;
	}

	static void OnRep_bAlreadySearched(UObject* Target)
	{
		static UObject* OnRep_bAlreadySearched = FindObject(L"Function /Script/FortniteGame.BuildingContainer.OnRep_bAlreadySearched");

		ProcessEvent(Target, OnRep_bAlreadySearched, nullptr);
	}

	static void ClientPlaySoundAtLocation(UObject* Target, UObject* SoundToPlay, FVector Location, float VolumeMultiplier, float PitchMultiplier)
	{
		static UObject* ClientPlaySoundAtLocation = FindObject(L"Function /Script/Engine.PlayerController.ClientPlaySoundAtLocation");

		struct
		{
			UObject* soundToPlay;
			FVector Location;
			float VolumeMultiplier;
			float PitchMultiplier;
		} params;

		params.soundToPlay = SoundToPlay;
		params.Location = Location;
		params.VolumeMultiplier = VolumeMultiplier;
		params.PitchMultiplier = PitchMultiplier;

		ProcessEvent(Target, ClientPlaySoundAtLocation, &params);
	}

	static auto SetHealth(UObject* inPawn, float SetHealthInput)
	{
		static auto fn = FindObject(L"Function /Script/FortniteGame.FortPawn.SetHealth");

		ProcessEvent(inPawn, fn, &SetHealthInput);
	}

	static auto SetShield(UObject* inPawn, float SetShieldInput)
	{
		static auto fn = FindObject(L"Function /Script/FortniteGame.FortPawn.SetShield");

		ProcessEvent(inPawn, fn, &SetShieldInput);
	}

	static auto SetMaxHealth(UObject* inPawn, float SetMaxHealthInput)
	{
		static auto fn = FindObject(L"Function /Script/FortniteGame.FortPawn.SetMaxHealth");

		ProcessEvent(inPawn, fn, &SetMaxHealthInput);
	}

	static auto SetMaxShield(UObject* inPawn, float SetMaxShieldInput)
	{
		static auto fn = FindObject(L"Function /Script/FortniteGame.FortPawn.SetMaxShield");

		ProcessEvent(inPawn, fn, &SetMaxShieldInput);
	}
}

namespace PlayerState
{
	static void OnRep_SquadId()
	{
		static UObject* OnRep_SquadID = FindObject(L"Function /Script/FortniteGame.FortPlayerStateAthena.OnRep_SquadId");

		Globals::PlayerState = *reinterpret_cast<UObject**>(reinterpret_cast<uintptr_t>(Globals::Controller) + Offsets::PlayerStateOffset);
		ProcessEvent(Globals::PlayerState, OnRep_SquadID, nullptr);
	};
}

namespace Pickup
{
	static void TossPickup(UObject* FortPickup, FVector FinalLocation, UObject* ItemOwner, int OverrideMaxStackCount, bool bToss)
	{
		static UObject* TossPickup = FindObject(L"Function /Script/FortniteGame.FortPickup.TossPickup");

		struct
		{
			FVector FinalLocation;
			UObject* ItemOwner;
			int OverrideMaxStackCount;
			bool bToss;
		} Params;

		Params.FinalLocation = FinalLocation;
		Params.ItemOwner = ItemOwner;
		Params.OverrideMaxStackCount = OverrideMaxStackCount;
		Params.bToss = bToss;

		ProcessEvent(FortPickup, TossPickup, &Params);
	}

	static void OnRep_PrimaryPickupItemEntry(UObject* FortPickup)
	{
		static UObject* OnRep_PrimaryPickupItemEntry = FindObject(L"Function /Script/FortniteGame.FortPickup.OnRep_PrimaryPickupItemEntry");

		ProcessEvent(FortPickup, OnRep_PrimaryPickupItemEntry, nullptr);
	}

	static void SpawnPickupAtLocation(UObject* ItemDefinition, int Count, FVector Location)
	{
		auto FortPickupAthena = SpawnActorEasy(GetWorld(), FindObject(L"Class /Script/FortniteGame.FortPickupAthena"), Location, {});

		auto EntryCount = reinterpret_cast<int*>(__int64(FortPickupAthena) + static_cast<__int64>(Offsets::PrimaryPickupItemEntryOffset) + static_cast<__int64>(Offsets::CountOffset));
		auto EntryItemDefinition = reinterpret_cast<UObject**>(__int64(FortPickupAthena) + static_cast<__int64>(Offsets::PrimaryPickupItemEntryOffset) + static_cast<__int64>(Offsets::ItemDefinitionOffset));

		*EntryCount = Count;
		*EntryItemDefinition = ItemDefinition;

		OnRep_PrimaryPickupItemEntry(FortPickupAthena);
		TossPickup(FortPickupAthena, Location, Globals::Pawn, 6, true);
	}
}

namespace Controller
{
	static auto GetPawn(UObject* Controller)
	{
		static UObject* K2_GetPawn = FindObject(L"Function /Script/Engine.Controller.K2_GetPawn");

		struct Params
		{
			UObject* ret;
		};

		Params params;

		ProcessEvent(Controller, K2_GetPawn, &params);

		return params.ret;
	}

	static auto GetControlRotation(UObject* Target)
	{
		static UObject* GetControlRotation = FindObject(L"Function /Script/Engine.Controller.GetControlRotation");

		FRotator ReturnValue;

		ProcessEvent(Target, GetControlRotation, &ReturnValue);

		return ReturnValue;
	}
}

namespace GameState
{
	static UObject* GetAircraft(UObject* InGameState)
	{
		static UObject* GetAircraft = FindObject(L"Function /Script/FortniteGame.FortGameStateAthena.GetAircraft");

		struct Params
		{
			int i;
			UObject* bus;
		};

		Params params;

		params.i = 1;

		ProcessEvent(InGameState, GetAircraft, &params);
		return params.bus;
	}

	static void OnRep_GamePhase(UObject* InGameState, EAthenaGamePhase OldGamePhase)
	{
		static UObject* OnRep_GamePhase = FindObject(L"Function /Script/FortniteGame.FortGameStateAthena.OnRep_GamePhase");

		ProcessEvent(InGameState, OnRep_GamePhase, &OldGamePhase);
	}

	static void OnRep_CurrentPlaylistData(UObject* InGameState)
	{
		static UObject* OnRep_CurrentPlaylistData = FindObject(L"Function /Script/FortniteGame.FortGameStateAthena.OnRep_CurrentPlaylistData");

		ProcessEvent(InGameState, OnRep_CurrentPlaylistData, nullptr);
	}
}

namespace CheatManager
{
	static void Summon(UObject* InCheatManager, FString InClassName)
	{
		static UObject* Summon = FindObject(L"Function /Script/Engine.CheatManager.Summon");

		ProcessEvent(InCheatManager, Summon, &InClassName);
	}
}

namespace TextActor
{
	static UObject* Spawn(FVector Location = {}, FRotator Rotation = {})
	{
		static auto c = FindObject(L"Class /Script/Engine.TextRenderActor");

		auto TextRenderComponent = *(UObject**)(reinterpret_cast<__int64>(SpawnActorEasy(GetWorld(), c, Location, Rotation)) + Offsets::TextRenderOffset /* UTextRenderComponent */);

		return TextRenderComponent;
	}

	static void SetText(UObject* Target, FString Text)
	{
		const auto SetText = FindObject(L"Function /Script/Engine.TextRenderComponent.SetText");

		ProcessEvent(Target, SetText, &Text);
	}

	static void SetWorldSize(UObject* Target, float value)
	{
		static auto SetWorldSize = FindObject(L"Function /Script/Engine.TextRenderComponent.SetWorldSize");

		ProcessEvent(Target, SetWorldSize, &value);
	}

	static void SetXScale(UObject* Target, float value)
	{
		static auto SetXScale = FindObject(L"Function /Script/Engine.TextRenderComponent.SetXScale");

		ProcessEvent(Target, SetXScale, &value);
	}

	static void SetYScale(UObject* Target, float value)
	{
		static auto SetYScale = FindObject(L"Function /Script/Engine.TextRenderComponent.SetYScale");

		ProcessEvent(Target, SetYScale, &value);
	}
}

namespace GameplayStatics
{
	static TArray<UObject*> GetAllActorsOfClass(UObject* Class)
	{
		static UObject* Default__GameplayStatics = FindObject(L"GameplayStatics /Script/Engine.Default__GameplayStatics");
		static UObject* GetAllActorsOfClass = FindObject(L"Function /Script/Engine.GameplayStatics.GetAllActorsOfClass");

		struct
		{
			UObject* World;
			UObject* Class;
			TArray<UObject*> ReturnValue;
		} Params;

		Params.World = GetWorld();
		Params.Class = Class;

		ProcessEvent(Default__GameplayStatics, GetAllActorsOfClass, &Params);

		return Params.ReturnValue;
	}
}

namespace Widget
{
	static void RemoveFromViewport(UObject* Target)
	{
		static UObject* RemoveFromViewport = FindObject(L"Function /Script/UMG.UserWidget.RemoveFromViewport");

		ProcessEvent(Target, RemoveFromViewport, nullptr);
	}
}

namespace Render
{
	static void MapWithActor(UObject* actorClass, std::string map, float actorWidth, float actorHeight, int lineLength, FVector loc, FRotator rot)
	{
		auto location = loc;

		for (std::string::size_type i = 0; i < map.size(); ++i)
		{
			location.X -= actorHeight;

			if (i % lineLength == 0)
			{
				location.Z -= actorWidth;
				location.X = loc.X;
			}

			if (map[i] == '#')
			{
				SpawnActorEasy(GetWorld(), actorClass, location, rot);
			}

			//printf("CurrentX: %f, CurrentZ: %f\n", location.X, location.Z);
		}

		location = {};
	}
}

namespace Inventory
{
	static UObject* CreateItem(UObject* ItemDefinition, int Count)
	{
		UObject* TemporaryItemInstance = Player::CreateTemporaryItemInstanceBP(ItemDefinition, Count, 1);

		if (TemporaryItemInstance)
		{
			Player::SetOwningControllerForTemporaryItem(TemporaryItemInstance, Globals::Controller);
		}

		int* CurrentCount = reinterpret_cast<int*>(__int64(TemporaryItemInstance) + static_cast<__int64>(Offsets::ItemEntryOffset) + static_cast<__int64>(0xC));
		*CurrentCount = Count;

		return TemporaryItemInstance;
	}

	static void UpdateInventory()
	{
		static auto HandleWorldInventoryLocalUpdate = FindObject(L"Function /Script/FortniteGame.FortPlayerController.HandleWorldInventoryLocalUpdate");
		static auto HandleInventoryLocalUpdate = FindObject(L"Function /Script/FortniteGame.FortInventory.HandleInventoryLocalUpdate");
		static auto OnRep_QuickBar = FindObject(L"Function /Script/FortniteGame.FortPlayerController.OnRep_QuickBar");
		static auto ClientForceUpdateQuickbar = FindObject(L"Function /Script/FortniteGame.FortPlayerController.ClientForceUpdateQuickbar");
		static auto OnRep_SecondaryQuickBar = FindObject(L"Function /Script/FortniteGame.FortQuickBars.OnRep_SecondaryQuickBar");
		static auto OnRep_PrimaryQuickBar = FindObject(L"Function /Script/FortniteGame.FortQuickBars.OnRep_PrimaryQuickBar");

		ProcessEvent(Globals::FortInventory, HandleInventoryLocalUpdate, nullptr);
		ProcessEvent(Globals::Controller, HandleWorldInventoryLocalUpdate, nullptr);
		if (OnRep_QuickBar)
		{
			ProcessEvent(Globals::Controller, OnRep_QuickBar, nullptr);
			ProcessEvent(Globals::Quickbar, OnRep_SecondaryQuickBar, nullptr);
			ProcessEvent(Globals::Quickbar, OnRep_PrimaryQuickBar, nullptr);
		}
		else
		{
			auto PrimaryQuickbar = EFortQuickBars::Primary;
			auto SecondaryQuickbar = EFortQuickBars::Secondary;
			ProcessEvent(Globals::Controller, ClientForceUpdateQuickbar, &PrimaryQuickbar);
			ProcessEvent(Globals::Controller, ClientForceUpdateQuickbar, &SecondaryQuickbar);
		}
	}

	static int test()
	{
	}

	static void ServerAddItemInternal(UObject* Quickbars, FGuid Item, EFortQuickBars Quickbar, int Slot)
	{
		static UObject* ServerAddItemInternal = FindObject(L"Function /Script/FortniteGame.FortQuickBars.ServerAddItemInternal");

		struct
		{
			FGuid Item;
			EFortQuickBars Quickbar;
			int Slot;
		} Params;

		Params.Item = Item;
		Params.Quickbar = Quickbar;
		Params.Slot = Slot;

		ProcessEvent(Quickbars, ServerAddItemInternal, &Params);
	}


	static void AddItemToInventory(UObject* FortItem, EFortQuickBars QuickbarIndex, int Slot)
	{
		FString CurrentVersion = RuntimeOptions::GetGameVersion();

		if (strstr(RuntimeOptions::GetFortniteVersion().c_str(), "3."))
		{
			struct ItemEntrySize
			{
				unsigned char Unk00[0xC0];
			};
			auto ItemEntry = reinterpret_cast<ItemEntrySize*>(reinterpret_cast<uintptr_t>(FortItem) + Offsets::ItemEntryOffset);
			reinterpret_cast<TArray<ItemEntrySize>*>(__int64(Globals::FortInventory) + static_cast<__int64>(Offsets::InventoryOffset) + static_cast<__int64>(Offsets::ItemEntriesOffset))->Add(*ItemEntry);
		}
		else if (strstr(RuntimeOptions::GetFortniteVersion().c_str(), "4.") || strstr(RuntimeOptions::GetFortniteVersion().c_str(), "5.") || strstr(RuntimeOptions::GetFortniteVersion().c_str(), "6."))
		{
			struct ItemEntrySize
			{
				unsigned char Unk00[0xD0];
			};
			auto ItemEntry = reinterpret_cast<ItemEntrySize*>(reinterpret_cast<uintptr_t>(FortItem) + Offsets::ItemEntryOffset);
			reinterpret_cast<TArray<ItemEntrySize>*>(__int64(Globals::FortInventory) + static_cast<__int64>(Offsets::InventoryOffset) + static_cast<__int64>(Offsets::ItemEntriesOffset))->Add(*ItemEntry);
		}
		else if (strstr(RuntimeOptions::GetFortniteVersion().c_str(), "7.") || strstr(RuntimeOptions::GetFortniteVersion().c_str(), "8."))
		{
			struct ItemEntrySize
			{
				unsigned char Unk00[0x120];
			};
			auto ItemEntry = reinterpret_cast<ItemEntrySize*>(reinterpret_cast<uintptr_t>(FortItem) + Offsets::ItemEntryOffset);
			reinterpret_cast<TArray<ItemEntrySize>*>(__int64(Globals::FortInventory) + static_cast<__int64>(Offsets::InventoryOffset) + static_cast<__int64>(Offsets::ItemEntriesOffset))->Add(*ItemEntry);
		}

		reinterpret_cast<TArray<UObject*>*>(__int64(Globals::FortInventory) + static_cast<__int64>(Offsets::InventoryOffset) + static_cast<__int64>(Offsets::ItemInstancesOffset))->Add(FortItem);

		if (7.4 > std::stof(RuntimeOptions::GetFortniteVersion()))
		{
			ServerAddItemInternal(Globals::Quickbar, Player::GetGuid(FortItem), QuickbarIndex, Slot);
		}
		
	}

	static void AddItemToInventoryWithUpdate(UObject* ItemDef, EFortQuickBars QuickbarIndex, int Slot, int Count)
	{
		if (ItemDef)
		{
			UObject* ItemInstance = CreateItem(ItemDef, Count);

			if (ItemInstance)
			{
				AddItemToInventory(ItemInstance, QuickbarIndex, Slot);
			}

			UpdateInventory();
		}
	}
}
