
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
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

Cylinder::Cylinder() {

}

Cylinder::Cylinder(double Radius, double Length, double PosX, double PosY, double PosZ, double Speed, double Angle) {
	radius = Radius;
	length = Length;
	posX = PosX;
	posY = PosY;
	posZ = PosZ;
	speed = Speed;
	angle = -Angle*2;
}

void Cylinder::draw() {


	
	glPushMatrix();

	static double spinning_angle = 0;
	spinning_angle = spinning_angle - speed;

	positionInGL();
	glTranslatef(posX, posY, posZ-length/2);
	glRotatef(angle, 0, 1, 0);
	glRotatef(spinning_angle, 0, 0, 1);

	
	GLUquadric*quadric;
	quadric = gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_OUTSIDE);
	gluQuadricTexture(quadric, GL_TRUE);
	glColor3f(0.3f, 0.59f, 0.11f);
	gluCylinder(quadric, radius, radius, length, 360, 1);
	
	//Front face
	positionInGL();
	glTranslatef(0, 0, 0);
	gluDisk(quadric, 0, radius, 360, 1);
	
	//Back Face
	positionInGL();
	glTranslatef(0, 0, length);
	gluDisk(quadric, 0, radius, 360, 1);

	int numSpokes = 5;
	double angleSpokes = 360 / numSpokes;
	
	for (int i = 0; i < numSpokes; i++) {
			positionInGL();
			glTranslatef(0, 0, 0);
			glColor3f(0.0f, 0.0f, 0.0f);
			glRotatef(angleSpokes, 0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex3f(0.0, -radius, 0.0);
			glVertex3f(0.0, radius, 0.0);
			glEnd();
			angleSpokes = angleSpokes + angleSpokes;
	}

	angleSpokes = 360 / numSpokes;
	for (int i = 0; i < numSpokes; i++) {
		positionInGL();
		glTranslatef(0, 0, -length);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRotatef(angleSpokes, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, -radius, 0.0);
		glVertex3f(0.0, radius, 0.0);
		glEnd();
		angleSpokes = angleSpokes + angleSpokes;
		length = 0;
	} 
	
	
	glPopMatrix();
}

Cylinder::~Cylinder() {

}
