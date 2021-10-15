#include"Setting.h"
#include<regex>

int checkData() {
	int n = 0;
	regex num("[0-9]+");
	string checkUserInput = "";
	do
	{
		cout << "Your selection: ";
		getline(cin, checkUserInput);
		if (checkUserInput.length() < 6 && regex_match(checkUserInput, num)) {
			n = stoi(checkUserInput);
		}
		else {
			cout << "Enter again!!!" << endl;
		}
	} while (!regex_match(checkUserInput, num) || checkUserInput.length() >= 6);
	return n = stoi(checkUserInput);
}
void Setting::copyInfor(Setting* st)
{
	setCarName(st->getCarName());
	setKeyNum(st->getKeyNum());
	setODO(st->getODO());
	setEmail(st->getEmail());
	setRemindService(st->getRemindService());
}



Setting::Setting() {
	display = new Display();
	sound = new Sound();
	general = new General();
}

Setting::~Setting() {
	/*delete display;
	delete sound;
	delete general;*/
}

void Setting::inputInfor() {
	regex regexCarName("([a-zA-Z]+( [a-zA-Z]+)*){1,30}");
	regex regexEmail("(\\w+){3,}(\\.|_)?(\\w*)@(\\w+){3,}(\\.(\\w+){3,})+");
	regex regexKeyNum("^[0-9]{8}$");

	string str = "";
	while (true)
	{
		cout << "Enter car name: ";
		getline(cin, str);
		setCarName(str);
		if (!regex_match(getCarName(), regexCarName)) {
			cout << "Input a invalid name!";
		}
		else {
			break;
		}
	}
	while (true)
	{
		cout << "Enter email: ";
		getline(cin, str);
		setEmail(str);
		if (!regex_match(getEmail(), regexEmail)) {
			cout << "Input a invalid name!\n"
				<< "please enter form abc@xyz.def" << endl;
		}
		else {
			break;
		}
	}
	while (true)
	{
		cout << "Enter key number: ";
		getline(cin, str);
		setKeyNum(str);
		if (!regex_match(getKeyNum(), regexKeyNum)) {
			cout << "Please enter 8 digits";
		}
		else {
			break;
		}
	}
	cout << "Enter ODO: ";
	setODO(checkData());
	cout << "Enter remind service: ";
	setRemindService(checkData());
}
void Setting::outputInfor() {
	cout << setw(20) << getCarName()
		<< setw(25) << getEmail()
		<< setw(20) << getKeyNum()
		<< setw(10) << to_string(getODO())
		<< setw(10) << to_string(getRemindService());
}

void Setting::setDisplay(Display* display) {
	this->display = display;
}

void Setting::setSound(Sound* sound) {
	this->sound = sound;
}

void Setting::setGeneral(General* genaral) {
	this->general = general;
}

Display* Setting::getDisplay() {
	return display;
}

Sound* Setting::getSound() {
	return sound;
}

General* Setting::getGeneral() {
	return general;
}