#include"Sound.h"
#include<regex>

// check level volumn 1 to 100
int checkNum2() {
	regex level("[0-9]+");
	string userInputLevel = "";
	bool flag = true;
	do
	{
		getline(cin, userInputLevel);
		if (userInputLevel.length() > 4 || !regex_match(userInputLevel, level) || stoi(userInputLevel) > 100) {
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

Sound::Sound() {
	this->mediaVolumeLevel = 0;
	this->callVolumeLevel = 0;
	this->navigationVolumeLevel = 0;
	this->notificationVolumeLevel = 0;
}


// set media volumn level
void Sound::setMediaVolumeLevel(int data) {
	this->mediaVolumeLevel = data;
}
// set call volume level
void Sound::setCallVolumeLevel(int data) {
	this->callVolumeLevel = data;
}
// set navigation volume level
void Sound::setNavigationVolumeLevel(int data) {
	this->navigationVolumeLevel = data;
}
// set notification volume level
void Sound::setNotificationVolumeLevel(int data) {
	this->notificationVolumeLevel = data;
}
// get media volume level
int Sound::getMediaVolumeLevel() {
	return this->mediaVolumeLevel;
}
// get call volume level
int Sound::getCallVolumeLevel() {
	return this->callVolumeLevel;
}
// get navigation volume level
int Sound::getNavigationVolumeLevel() {
	return this->navigationVolumeLevel;
}
// get notification volume level
int Sound::getNotificationVolumeLevel() {
	return this->notificationVolumeLevel;
}
// input information sound
void Sound::inputInforSound() {
	cout << " Enter media volume level: ";
	setMediaVolumeLevel(checkNum2());
	cout << " Enter call volume level: ";
	setCallVolumeLevel(checkNum2());
	cout << " Enter navigation volume level: ";
	setNavigationVolumeLevel(checkNum2());
	cout << " Enter notification volume level: ";
	setNotificationVolumeLevel(checkNum2());
}
// show information sound
void Sound::outputInforSound() {

	cout << setw(10) << this->mediaVolumeLevel
		<< setw(10) << this->callVolumeLevel
		<< setw(10) << this->navigationVolumeLevel
		<< setw(10) << this->notificationVolumeLevel;
}