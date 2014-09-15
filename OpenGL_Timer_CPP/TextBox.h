//
//  TextBox.h
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#ifndef __OpenGL_Timer_CPP__TextBox__
#define __OpenGL_Timer_CPP__TextBox__

#include <iostream>
#include <GLUT/GLUT.h>
#include "GLColor.h"

class TextBox {
	void *font;
	char *data;
	size_t len;
	float x_axis, y_axis;
	float color[3];
	
public:
	TextBox();
	TextBox(float x, float y, const char *p,
			const float *fontColor = GLColor::GL_WHITE_COLOR,
			void *f = GLUT_BITMAP_HELVETICA_18);
	TextBox(float x, float y, const std::string &ref,
			const float *fontColor = GLColor::GL_WHITE_COLOR,
			void *f = GLUT_BITMAP_HELVETICA_18);
	~TextBox();
	void diag_info();
	void draw();
};

#endif /* defined(__OpenGL_Timer_CPP__TextBox__) */
