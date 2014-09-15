//
//  GlutObject.h
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#ifndef __OpenGL_Timer_CPP__GlutObject__
#define __OpenGL_Timer_CPP__GlutObject__

#include <iostream>
#include "GL_Pt.h"
#include <GLUT/GLUT.h>

class glutObject {
	
public:
	void Init(int argc, char **argv);
	void InitDisplayMode(int FrameMode, int ColorMode);
	void InitWindow(GL_Pt Rectangle);
	void CreateWindow(const char *name);
	void ClearWindow();
	void SetProjection();
	void SetOrtho(const float left, const float right, const float buttom,
				  const float top, const float zNear, const float zFar);
	void Misc(void (*func)());
	void displayFunc(void (*func)());
	void idleFunc(void (*func)());
	void flush();

};

#endif /* defined(__OpenGL_Timer_CPP__GlutObject__) */
