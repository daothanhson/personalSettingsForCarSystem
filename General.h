#ifndef GENERAL_H
#define GENERAL_H

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class General
{
public:
	General();
	void setTimezone(string data);
	void setLanguage(string data);
	string getTimezone() {
		return this->timezone;
	}
	string getLanguage() {
		return this->language;
	}
	void outputInforGeneral();
private:
	string timezone;
	string language;
};
#endif // !GENERAL_H



