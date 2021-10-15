#include"General.h"

General::General() {
	timezone = "GMT-7:00";
	language = "English";
}

void General::setTimezone(string data) {
	this->timezone = data;
}

void General::setLanguage(string data) {
	this->language = data;
}
void General::outputInforGeneral() {
	cout << setw(15) << this->timezone << setw(10) << this->language << endl;
}