//
//  Clock.h
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#ifndef __OpenGL_Timer_CPP__Clock__
#define __OpenGL_Timer_CPP__Clock__

#include <iostream>

#ifdef __WIN32__
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "TextBox.h"
#include <ctime>

void printFPS(float x, float y);
void timer1();
void timecheck();

#endif /* defined(__OpenGL_Timer_CPP__Clock__) */
