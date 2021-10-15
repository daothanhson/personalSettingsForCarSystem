#include"Car.h"


Car::Car() {
	carName = '\0';
	email = '\0';
	keyNum = '\0';
	ODO = 0;
	remindService = 0;
}
Car::~Car() {}
void Car::setCarName(string data) {
	this->carName = data;
}
void Car::setEmail(string data) {
	this->email = data;
}
void Car::setKeyNum(string data) {
	this->keyNum = data;
}
void Car::setODO(int data) {
	this->ODO = data;
}
void Car::setRemindService(int data) {
	this->remindService = data;
}
string Car::getCarName() {
	return this->carName;
}
string Car::getEmail() {
	return this->email;
}
string Car::getKeyNum() {
	return this->keyNum;
}
int Car::getODO() {
	return this->ODO;
}
int Car::getRemindService() {
	return this->remindService;
}

