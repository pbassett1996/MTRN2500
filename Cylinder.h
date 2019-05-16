#pragma once

#include "Shape.hpp"

class Cylinder : public Shape
{
protected:
	double radius;
	double length;
	double posX;
	double posY;
	double posZ;
	double speed;
	double angle;
	double r;
	double g;
	double b;
public:
	Cylinder();
	Cylinder(double Radius, double Length, double Angle, double PosX, double PosY, double PosZ, double Speed);
	void draw();
	~Cylinder();
};
