#pragma once

#include "Shape.hpp"

class Rectangle_Prism : public Shape
{
	friend Shape;
protected:
	double x_length;
	double y_length;
	double z_length;
	double posX;
	double posY;
	double posZ;
	double speed;
	double r;
	double g;
	double b;

public:
	Rectangle_Prism();
	Rectangle_Prism(double X_Length, double Y_Length, double Z_Length, double PosX, double PosY, double PosZ, double Speed, double R, double G, double B);
	void draw();
	~Rectangle_Prism();
};

