
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "MyVehicle.h"
#include "Rectangle.h"
#include "Cylinder.h"


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


MyVehicle::MyVehicle() {
	scale = 1;
}

MyVehicle::MyVehicle(double Scale) {
	scale = Scale;
}

void MyVehicle::draw() {

	glPushMatrix();
	positionInGL();

	double LOB = scale*3.0; //length of body
	double WOB = scale*2.0; //width of body
	double HOB = scale*1.0; //height of body

	double FWR = scale*0.3; //front wheel radius
	double BWR = scale*0.3; //back wheel radius
	double FWW = scale*0.1; //front wheel width
	double BWW = scale*0.1; //back wheel width

	double start_PosX = 0;
	double start_PosY = 0;
	double start_PosZ = 0;

	Rectangle_Prism(LOB, HOB, WOB, start_PosX, start_PosY, start_PosZ, speed, 1, 0.6, 1);

	Cylinder(FWR, FWW, start_PosX + scale*1.1, start_PosY - scale*0.5, start_PosZ + scale*1.1, speed, steering).draw();
	Cylinder(FWR, FWW, start_PosX + scale*1.1, start_PosY - scale*0.5, start_PosZ - scale*1.1, speed, steering).draw();
	Cylinder(BWR, BWW, start_PosX - scale*1.1, start_PosY - scale*0.4, start_PosZ + scale*1.05, speed, 0).draw();
	Cylinder(BWR, BWW, start_PosX - scale*1.1, start_PosY - scale*0.4, start_PosZ - scale*1.05, speed, 0).draw();
	

	glPopMatrix();

}

MyVehicle::~MyVehicle() {

}