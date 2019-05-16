#include <iostream>
#include <Windows.h>
#include <Xinput.h>
#include "Header.h"

using namespace std;

int main()
{
	if (GetBattery() == 0) {
		cout << "No Battery. Please Recharge." << endl;
	}
	else if (GetBattery() == 1) {
		cout << "Battery Level Low. Please Recharge." << endl;
	}
	else if (GetBattery() == 2) {
		cout << "Battery Level Medium" << endl;
	}
	else if (GetBattery() == 3) {
		cout << "Battery Full" << endl;
	}
}