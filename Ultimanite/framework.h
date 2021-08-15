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

#define JM_XORSTR_DISABLE_AVX_INTRINSICS //OLD CPU SUPPORT

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "httplib.h"
#include <Windows.h>
#include <vector>
#include <Detours.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <fstream>

#include "source/duktape.h"
#include "xorstr.hpp"
#define _(str) xorstr_(str)

//always the last
#include "enums.h"
#include "util.h"
#include "structs.h"
#include "ue4.h"
#include "sdk.h"
#include "script.h"