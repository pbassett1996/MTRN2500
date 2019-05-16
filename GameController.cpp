#include <iostream>
#include <Windows.h>
#include <Xinput.h>
#include "Header.h"

//Constructor

GameController::GameController()
{

}

//Getters
int GameController::GetBattery()
{
	XINPUT_BATTERY_INFORMATION BatteryInformation;
	XInputGetBatteryInformation(0, BATTERY_DEVTYPE_GAMEPAD, &BatteryInformation);
	switch (BatteryInformation.BatteryLevel)
	{
	case BATTERY_LEVEL_EMPTY: return 0;
		break;
	case BATTERY_LEVEL_LOW: return 1;
		break;
	case BATTERY_LEVEL_MEDIUM: return 2;
		break;
	case BATTERY_LEVEL_FULL: return 3;
	}
}

