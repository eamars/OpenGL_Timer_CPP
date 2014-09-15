//
//  GlutObject.cpp
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#include "GlutObject.h"

void glutObject::Init(int argc, char **argv){
	glutInit(&argc, argv);
}

void glutObject::InitDisplayMode(int FrameMode, int ColorMode){
	glutInitDisplayMode(FrameMode | ColorMode);
}

void glutObject::InitWindow(GL_Pt Rectangle){
	glutInitWindowSize(Rectangle.size().a, Rectangle.size().b);
	glutInitWindowPosition(Rectangle.origin().a, Rectangle.origin().b);
}

void glutObject::CreateWindow(const char *name){
	glutCreateWindow(name);
}

void glutObject::ClearWindow(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
}

void glutObject::SetProjection(){
	glMatrixMode(GL_PROJECTION);
}

void glutObject::SetOrtho(const float left, const float right, const float buttom,
						  const float top, const float zNear, const float zFar){
	glOrtho(left, right, buttom, top, zNear, zFar);
}

void glutObject::Misc(void (*func)()){
	(*func)();
}

void glutObject::displayFunc(void (*func)()){
	glutDisplayFunc(func);
}

void glutObject::idleFunc(void (*func)()){
	glutIdleFunc(func);
}

void glutObject:: flush(){
	glutMainLoop();
}
