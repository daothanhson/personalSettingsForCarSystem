
#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<string>
using namespace std;

class Car
{
public:
	Car();
	~Car();
	virtual void inputInfor() = 0;
	virtual void outputInfor() = 0;
	void setCarName(string data);
	void setEmail(string data);
	void setKeyNum(string data);
	void setODO(int data);
	void setRemindService(int data);
	string getCarName();
	string getEmail();
	string getKeyNum();
	int getODO();
	int getRemindService();
private:
	string carName;
	string email;
	string keyNum;
	int ODO;
	int remindService;
};
#endif // !CAR_H


