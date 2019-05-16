#pragma once


class GameController
{
public:
	//Constructor
	GameController();

	//overloaded constructor
	GameController(int i) { ... };
		 
	//Getters
	int GetBattery();

	//Destructor
	~GameController();
};