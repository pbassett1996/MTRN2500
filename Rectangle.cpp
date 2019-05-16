#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Rectangle.h"

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

Rectangle_Prism::Rectangle_Prism() {

}

Rectangle_Prism::Rectangle_Prism(double X_Length, double Y_Length, double Z_Length, double PosX, double PosY, double PosZ, double Speed, double R, double G, double B) {
	x_length = X_Length;
	y_length = Y_Length;
	z_length = Z_Length;
	posX = PosX;
	posY = PosY;
	posZ = PosZ;
	speed = Speed;
	r = R;
	g = G;
	b = B;

}

void Rectangle_Prism::draw() {
	glPushMatrix();
	positionInGL();
	glTranslatef(posX, posY, posZ);
	glBegin(GL_QUADS);

	x_length = x_length / 2;
	y_length = y_length / 2;
	z_length = z_length / 2;

	//Front Face
	glColor3f(r, g, b);
	glVertex3f(posX - x_length, posY + y_length, posZ + z_length);
	glVertex3f(posX + x_length, posY + y_length, posZ + z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ + z_length);
	glVertex3f(posX - x_length, posY - y_length, posZ + z_length);

	//Back Face
	glVertex3f(posX - x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ - z_length);
	glVertex3f(posX - x_length, posY - y_length, posZ - z_length);

	//left Face
	glVertex3f(posX - x_length, posY + y_length, posZ + z_length);
	glVertex3f(posX - x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX - x_length, posY - y_length, posZ - z_length);
	glVertex3f(posX - x_length, posY - y_length, posZ + z_length);

	//right Face
	glVertex3f(posX + x_length, posY + y_length, posZ + z_length);
	glVertex3f(posX + x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ + z_length);

	//top Face
	glVertex3f(posX - x_length, posY + y_length, posZ + z_length);
	glVertex3f(posX - x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY + y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY + y_length, posZ + z_length);

	//bottom Face
	glVertex3f(posX - x_length, posY - y_length, posZ + z_length);
	glVertex3f(posX - x_length, posY - y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ - z_length);
	glVertex3f(posX + x_length, posY - y_length, posZ + z_length);


	glEnd();
	glFlush();

	glPopMatrix();

}

Rectangle_Prism::~Rectangle_Prism() {

}

