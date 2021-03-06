/*
 * CG Madness - a Marble Madness clone
 * Copyright (C) 2007  Sven Reinck <sreinck@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "mouse.hpp"

#include "callback.hpp"

#include GLUT_H

static int gLastX;
static int gLastY;

static funcDrag gDrag;

void mouseMotion(int x, int y)
{
	if (x != gLastX || y != gLastY)
	{
		if (gDrag)
		{
			gDrag(x - gLastX, y - gLastY);
			//glutWarpPointer(gLastX, gLastY);
		}
	}
}

void setDragFunc(funcDrag drag)
{
	gDrag = drag;
	if (gDrag)
	{
		centerMouse(&gLastX, &gLastY);
	}
}

void startMouse()
{
	//glutPassiveMotionFunc(mouseMotion);
}
