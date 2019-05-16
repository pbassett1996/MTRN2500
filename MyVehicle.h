#pragma once

#include "Shape.hpp"
#include "Vehicle.hpp"

class MyVehicle : public Vehicle
{
protected:
	double scale;
public:
	MyVehicle();
	MyVehicle(double Scale);
	void draw();
	~MyVehicle();

};