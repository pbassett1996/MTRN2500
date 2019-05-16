
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Triangular_Prism.h"
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

Triangular_Prism::Triangular_Prism() {

}

Triangular_Prism::Triangular_Prism(double Height, double Base, double Length) {
	height = Height; //side
	base = Base; //base
	length = Length; //length
}

void Triangular_Prism::draw() {
	glPushMatrix();
	positionInGL();
	double posX = 0 + base / 2;
	double posY = 0 + height / 2;
	double posZ = 0 + length / 2;

	glTranslatef(posX, posY, posZ);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);

	//Back Triangle
	glVertex3f(posX - base / 2, posY - height / 2, posZ - length / 2);
	glVertex3f(posX, posY + height / 2, posZ - length / 2);
	glVertex3f(posX + base / 2, posY - height / 2, posZ - length / 2);

	

	//Front Triangle
	glVertex3f(posX - base / 2, posY - height / 2, posZ + length / 2);
	glVertex3f(posX, posY + height / 2, posZ + length / 2);
	glVertex3f(posX + base / 2, posY - height / 2, posZ + length / 2);
	glEnd();

	glBegin(GL_QUADS);

	//Bottom
	glVertex3f(posX - base / 2, posY - height / 2, posZ - length / 2);
	glVertex3f(posX - base / 2, posY - height / 2, posZ + length / 2);
	glVertex3f(posX + base / 2, posY - height / 2, posZ + length / 2);
	glVertex3f(posX + base / 2, posY - height / 2, posZ - length / 2);

	//Left Side
	glVertex3f(posX - base / 2, posY - height / 2, posZ - length / 2);
	glVertex3f(posX - base / 2, posY - height / 2, posZ + length / 2);
	glVertex3f(posX, posY + height / 2, posZ + length / 2);
	glVertex3f(posX, posY + height / 2, posZ - length / 2);

	//Right Side
	glVertex3f(posX + base / 2, posY - height / 2, posZ - length / 2);
	glVertex3f(posX + base / 2, posY - height / 2, posZ + length / 2);
	glVertex3f(posX, posY + height / 2, posZ + length / 2);
	glVertex3f(posX, posY + height / 2, posZ - length / 2);

	glEnd();
	glPopMatrix();
}

Triangular_Prism::~Triangular_Prism() {

}



