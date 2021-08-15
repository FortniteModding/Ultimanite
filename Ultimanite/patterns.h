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

// From 2.5-CL-3889387 to 4.5-CL-4166199.
#define UE_4_20_GOBJECTS _("48 8B 05 ? ? ? ? 48 8D 1C C8 81 4B ? ? ? ? ? 49 63 76 30")
#define UE_4_20_FNAME_TOSTRING _("48 89 5C 24 ? 57 48 83 EC 40 83 79 04 00 48 8B DA 48 8B F9")
#define UE_4_20_GETFIRSTPLAYERCONTROLLER _("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9")
#define UE_4_20_SPAWNACTORFROMCLASS _("40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB")
#define UE_4_20_CONSTRUCTOBJECT _("4C 89 44 24 ? 53 55 56 57 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ?")
#define UE_4_20_LOADOBJECT _("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 33 D2")
#define UE_4_20_GETROW _("48 89 5C 24 ? 48 89 74 24 ? 48 89 54 24 ? 57 48 83 EC 60 48 83 79 ? ? 41 0F B6 F9 49 8B F0 48 8B D9 75 6C 80 3D ? ? ? ? ? 0F 82 ? ? ? ? 45 33 C0 48 8D 54 24 ? E8 ? ? ? ? 83 78 08 00 74 05 48 8B 18 EB 07")
#define UE_4_20_FREE _("48 85 C9 74 1D 4C 8B 05 ? ? ? ? 4D 85 C0")

// From Season 5 to Season 6.
#define UE_4_21_GOBJECTS _("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB 03 48 8B ? 81 48 08 ? ? ? 40 49")
#define UE_4_21_FNAME_TOSTRING _("48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9")
#define UE_4_21_GETFIRSTPLAYERCONTROLLER _("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9")
#define UE_4_21_SPAWNACTORFROMCLASS _("40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB")
#define UE_4_21_CONSTRUCTOBJECT _("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B A5 ? ? ? ? 48 8D 05 ? ? ? ?")
#define UE_4_21_LOADOBJECT _("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 78 45 33 F6")
#define UE_4_21_FREE _("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9")

// Season 7 (Tested 7.3 and 7.4)
#define UE_4_22_GOBJECTS _("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB 03 48 8B ? 81 48 08 ? ? ? 40 49")
#define UE_4_22_FNAME_TOSTRING _("48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9")
#define UE_4_22_GETFIRSTPLAYERCONTROLLER _("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9")
#define UE_4_22_SPAWNACTORFROMCLASS _("40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB")
#define UE_4_22_CONSTRUCTOBJECT _("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B A5 ? ? ? ? 48 8D 05 ? ? ? ?")
#define UE_4_22_LOADOBJECT _("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 78 45 33 F6")
#define UE_4_22_FREE _("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9")

// 8.51 
#define UE_4_23_GOBJECTS _("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB 03 48 8B ? 81 48 08 ? ? ? 40 49")
#define UE_4_23_FNAME_TOSTRING _("48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9")
#define UE_4_23_GETFIRSTPLAYERCONTROLLER _("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9")
#define UE_4_23_SPAWNACTORFROMCLASS _("40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB")
#define UE_4_23_CONSTRUCTOBJECT _("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B A5 ? ? ? ? 48 8D 05 ? ? ? ?")
#define UE_4_23_LOADOBJECT _("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 78 45 33 F6")
#define UE_4_23_FREE _("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9")