
#pragma once

#include <iostream>
#include "Shape.hpp"

class Triangular_Prism : public Shape 
{
protected:
	double height;
	double base;
	double length;
	double angle;public:
	Triangular_Prism();
	Triangular_Prism(double Height, double Base, double Length);
	void draw();
	~Triangular_Prism();

};



