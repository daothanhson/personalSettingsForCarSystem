#ifndef SOUND_H
#define SOUND_H

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


class Sound
{
public:
	Sound();
	~Sound() {};
	// set volume level
	void setMediaVolumeLevel(int data);
	void setCallVolumeLevel(int data);
	void setNavigationVolumeLevel(int data);
	void setNotificationVolumeLevel(int data);

	// get volume level
	int getMediaVolumeLevel();
	int getCallVolumeLevel();
	int getNavigationVolumeLevel();
	int getNotificationVolumeLevel();
	void inputInforSound();
	void outputInforSound();
private:
	int mediaVolumeLevel;
	int callVolumeLevel;
	int navigationVolumeLevel;
	int notificationVolumeLevel;
};
int checkNum2();

#endif // !SOUND_H



