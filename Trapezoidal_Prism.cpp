
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Trapezoidal_Prism.h"
#include <math.h>

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

Trapezoid_Prism::Trapezoid_Prism() {

}

Trapezoid_Prism::Trapezoid_Prism(double Height, double Base, double Length, double Top) {
	height = Height; //side
	base = Base; //base
	length = Length; //length
	top = Top;
}

void Trapezoid_Prism::draw() {
	glPushMatrix();
	positionInGL();
	double posX = 0;
	double posY = 4;
	double posZ = 0;

	glTranslatef(posX, posY, posZ);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	
	//Front
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ + length*0.5);
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ + length*0.5);

	//Back
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ - length*0.5);
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ - length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ - length*0.5);
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ - length*0.5);

	//Bottom
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ + length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ + length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ - length*0.5);
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ - length*0.5);

	//top
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ - length*0.5);
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ - length*0.5);
	
	//Right Side
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX + top*0.5, posY + height*0.5, posZ - length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ - length*0.5);
	glVertex3f(posX + base*0.5, posY - height*0.5, posZ + length*0.5);

	//Left Side
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ + length*0.5);
	glVertex3f(posX - top*0.5, posY + height*0.5, posZ - length*0.5);
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ - length*0.5);
	glVertex3f(posX - base*0.5, posY - height*0.5, posZ + length*0.5);
	

	glEnd();
	glPopMatrix();
}

Trapezoid_Prism::~Trapezoid_Prism() {

}