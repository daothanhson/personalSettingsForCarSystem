#include "Display.h"
#include<regex>

Display::Display() {
	this->lightLevel = 0;
	this->screenLightLevel = 0;
	this->taploLightLevel = 0;
}

// set light level
void Display::setLightLevel(int data) {
	this->lightLevel = data;
}
// set screen light level
void Display::setScreenLightLevel(int data) {
	this->screenLightLevel = data;
}
// set taplo light level
void Display::setTaploLightLevel(int data) {
	this->taploLightLevel = data;
}
// get light level
int Display::getLightLevel() {
	return this->lightLevel;
}
// get screen light level
int Display::getScreenLightLevel() {
	return this->screenLightLevel;
}
// get taplo light level
int Display::getTapLoLightLevel() {
	return this->taploLightLevel;
}
// input information display
void Display::inputInforDisplay() {
	cout << "Enter light level: ";
	setLightLevel(checkNum());
	cout << "Enter screen light level: ";
	setScreenLightLevel(checkNum());
	cout << "Enter taplo light level: ";
	setTaploLightLevel(checkNum());
}
// output information display
void Display::outputInforDisplay() {
	cout << setw(10) << to_string(this->lightLevel)
		<< setw(10) << to_string(this->screenLightLevel)
		<< setw(10) << to_string(this->taploLightLevel);
		

}
// check level 1 to 100
int checkNum() {
	regex level("(\\d+)");
	string userInputLevel = "";
	bool flag = true;
	do
	{
		getline(cin, userInputLevel);
		if (userInputLevel.length() > 3 || stoi(userInputLevel) > 100 || !regex_match(userInputLevel, level)) {
			cout << "You entered the wrong value!!!" << '\n';
			cout << "Please enter again!!!!" << endl;
			flag = false;
		}
		else {
			flag = true;
		}
	} while (!flag);
	return stoi(userInputLevel);
}