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


#include "hw/features.hpp"
#include "Main.hpp"


#include "callback.hpp"

#include "process/MainProcess.hpp"

#include "level/level.hpp"

#include "hw/keyboard.hpp"
#include "hw/mouse.hpp"


#include "utils/Singleton.hpp"

#include "tools.hpp"

#include GLUT_H

#include <stdio.h>
#include <stdlib.h>

void usage(void)
{
	printf("usage: cgmadness [options...]\n");
	usageFeatures();
}

int main(int argc, char *argv[])
{
	message();
	usage();

	assurePath(argv[0]);

	/*
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);

	glutInitWindowSize(700, 500);
	glutInitWindowPosition(0, 0);

	glutInit(&argc, argv);

	if (!glutCreateWindow("CG Madness"))
	{
		printf("Could not create window :(\n");
		return 1;
	}

	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);


	initFeatures(argc, argv);


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearStencil(0);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	{
		float ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glEnable(GL_LIGHT0);
	}

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	*/

	/* ---- */

	startKeyboard();
	startMouse();

	Main::init();

	Singleton<Main> main;
	Singleton<MainProcess> process;
	main->setFirstProcess(process);

	startCallback(main);

	//glutMainLoop();

	return 0;
}
