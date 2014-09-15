//
//  main.cpp
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#include <iostream>
#include "Clock.h"
#include "GL_Pt.h"
#include "GlutObject.h"

int main(int argc, char ** argv)
{
	glutObject timer;
	GL_Pt WindowRect(500, 500, 100, 0);
	timer.Init(argc, argv);
	timer.InitDisplayMode(GLUT_DOUBLE, GLUT_RGB);
	timer.InitWindow(WindowRect);
	timer.CreateWindow("Clock");
	timer.ClearWindow();
	timer.SetProjection();
	timer.SetOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
	timer.displayFunc(timer1);
	timer.idleFunc(timecheck);
	timer.flush();
	
    return 0;
}

