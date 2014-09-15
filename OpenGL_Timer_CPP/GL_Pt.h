//
//  GL_Pt.h
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#ifndef __OpenGL_Timer_CPP__GL_Pt__
#define __OpenGL_Timer_CPP__GL_Pt__

#include <iostream>

struct pt {
	double a, b;
};

typedef pt s_GL_Pt;

class GL_Pt {
	double x_axis, y_axis;
	double width, height;
	
public:
	GL_Pt();
	GL_Pt(const double x, const double y, const double w, const double h);
	GL_Pt(const double*);
	s_GL_Pt size();
	s_GL_Pt origin();
};

#endif /* defined(__OpenGL_Timer_CPP__GL_Pt__) */
