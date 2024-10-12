#include<iostream>
#include<iomanip>
#include"Car.h"

using namespace std;

int Car::count_ = 0;

Car::Car(string personal_key) :Setting(personal_key) {
	count_++;
	//construct setting of display,sound,general for each car
	display_ = new Display();
	sound_ = new Sound();
	general_ = new General();
}

Car::~Car() {
	//release all the memories
	delete display_;
	delete sound_;
	delete general_;
}

void Car::info() {
	Setting::info();
	getDisplay()->info();
	getSound()->info();
	getGeneral()->info();
}

//Function to display both car information and display setting
void Car::infoDisplay() {
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(10) << display_->getLightLevel()
		<< setw(10) << display_->getLightScreenLevel()
		<< setw(10) << display_->getLightTabloLevel() << endl;
}

//Function to display both car information and sound setting
void Car::infoSound() {
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(10) << sound_->getMediaLevel()
		<< setw(10) << sound_->getCallLevel()
		<< setw(10) << sound_->getNavigationLevel()
		<< setw(10) << sound_->getNotificationLevel() << endl;
}

//Function to display both car information and general setting
void Car::infoGeneral() {
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(10) << general_->getTimezone()
		<< setw(10) << general_->getLanguage() << endl;
}

//Getters
Display* Car::getDisplay() {
	return display_;
}
Sound* Car::getSound() {
	return sound_;
}
General* Car::getGeneral() {
	return general_;
}
int Car::count() {
	return count_;
}
