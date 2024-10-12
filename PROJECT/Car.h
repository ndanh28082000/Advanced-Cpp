#ifndef CAR_H_
#define CAR_H_

#include<string>
#include"Setting.h"
#include"Display.h"
#include"Sound.h"
#include"General.h"

using namespace std;

//class to manage all data of a car
class Car :public Setting {
public:
	//every car must have personal key to distinguish
	Car(string personal_key);
	~Car();
	void info();
	void infoSound();
	void infoDisplay();
	void infoGeneral();
	Display* getDisplay();
	Sound* getSound();
	General* getGeneral();

	//function to count the numbers of car
	static int count();
private:
	Display* display_;
	Sound* sound_;
	General* general_;
	//save the numbers of car
	static int count_;
};


#endif // !CAR_H_

