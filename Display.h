#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Display
{
public:
	Display();
	// set light level
	void setLightLevel(int data);
	void setScreenLightLevel(int data);
	void setTaploLightLevel(int data);
	void inputInforDisplay();
	// get light level
	int getLightLevel();
	int getScreenLightLevel();
	int getTapLoLightLevel();
	void outputInforDisplay();
private:
	int lightLevel;
	int screenLightLevel;
	int taploLightLevel;
};

// check level 1 to 100
int checkNum();


#endif // !DISPLAY_H



