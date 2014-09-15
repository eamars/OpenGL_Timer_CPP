//
//  Clock.cpp
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#include "Clock.h"
#include "GLColor.h"
#include <cmath>

const static int N = 80;

double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;
    
    ++count;
    if( count <= 50 )
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current-last)/(double)CLOCKS_PER_SEC;
    save = 50.0/timegap;
    return save;
}

void printFPS(float x, float y){
	double fpsValue = CalFrequency();
	std::string fpsString = "FPS: " + std::to_string(fpsValue);
	
	
	TextBox fpsObject(x, y, fpsString, GLColor::GL_WHITE_COLOR, GLUT_BITMAP_HELVETICA_12);
	fpsObject.draw();
	
	
}

void display_date(float x,float y,float fs)
{
    
    time_t timer;
    struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);//get current time:sec,min,hour
	
	
	std::string timezoneString = tblock->tm_zone;
	std::string yearString = std::to_string(tblock->tm_year + 1900);
	std::string monthString = std::to_string(tblock->tm_mon);
	std::string dayString = std::to_string(tblock->tm_mday);
	
	std::string hourString = std::to_string(tblock->tm_hour);
	std::string ampmString = "a.m";
	if (tblock->tm_hour > 12) {
		hourString = std::to_string(tblock->tm_hour - 12);
		ampmString = "p.m";
	}
	std::string minString = std::to_string(tblock->tm_min);
	
	
	std::string toDisplay =timezoneString + ": " + yearString + "-" + monthString + "-" + dayString + "," + hourString + ":" + minString + " " + ampmString;
	
	TextBox date_msg(x, y, toDisplay,  GLColor::GL_WHITE_COLOR, GLUT_BITMAP_HELVETICA_18);
	date_msg.draw();
}




void clock1(float xf,float yf,float radius)
{
    float x[N],y[N];
    
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
	
    
    glColor3fv(GLColor::GL_WHITE_COLOR);
    glLineWidth(10);
		//clock panel outer layor
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < N; i++) {
		x[i] = radius * cos(2 * M_PI / N) + xf;
		y[i] = radius * sin(2 * M_PI / N) + yf;
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    glFlush();
    
	
		//unit
    glLineWidth(2.5);
    glBegin(GL_LINES);
    for (int i=0; i<60; i++) {
        glVertex2f((radius - 0.15) * sin(i * 6 * (M_PI / 180)), (radius - 0.15) * cos(i * 6 * (M_PI/180)));
        glVertex2f(radius * sin(i * 6 * (M_PI / 180)), radius * cos(i * 6 * (M_PI / 180)));
    }
	
	
	

		//arrays
    time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);//get current time:sec,min,hour
    
	
		//array_sec
    float sec_d = tblock -> tm_sec;//sec in degree
    float sec_r = sec_d * 6 * (M_PI / 180);//sec in radius
    glLineWidth(1);
    glColor3fv(GLColor::GL_RED_COLOR);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius / 1.05 * sin(sec_r), radius / 1.05 * cos(sec_r));
    glEnd();
    glFlush();
    
		//array_min
    float min_d = tblock -> tm_min + sec_d / 60;
    float min_r = min_d * 6 * (M_PI / 180);
    
    glColor3fv(GLColor::GL_YELLOW_COLOR);
	glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius / 1.5 * sin(min_r), radius / 1.5 * cos(min_r));
    glEnd();
    glFlush();
	
		//array_hour
    float hour_d = tblock -> tm_hour + min_d / 60;
    float hour_r = hour_d * 30 * (M_PI / 180);
    
    glColor3fv(GLColor::GL_GREEN_COLOR);
	glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius / 3 * sin(hour_r), radius / 3 * cos(hour_r));
    glEnd();
    glFlush();
    
    
    
		//inner layor
    glColor3fv(GLColor::GL_WHITE_COLOR);
    glBegin(GL_POLYGON);
    for (int i=0; i<N; i++) {
        x[i]=radius / 15 * cos(2 * i * M_PI / N)+xf;
        y[i]=radius / 15 * sin(2 * i * M_PI / N)+yf;
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    glFlush();
    
    
		// display number
	for (int i = 0;  i < 12; i++) {
		if (i == 0){
			TextBox numberToDisplay(radius / 1.1 * sin(i * 30 * (M_PI / 180)) - 0.1, radius / 1.1 * cos(i * 30 * (M_PI / 180)) - 0.13, std::to_string(12), GLColor::GL_WHITE_COLOR, GLUT_BITMAP_HELVETICA_18);
			numberToDisplay.draw();
		}
		else{
			TextBox numberToDisplay(radius / 1.1 * sin(i * 30 * (M_PI / 180)) - 0.1, radius / 1.1 * cos(i * 30 * (M_PI / 180)) - 0.13, std::to_string(i), GLColor::GL_WHITE_COLOR, GLUT_BITMAP_HELVETICA_18);
			numberToDisplay.draw();
		}
		
		
	}
    
    display_date(-2.3, -4.5, 1);
    printFPS(-5, 4.8);
	
}


void timer1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    clock1(0, 0, 4);
	
    glutSwapBuffers();
}

void timecheck()
{
    
    time_t timer;
    struct tm *tblock;
    
    
    int current_sec = 0,last_sec;
    
    
    timer = time(NULL);
    tblock = localtime(&timer);
    
    last_sec = current_sec;
    current_sec = tblock->tm_sec;
    
    if (last_sec != current_sec) {
        timer1();
#ifdef __WIN32__
        Sleep(998);
#else
		sleep(1.0);//give cpu a delay time
#endif
    }
}



