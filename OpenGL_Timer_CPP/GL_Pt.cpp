//
//  GL_Pt.cpp
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#include "GL_Pt.h"

GL_Pt::GL_Pt(){
	x_axis = y_axis = width = height = 0;
}

GL_Pt::GL_Pt(const double x, const double y, const double w, const double h){
	x_axis = x;
	y_axis = y;
	width = w;
	height = h;
}

s_GL_Pt GL_Pt::size(){
	s_GL_Pt size_r;
	size_r.a = x_axis;
	size_r.b = y_axis;
	
	return size_r;
}

s_GL_Pt GL_Pt::origin(){
	s_GL_Pt size_r;
	size_r.a = width;
	size_r.b = height;
	
	return size_r;
}