#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo {
public:
	string getNumber() {
		return number;
	}

	string getName() {
		return name;
	}

	void setNumber(string data) {
		number = data;
	}

	void setName(string data) {
		name = data;
	}
private:
	string number;
	string name;
};

#endif // COMMON_H

