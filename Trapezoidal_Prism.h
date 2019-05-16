#pragma once

#include "Shape.hpp"

class Trapezoid_Prism : public Shape
{
protected:
	double height;
	double length;
	double base;
	double top;
public:
	Trapezoid_Prism();
	Trapezoid_Prism(double Height, double Length, double Base, double Top);
	void draw();
	~Trapezoid_Prism();
};


