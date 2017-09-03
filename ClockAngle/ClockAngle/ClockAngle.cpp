// "ClockAngle.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

//------------------------------------------------------
//TASK:
//Given two integers, an hour and a minute, 
//write a function to calculate the angle between the two hands on a clock representing that time.
//------------------------------------------------------

#include "stdafx.h"
#include <iostream>


//returns the angle between the 12 on the top of a clock and int minutes of the hour minute hand
double AngleMinutes(int minutes) {
	if (minutes == 0) {
		return 0;
	}

	double factor = (double)minutes / 60;
	return factor * 360;
}

//returns the angle between the 12 on the top of a clock and int hour of the hour clock hand
double AngleHours(int hour) {
	if (hour == 0 || hour == 12) {
		return 0;
	}
	if (hour > 12) {
		hour -= 12;
	}
	double factor = (double)hour / 12;
	return factor * 360;
}


double ClockAngle(int hour, int minutes) {

	//if degree of bottom angle <= 180 return bottom angle, 
	//if degree of bottom angle > 180 return top angle (just returned, not defined as a variable)
	//always return the lesser of the two (bootom/top angle)
	double bottomAngle;

	//hourOffset: taking into account, that the hour clock hand moves as well (changes the angle to a degree between 0 and 30)
	//if this function returns the bottom angle: if the hour angle is bigger than the minute angle it will decrease it and vice versa
	//if this function returns the top angle: if the minute angle is bigger than the hour angle it will decrease it and vice versa
	double hourOffset = ((double)minutes / 60) * 30;


	//check if time is valid: 
	if (hour < 0 || hour > 23 || minutes < 0 || minutes > 60) {
		std::cout << "Not a valid time. Error value -1\n";
		return -1;
	}

	//if time is valid calculate the angle:
	else {
		double angleHour = AngleHours(hour);
		double angleMin = AngleMinutes(minutes);		

		//case 1
		if (angleHour > angleMin) {
			bottomAngle = (angleHour - angleMin) + hourOffset;
			if (bottomAngle <= 180) {
				return bottomAngle;
			}
			//else returns top angle
			else return (360 - angleHour) + minutes - hourOffset;
			
		}

		//case 2
		else {
			bottomAngle = (angleMin - angleHour) - hourOffset;
			if (bottomAngle <= 180) {
				return bottomAngle;
			}
			//else returns top angle
			else return (360 - angleMin) + angleHour + hourOffset;
			
		}		
	}	
}




int main()
{
	std::cout << "Press Enter to set you time\n\n";
	int hrs;
	std::cout << "Hour: ";
	std::cin >> hrs;
	int min;
	std::cout << "Minutes: ";
	std::cin >> min;
	std::cout << std::endl << std::endl;

	std::cout << "The angle is: " << ClockAngle(hrs,min);
	std::cin.get();
	std::cin.get();
    return 0;
}

