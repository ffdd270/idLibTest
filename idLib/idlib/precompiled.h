/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __PRECOMPILED_H__
#define __PRECOMPILED_H__

#ifndef WINVER
#define WINVER 0x0500
#define _WIN32_WINNT 0x0500
#endif

#include "sys/sys_defines.h"
#include "sys/sys_builddefines.h"
#include "sys/sys_includes.h"
#include "sys/sys_assert.h"
#include "sys/sys_types.h"
#include "sys/sys_intrinsics.h"
#include "sys/sys_threading.h"


#include "../idlib/Lib.h"
//-----------------------------------------------------

#define ID_TIME_T int64 // Signed because -1 means "File not found" and we don't want that to compare > than any other time

// non-portable system services



// We have expression parsing and evaluation code in multiple places:
// materials, sound shaders, and guis. We should unify them.
const int MAX_EXPRESSION_OPS = 4096;
const int MAX_EXPRESSION_REGISTERS = 4096;


//-----------------------------------------------------

#ifndef _D3SDK

#ifdef GAME_DLL

#include "../d3xp/Game_local.h"

#else



#endif /* !GAME_DLL */

#endif /* !_D3SDK */

//-----------------------------------------------------

#undef min
#undef max
#include <algorithm>	// for min / max / swap

#endif /* !__PRECOMPILED_H__ */
