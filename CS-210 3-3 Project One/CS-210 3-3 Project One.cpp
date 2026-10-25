//CS-210 Project 1 Sean Porter 09/23/26
#include <vector>
#include <iostream>
#include <string>


using namespace std;

//Global variables to keep track of things used in and out of different loops and functions.
int userInput = 4;
int clockHour;
int clockHour12;
int clockMinute;
int clockSecond;

bool getHour = true;
bool getMinute = true;
bool getSecond = true;

string timeOfDay = "AM";
string userTime;


//Various functions to add time and set it back to the start when value is overflowed.
void addHour() {
	++clockHour;
	if (clockHour >= 24) {
		clockHour = 0;
	}
}

void addMinute() {
	++clockMinute;
	if (clockMinute >= 60) {
		clockMinute = 0;
		addHour();
	}
}

void addSecond() {
	++clockSecond;
	if (clockSecond >= 60) {
		clockSecond = 0;
		addMinute();
	}
}


//The function that gets the time from the user
//Each aspect is split up into its own set of loops and will only go on to the next if the input is valid
//I put in abort statements because if you put a letter into the input it would break the program and I couldn't figure out how to fix it in a timely manner so this is a bandaid fix. Assignment is already late as it is.
void getTime() {
	while (getHour == true) {
		cout << "Please enter the hour: ";
		cin >> clockHour;


		if (clockHour >= 0 && clockHour < 24) {
			getHour = false;
			continue;
		}
		else {
			cout << "Not a valid input" << endl;
		}
	}
	
	while (getMinute == true) {
		cout << "Please enter the minute: ";
		cin >> clockMinute;

	

		if (clockMinute >= 0 && clockMinute < 60) {
			getMinute = false;
			continue;
		}
		else {
			cout << "Not a valid input" << endl;
		}
	}

	while (getSecond == true) {
		cout << "Please enter the second: ";
		cin >> clockSecond;

		
		if (clockSecond >= 0 && clockSecond < 60) {
			getSecond = false;
			userInput = 0;
			continue;
		}
		else {
			cout << "Not a valid input" << endl;
		}
	}
	


	
}

//This is the function that displays the time, along with adding zeros to the single digit times.
void displayTime24() {
	if (clockHour < 10) { 
		cout << "0" << clockHour << ":"; 
	}
	else {
		cout << clockHour << ":";
	}

	if (clockMinute < 10) { 
		cout << "0" << clockMinute << ":"; 
	}
	else {
		cout << clockMinute << ":";
	}

	if (clockSecond < 10) { 
		cout << "0" << clockSecond << endl; 
	}
	else {
		cout << clockSecond << endl;
	}
	
}

//This is the function that displays the 12 hour format. It creates its own variable as not to conflict with the other variable used by displayTime24.
void displayTime12() {
	clockHour12 = clockHour;

	if (clockHour12 > 12) {
		timeOfDay = "PM";
		clockHour12 = clockHour12 % 12;
	}
	else if (clockHour12 == 0 && timeOfDay == "PM") {
		timeOfDay = "AM";
		clockHour12 = 12;
	}

	if (clockHour12 < 10) {
		cout << "0" << clockHour12 << ":";
	}
	else {
		cout << clockHour12 << ":";
	}

	if (clockMinute < 10) {
		cout << "0" << clockMinute << ":";
	}
	else {
		cout << clockMinute << ":";
	}

	if (clockSecond < 10) {
		cout << "0" << clockSecond << " ";
	}
	else {
		cout << clockSecond << " ";
	}

	cout << timeOfDay << endl;

}




void main() {
	getTime();

	//The loop that runs and creates the user menu.
	while (userInput != 4) {
		displayTime24();
		displayTime12();
		cout << "1 - Add One Hour" << endl << "2 - Add One Minute" << endl << "3 - Add One Second" << endl << "4 - Exit Program" << endl;
		cin >> userInput;

		//This is how the parts of the time are added. If the input is not a valid one, it will give an error message and run the loop again.
		if (userInput == 1) {
			addHour();
		}
		else if (userInput == 2) {
			addMinute();
		}
		else if (userInput == 3) {
			addSecond();
		}
		else {
			cout << "Not a valid input" << endl;
		}
	}
}


