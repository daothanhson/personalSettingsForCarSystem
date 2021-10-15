#ifndef SETTING_H
#define SETTING_H

#include<iostream>
#include<string>
#include"Display.h"
#include"General.h"
#include"Sound.h"
#include"Car.h"
#include<regex>

using namespace std;

class Setting : public Car
{
public:
	Setting();
	~Setting();
	void inputInfor();
	void outputInfor();
	void setDisplay(Display* display);
	void setSound(Sound* sound);
	void setGeneral(General* genaral);
	Display* getDisplay();
	Sound* getSound();
	General* getGeneral();
	void copyInfor(Setting* st);
private:
	Display* display;
	Sound* sound;
	General* general;
};
int checkData();
#endif // !SETTING_H



