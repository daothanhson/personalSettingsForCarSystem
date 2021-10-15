#include<iostream>
#include<fstream>
#include<regex>
#include"Display.h"
#include"Sound.h"
#include"General.h"
#include"Setting.h"
#include"Car.h"
#include"CommonInfor.h"
#include<vector>
#include<sstream>
#include"Node_BST.cpp"
using namespace std;

// variable global
//Setting* carSetting = new Setting[100];
BST<Setting>carSetting;

vector<CommonInfo> timezoneList; // Timezone
vector<CommonInfo> languageList; //Language

// input data setting
void inputSetting();
void inputSettingDisplay();
void inputSettingSound();
void inputSettingGerenal();

// output data setting
void outputSetting();
void outputSettingDisplay();
void outputSettingSound();
void outputSettingGeneral();
void outputSettingAll();

void menu();
void showMenu();
void showMenuSetting();

// sort
bool sortName(CommonInfo& a_str, CommonInfo& b_str);

// check information owner car
string enterKeyNum();
string enterName();
int checkData3();
int checkData2(int len);
string enterYesOrNo();

void loadData();
void downloadTimezone();
void downloadLanguage();
//show information display
void showTimezone();
void showLanguage();
/*--------MAIN-----------------*/
/*-----------------------------*/
int main()					   //
{							   //
	loadData();				   //
	downloadTimezone();		   //
	downloadLanguage();		   //
	menu();					   //
	system("pause");		   //
	return 0;				   //
}							   //
/*-----------------------------*/
/*-----------------------------*/
void showMenu() {
	cout << "==========SELECT MENU=========\n"
		<< "1. Input setting information\n"
		<< "2. Print setting information\n"
		<< "3. Exit" << endl;
}
void showMenuSetting() {
	cout << "==========SELECT MENU=========\n"
		<< "1. Display setting\n"
		<< "2. Sound setting\n"
		<< "3. General setting\n"
		<< "4. Return"
		<< endl;
}
void menu() {
	int select = 0;
	showMenu();
	select = checkData3();
	system("cls");
	switch (select)
	{
	case 1:
		inputSetting();
		break;
	case 2:
		if (carSetting.sizeTree() == 0) {
			cout << "You have no car in the System" << endl;
			menu();
			return;
		}
		else {
			outputSetting();
		}
		break;
	case 3:
		cout << "Good bye!!!!" << endl;
		break;
	default:
		cout << "Wrong data input!!!\n"
			<< "Enter again, your selection: " << endl;
		system("pause");
		system("cls");
		menu();
	}
}
void inputSetting() {
	int select = 0;
	showMenuSetting();
	select = checkData3();
	system("cls");
	switch (select)
	{
	case 1:
		inputSettingDisplay();
		system("cls");
		menu();
		break;
	case 2:
		inputSettingSound();
		system("cls");
		menu();
		break;
	case 3:
		inputSettingGerenal();
		menu();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "Wrong data input!!!\n"
			<< "Enter again, your selection: " << endl;
		system("pause");
		system("cls");
		inputSetting();
		break;
	}
}


void outputSetting() {
	int select = 0;
	cout << "==========SELECT MENU=========\n"
		<< "1. Print display setting information\n"
		<< "2. Print sound setting information\n"
		<< "3. Print general setting information\n"
		<< "4. Print all setting information\n"
		<< "5. Return"
		<< endl;
	select = checkData3();
	system("cls");
	switch (select)
	{
	case 1:
		outputSettingDisplay();
		system("pause");
		system("cls");
		menu();
		break;
	case 2:
		outputSettingSound();
		system("pause");
		system("cls");
		menu();
		break;
	case 3:
		outputSettingGeneral();
		system("pause");
		system("cls");
		menu();
		break;
	case 4:
		// input peronal key and show information car
		outputSettingAll();
		system("pause");
		system("cls");
		outputSetting();
		break;
	case 5:
		menu();
		break;
	default:
		cout << "Enter again!!!" << endl;
		outputSetting();
		break;
	}
}

void inputSettingDisplay() {
	system("cls");
	int n = 0;
	string continues = "";
	do
	{
		Setting* setting = new Setting();
		cout << "======Input display setting=======\n"
			<< "Car index " << carSetting.sizeTree() + 1 << endl;
		setting->inputInfor();
		string s = setting->getKeyNum();
		if (carSetting.sizeTree() > 0) {
			if (carSetting.searchNodeByKey(s) != NULL) {
				cout << "This car " << carSetting.sizeTree() + 1 << " already existed, data will be overitten\n";
				carSetting.searchNodeByKey(s)->data->copyInfor(setting);
				carSetting.searchNodeByKey(s)->data->getDisplay()->inputInforDisplay();
				delete setting;
			}
			else {
				cout << "This car " << carSetting.sizeTree() + 1 << " data will be appended to your list\n";
				setting->getDisplay()->inputInforDisplay();
				carSetting.insertNode(setting);
			}
		}
		else {
			cout << "This is the first car" << endl;
			setting->getDisplay()->inputInforDisplay();
			carSetting.insertNode(setting);
		}
		carSetting.saveDataNode();
		cout << "CONTINUE TO NUMBER CAR " << carSetting.sizeTree() + 1 << " ? (y/n): ";
		continues = enterYesOrNo();
		system("cls");
	} while (continues == "y" || continues == "Y");
}
void inputSettingSound() {
	system("cls");
	int n = 0;
	string continues = "";
	do
	{
		Setting* setting = new Setting();
		cout << "========input setting sound===========\n"
			<< "Car index: " << carSetting.sizeTree() + 1 << endl;
		setting->inputInfor();
		string s = setting->getKeyNum();
		if (carSetting.sizeTree() > 0) {
			if (carSetting.searchNodeByKey(s) != NULL) {
				cout << "This car " << carSetting.sizeTree() + 1 << " already existed, data will be overitten\n";
				carSetting.searchNodeByKey(s)->data->copyInfor(setting);
				carSetting.searchNodeByKey(s)->data->getSound()->inputInforSound();
				delete setting;
			}
			else {
				cout << "This car " << carSetting.sizeTree() + 1 << " data will be appended to your list\n";
				setting->getSound()->inputInforSound();
				carSetting.insertNode(setting);
			}
		}
		else {
			cout << "This is the first car" << endl;
			setting->getSound()->inputInforSound();
			carSetting.insertNode(setting);
		}
		carSetting.saveDataNode();
		cout << "CONTINUE TO NUMBER CAR " << carSetting.sizeTree() + 1 << " ? (y/n): ";
		continues = enterYesOrNo();
	} while (continues == "y" || continues == "Y");

}

void inputSettingGerenal() {
	system("cls");
	int n = 0;
	int index = 0;
	string continues = "";
	do
	{
		Setting* setting = new Setting();
		cout << "========input setting gerenal===========\n"
			<< "Car index: " << carSetting.sizeTree() + 1 << endl;
		setting->inputInfor();
		string s = setting->getKeyNum();
		if (carSetting.sizeTree() > 0) {
			if (carSetting.searchNodeByKey(s) != NULL) {
				cout << "This car " << carSetting.sizeTree() + 1 << " already existed, data will be overitten\n";
				carSetting.searchNodeByKey(s)->data->copyInfor(setting);
				showTimezone();
				cout << "\nEnter number: ";
				index = checkData2((int)timezoneList.size());
				carSetting.searchNodeByKey(s)->data->getGeneral()->setTimezone(timezoneList[index].getNumber());
				system("cls");
				showLanguage();
				cout << "\nEnter number: ";
				index = checkData2((int)languageList.size());
				carSetting.searchNodeByKey(s)->data->getGeneral()->setLanguage(languageList[index].getName());
				delete setting;
			}
			else {
				cout << "This car " << carSetting.sizeTree() + 1 << " data will be appended to your list\n";
				showTimezone();
				cout << "\nEnter number: ";
				index = checkData2((int)timezoneList.size());
				setting->getGeneral()->setTimezone(timezoneList[index].getNumber());
				system("cls");
				showLanguage();
				cout << "\nEnter number: ";
				index = checkData2((int)languageList.size());
				setting->getGeneral()->setLanguage(languageList[index].getName());
				carSetting.insertNode(setting);
			}
		}
		else {
			cout << "This is the first car" << endl;
			showTimezone();
			cout << "\nEnter number: \n";
			index = checkData2((int)timezoneList.size());
			setting->getGeneral()->setTimezone(timezoneList[index].getNumber());
			system("cls");
			showLanguage();
			cout << "\nEnter number: \n";
			index = checkData2((int)languageList.size());
			setting->getGeneral()->setLanguage(languageList[index].getName());
			carSetting.insertNode(setting);
		}
		carSetting.saveDataNode();
		system("cls");
		cout << "CONTINUE TO NUMBER CAR " << carSetting.sizeTree() + 1 << " ? (y/n): ";
		continues = enterYesOrNo();
	} while (continues == "y" || continues == "Y");
}

//show information display
void outputSettingDisplay() {
	int select = 0;
	cout << "selection sort personal key or Name\n"
		<< "1. sort by personal key\n"
		<< "2. sort by name" << endl;
	select = checkData();
	system("cls");
	cout << setw(20) << "Car owner name" << setw(25) << "Email" << setw(20)
		<< "MSCN" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10)
		<< "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
	switch (select)
	{
	case 1: carSetting.inorder(1);
		break;
	case 2:	for (int i = 0; i < carSetting.sortNodeByName().size(); i++) {
		carSetting.sortNodeByName()[i]->data->outputInfor();
		carSetting.sortNodeByName()[i]->data->getDisplay()->outputInforDisplay();
		cout << endl;
	}
		break;
	default:
		cout << "Enter again!!!" << endl;
		outputSettingDisplay();
		break;
	}
	
	
}
// show information sound
void outputSettingSound() {
	int select = 0;
	cout << "selection sort personal key or Name\n"
		<< "1. sort by personal key\n"
		<< "2. sort by name" << endl;
	select = checkData();
	system("cls");
	cout << setw(20) << "Car owner name" << setw(25) << "Email" << setw(20)
		<< "MSCN" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10)
		<< "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10)
		<< "Notify" << endl;
	switch (select)
	{
	case 1: carSetting.inorder(2);
		break;
	case 2:	for (int i = 0; i < carSetting.sortNodeByName().size(); i++) {
		carSetting.sortNodeByName()[i]->data->outputInfor();
		carSetting.sortNodeByName()[i]->data->getSound()->outputInforSound();
		cout << endl;
	}
		  break;
	default:
		cout << "Enter again!!!" << endl;
		outputSettingSound();
		break;
	}
}

// show information general
void outputSettingGeneral() {
	int select = 0;
	cout << "selection sort personal key or Name\n"
		<< "1. sort by personal key\n"
		<< "2. sort by name" << endl;
	select = checkData();
	system("cls");
	cout << setw(20) << "Car owner name" << setw(25) << "Email" << setw(20)
		<< "MSCN" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(15)
		<< "TimeZone" << setw(15) << "Language" << endl;
	switch (select)
	{
	case 1: carSetting.inorder(3);
		break;
	case 2:	for (int i = 0; i < carSetting.sortNodeByName().size(); i++) {
		carSetting.sortNodeByName()[i]->data->outputInfor();
		carSetting.sortNodeByName()[i]->data->getGeneral()->outputInforGeneral();
	}
		  break;
	default:
		cout << "Enter again!!!" << endl;
		outputSettingGeneral();
		break;
	}
}

// show all information
void outputSettingAll() {
	if (carSetting.sizeTree() > 0) {
		system("cls");
		int select = 0;
		string s = "";
		cout << "---Select setting---\n";
		cout << "1. Enter name to show user's data\n"
			<< "2. Enter personal key show get user's data\n";
		select = checkData();
		switch (select) {
		case 1:
			system("cls");
			cout << "Get data by car name\n";
			s = enterName();
			cout << setw(20) << "Car owner name" << setw(25) << "Email" << setw(20) << "MSCN" << setw(10) << "ODO"
				<< setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
				<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
				<< setw(15) << "TimeZone" << setw(10) << "Language" << endl;

			for (int i = 0; i < carSetting.searchNodeByName(s).size(); i++) {
				carSetting.searchNodeByName(s)[i]->data->outputInfor();
				carSetting.searchNodeByName(s)[i]->data->getDisplay()->outputInforDisplay();
				carSetting.searchNodeByName(s)[i]->data->getSound()->outputInforSound();
				carSetting.searchNodeByName(s)[i]->data->getGeneral()->outputInforGeneral();
				cout << endl;
			}
			break;
		case 2:
			system("cls");
			cout << "Get data by personal key\n";
			s = enterKeyNum();
			cout << setw(20) << "Car owner name" << setw(25) << "Email" << setw(20) << "MSCN" << setw(10) << "ODO"
				<< setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
				<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
				<< setw(15) << "TimeZone" << setw(10) << "Language" << endl;
			carSetting.searchNodeByKey(s)->data->outputInfor();
			carSetting.searchNodeByKey(s)->data->getDisplay()->outputInforDisplay();
			carSetting.searchNodeByKey(s)->data->getSound()->outputInforSound();
			carSetting.searchNodeByKey(s)->data->getGeneral()->outputInforGeneral();
			cout << endl;
			break;
		default:
			cout << "Enter again!!!" << endl;
			system("pause");
			outputSettingAll();
			break;
		}
	}
	else {
		cout << "THERE IS NO DATA IN FILE\n";
	}
}

//choose Yes or No when add new car
string enterYesOrNo() {
	regex yon("[y|n|Y|N]{1}");
	while (true)
	{
		string str = "";
		getline(cin, str);
		if (regex_match(str, yon)) {
			return str;
		}else {
				cout << "Please enter yes or no (y/n)!!!\n";
				cout << "enter again: ";
		}
	}
}
// input car name, show information
string enterName() {
	regex regexCarName("([a-zA-Z]+( [a-zA-Z]+)*){1,30}");
	string str = "";
	Setting* setting = new Setting();
	cout << "Enter car name show information: " << endl;
	while (true) {
		cout << "Enter name: ";
		getline(cin, str);
		setting->setCarName(str);
		if (!regex_match(setting->getCarName(), regexCarName)) {
			cout << "car name wrong, ";
		}
		else if (carSetting.searchNodeByName(setting->getCarName()).empty()) {
			cout << "car name wrong" << endl;
		}
		else {
			break;
		}
	}
	return str;
}

//input personal key, show information
string enterKeyNum() {
	regex regexKeyNum("^[0-9]{8}$");
	string str = "";
	Setting* setting = new Setting();
	cout << "Enter personal key of car show information: " << endl;

	while (true) {
		cout << "Enter key number: ";
		getline(cin, str);
		setting->setKeyNum(str);
		if (!regex_match(setting->getKeyNum(), regexKeyNum)) {
			cout << "Please enter 8 digits";
		}
		else if (carSetting.searchNodeByKey(setting->getKeyNum()) == NULL) {
			cout << "Personal key wrong!!!" << endl;
		}
		else {
			break;
		}
	}
	return str;
}
// check data user input from 1 to 9
int checkData3() {
	int n = 0;
	regex num("[1-9]{1}");	// format digit charactter
	string checkUserInput = "";
	bool flag = true;
	do {
		cout << "Your selection: ";
		getline(cin, checkUserInput);
		if (regex_match(checkUserInput, num)) {
				n = stoi(checkUserInput);
		}
		else {
			cout << "Enter Again!!!" << endl;
		}
	} while (!regex_match(checkUserInput, num));
	return n = stoi(checkUserInput);
}
// check data user input from 0 to 9, function one param
int checkData2(int len) {
	int n = 0;
	regex number("[0-9]{1,2}");// format digit charactter
	string s_checkInput = "";
	do {
		getline(cin, s_checkInput);
		if (regex_match(s_checkInput, number) && stoi(s_checkInput) < len)
		{
			n = stoi(s_checkInput);
			
		}
	} while (!regex_match(s_checkInput, number) || stoi(s_checkInput) >= len);
	return n = stoi(s_checkInput);
}

//  separate / print text file
const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;
	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

//download into vector language
void downloadLanguage() {
	string s;
	CommonInfo com;
	vector<string> temp_commoninfo;
	ifstream f("languages.txt");
	try {
		if (f.is_open()) {
			// read data in file
			while (getline(f, s)) {
				temp_commoninfo = explode(s, '/');
				com.setNumber(temp_commoninfo[0]);
				com.setName(temp_commoninfo[1]);
				languageList.push_back(com);
			}
			f.close();
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		// input data in file
		ofstream file1("languages.txt");
		if (file1.is_open()) {
			file1 << "1 / Mandarin (entire branch)" << "\n2 / Spanish" << "\n3 / English" << "\n4 / Hindi" << "\n5 / Arabic" << "\n6 / Portuguese"
				<< "\n7 / Bengali" << "\n8 / Russian" << "\n9 / Japanese" << "\n10 / Punjabi" << "\n11 / German" << "\n12 / Javanese"
				<< "\n13 / Wu (inc. Shanghainese)" << "\n14 / Malay (inc. Indonesian and Malaysian)" << "\n15 / Telugu" << "\n16 / Vietnamese" << "\n17 / Korean" << "\n18 / French"
				<< "\n19 / Marathi" << "\n20 / Tamil" << "\n21 / Urdu" << "\n22 / Turkish" << "\n23 / Italian" << "\n24 / Yue (inc. Cantonese)"
				<< "\n25 / Thai" << "\n26 / Gujarati" << "\n27 / Jin" << "\n28 / Southern Min" << "\n29 / Persian" << "\n30 / Polish";
		}
		file1.close();
		string s;
		CommonInfo com2;
		vector <string> temp_commoninfo2;
		ifstream f2("languages.txt");
		if (f2.is_open()) {
			while (getline(f2, s)) {
				temp_commoninfo2 = explode(s, '/');
				com2.setNumber(temp_commoninfo2[0]);
				com2.setName(temp_commoninfo2[1]);
				timezoneList.push_back(com2);
			}
			f2.close();
		}
		downloadLanguage();
	}


}

// download into vecto timezone
void downloadTimezone() {
	string s;
	CommonInfo com;
	vector<string> temp_commoninfo;
	ifstream f("timezones.txt");
	try {
		if (f.is_open()) {
			while (getline(f, s)) {
				temp_commoninfo = explode(s, '/');
				com.setNumber(temp_commoninfo[0]);
				com.setName(temp_commoninfo[1]);
				timezoneList.push_back(com);
			}
			f.close();
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		ofstream file1("timezones.txt");
		if (file1.is_open()) {
			file1 << "(GMT-12:00) / International Date Line West\n" << "(GMT-11:00) / Midway Island, Samoa\n" << "(GMT-10:00) / Hawaii\n" << "(GMT-09:00) / Alaska\n" << "(GMT-08:00) / Tijuana, Baja California\n" << "(GMT-07:00) / Chihuahua, La Paz, Mazatlan - New\n" << "(GMT-06:00) / Guadalajara, Mexico City, Monterrey - New\n"
				<< "(GMT-05:00) / Eastern Time (US and Canada)\n" << "(GMT-04:00) / Atlantic Time (Canada)\n" << "(GMT-03:30) / Newfoundland\n" << "(GMT-02:00) / Mid-Atlantic\n" << "(GMT-01:00) / Azores\n" << "(GMT-00:00) / Monrovia, Reykjavik\n" << "(GMT+01:00) / Belgrade, Bratislava, Budapest, Ljubljana, Prague\n"
				<< "(GMT+02:00) / Minsk\n" << "(GMT+03:00) / Moscow, St. Petersburg, Volgograd\n" << "(GMT+04:00) / Abu Dhabi, Muscat\n" << "(GMT+04:30) / Kabul\n" << "(GMT+05:00) / Tashkent\n" << "(GMT+05:30) / Chennai, Kolkata, Mumbai, New Delhi\n" << "(GMT+05:45) / Kathmandu\n" << "(GMT+06:00) / Astana, Dhaka\n" << "(GMT+06:30) / Yangon (Rangoon)\n"
				<< "(GMT+07:00) / Bangkok, Hanoi, Jakarta\n" << "(GMT+08:00) / Beijing, Chongqing, Hong Kong, Urumqi\n" << "(GMT+08:00) / Irkutsk, Ulaanbaatar\n" << "(GMT+09:00) / Seoul\n" << "(GMT+09:30) / Adelaide\n" << "(GMT+10:00) / Canberra, Melbourne, Sydney\n" << "(GMT+11:00) / Magadan, Solomon Islands, New Caledonia\n" << "(GMT+12:00) / Fiji, Kamchatka, Marshall Is.\n" << "(GMT+13:00) / Nuku'alofa\n";
		}
		file1.close();
		string s;
		CommonInfo com2;
		vector <string> temp_commoninfo2;
		ifstream f2("timezones.txt");
		if (f2.is_open()) {
			while (getline(f2, s)) {
				temp_commoninfo2 = explode(s, '/');
				com2.setNumber(temp_commoninfo2[0]);
				com2.setName(temp_commoninfo2[1]);
				timezoneList.push_back(com2);
			}
			f2.close();
		}
		downloadTimezone();
	}
}
void loadData() {
	string s;
	ifstream file1("Setting.txt");
	string arrS[13];

	try {
		if (file1.is_open()) {
			while (getline(file1, s)) {
				Setting* temp = new Setting;
				vector<string>vect_s;
				vect_s = explode(s, ';');
				vector<string> vect_common = explode(vect_s[0], ':');
				vector<string>vect_gen = explode(vect_s[1], ':');
				vector<string>vect_sou = explode(vect_s[2], ':');
				vector<string>vect_disp = explode(vect_s[3], ':');
				vector<string>sub_common = explode(vect_common[1], ',');
				vector<string>sub_gen = explode(vect_gen[2], ',');
				vector<string>sub_sou = explode(vect_sou[1], ',');
				vector<string>sub_disp = explode(vect_disp[1], ',');
				temp->setCarName(sub_common[0]);
				temp->setEmail(sub_common[1]);
				temp->setKeyNum(sub_common[2]);
				temp->setODO(stoi(sub_common[3]));
				temp->setRemindService(stoi(sub_common[4]));
				temp->getGeneral()->setTimezone(vect_gen[1] + ":" + sub_gen[0]);
				temp->getGeneral()->setLanguage(sub_gen[1]);
				temp->getSound()->setCallVolumeLevel(stoi(sub_sou[0]));
				temp->getSound()->setMediaVolumeLevel(stoi(sub_sou[1]));
				temp->getSound()->setNavigationVolumeLevel(stoi(sub_sou[2]));
				temp->getSound()->setNotificationVolumeLevel(stoi(sub_sou[3]));
				temp->getDisplay()->setLightLevel(stoi(sub_disp[0]));
				temp->getDisplay()->setScreenLightLevel(stoi(sub_disp[1]));
				temp->getDisplay()->setTaploLightLevel(stoi(sub_disp[2]));
				carSetting.insertNode(temp); // save all infor
			}
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		//cerr << "Unable to open file to read " << "setting.txt" << endl;
	}
}


// sort by name Timezone and Language
bool sortName(CommonInfo& a_str, CommonInfo& b_str) {
	return a_str.getName() < b_str.getName();
}
// show information, user choose
void showTimezone() {
	for (size_t i = 0; i < timezoneList.size(); i++) {
		cout << i << " : " << timezoneList[i].getNumber() << "-" << timezoneList[i].getName() << endl;
	}
}
// show information, user choose
void showLanguage() {
	sort(languageList.begin(), languageList.end(), sortName);
	for (size_t i = 0; i < languageList.size(); i++) {
		cout << i << ":" << languageList[i].getName() << endl;
	}
}
