// AutoTempDetection.cpp : Defines the entry point for the application.
//

#include "AutoTempDetection.h"
#include <any>

using namespace std;
bool checkIfInt(any var);
bool checkIfNull(int var);
#define MIN_POSSIBLE_TEMP -270
#define MAX_POSSIBLE_TEMP 100

/*
 * Interface that controls room temperature based on user input.
 * @param {any} minTemp : Minimunum room temperature below which the heater starts 
 * @param {any} maxTemp : Maximum room temperature above which the cooler starts
 * @param {any} roomTemp : Current room temperature
*/
string runAutoTempControl(any minTemp = 0xFFFF, any  maxTemp = 0xFFFF, any roomTemp = 0xFFFF) {
	string output;
	if (!checkIfInt(minTemp) || !checkIfInt(maxTemp) || !checkIfInt(roomTemp)) {
		output = "Invalid Input Type. Use integer number to set temperature\n";
	}
	else {
		int tempMinTemp = any_cast<int>(minTemp);
		int tempMaxTemp = any_cast<int>(maxTemp);
		int tempRoomTemp = any_cast<int>(roomTemp);
		if (checkIfNull(tempMinTemp) || checkIfNull(tempMaxTemp)|| checkIfNull(tempRoomTemp)) {
			output = "Please enter minimum, maximum and present room temperature. Missing Arguments\n";
		}
		else if ((tempMinTemp < MIN_POSSIBLE_TEMP) || (tempMaxTemp < MIN_POSSIBLE_TEMP) || (tempRoomTemp < MIN_POSSIBLE_TEMP)) {
			output = "No temperature can be less than -270 degree C\n";
		}
		else if ((tempMinTemp > MAX_POSSIBLE_TEMP) || (tempMaxTemp > MAX_POSSIBLE_TEMP) || (tempRoomTemp > MAX_POSSIBLE_TEMP)) {
			output = "No temperature can be more than 100 degree C\n";
		}
		else if (tempMinTemp > tempMaxTemp) {
			output = "Minimum room temperature cannot be more than maximum room temperature\n";
		}
		else if ((tempMinTemp == tempRoomTemp) && (tempMaxTemp == tempRoomTemp)) {
			output = "Warning!! both heater and cooler running at the same time. Adjust temperature\n";
		}
		else if (tempRoomTemp <= tempMinTemp) {
			output = "Heating started\n";
		}
		else if (tempRoomTemp >= tempMaxTemp) {
			output = "Cooling started\n";
		}
		else if ((tempRoomTemp> tempMinTemp) && (tempRoomTemp < tempMaxTemp)) {
			output = "Pleasant Room Temperatutre. Both heater and cooler are off\n";
		}
	}
	return output;
}


int main()
{
	cout << runAutoTempControl(20, 40, 32) << endl;
	return 0;
}