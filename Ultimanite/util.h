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

#define RELATIVE_ADDRESS(address, size) ((PBYTE)((UINT_PTR)(address) + *(PINT)((UINT_PTR)(address) + ((size) - sizeof(INT))) + (size)))

namespace Util
{
	static __forceinline void SetupConsole()
	{
		AllocConsole();

		FILE* pFile;
		freopen_s(&pFile, "CONOUT$", "w", stdout);
	}

	static __forceinline bool IsBadReadPtr(void* p)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (VirtualQuery(p, &mbi, sizeof(mbi)))
		{
			DWORD mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
			bool b = !(mbi.Protect & mask);
			if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) b = true;

			return b;
		}
		return true;
	}

	static __forceinline std::string readAllText(const std::string& path)
	{
		std::ifstream input_file(path);
		if (!input_file.is_open()) return std::string();

		return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
	}

	static __forceinline std::string GetRuntimePath()
	{
		char result[MAX_PATH];
		std::string path(result, GetModuleFileNameA(nullptr, result, MAX_PATH));
		size_t pos = path.find_last_of("\\/");
		return (std::string::npos == pos) ? "" : path.substr(0, pos);
	}

	static __forceinline uintptr_t FindPattern(const char* signature, bool bRelative = false, uint32_t offset = 0)
	{
		uintptr_t base_address = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
		static auto patternToByte = [](const char* pattern)
		{
			auto bytes = std::vector<int>{};
			const auto start = const_cast<char*>(pattern);
			const auto end = const_cast<char*>(pattern) + strlen(pattern);

			for (auto current = start; current < end; ++current)
			{
				if (*current == '?')
				{
					++current;
					if (*current == '?') ++current;
					bytes.push_back(-1);
				}
				else { bytes.push_back(strtoul(current, &current, 16)); }
			}
			return bytes;
		};

		const auto dosHeader = (PIMAGE_DOS_HEADER)base_address;
		const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)base_address + dosHeader->e_lfanew);

		const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
		auto patternBytes = patternToByte(signature);
		const auto scanBytes = reinterpret_cast<std::uint8_t*>(base_address);

		const auto s = patternBytes.size();
		const auto d = patternBytes.data();

		for (auto i = 0ul; i < sizeOfImage - s; ++i)
		{
			bool found = true;
			for (auto j = 0ul; j < s; ++j)
			{
				if (scanBytes[i + j] != d[j] && d[j] != -1)
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				uintptr_t address = reinterpret_cast<uintptr_t>(&scanBytes[i]);
				if (bRelative)
				{
					address = ((address + offset + 4) + *(int32_t*)(address + offset));
					return address;
				}
				return address;
			}
		}
		return NULL;
	}
}
