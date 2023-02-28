#include<iostream>
#include<iomanip>
#include"Sound.h"
#include"Setting.h"

using namespace std;

void Sound::info() {
	cout << left;
	cout << "    "
		<< setw(15) << "Sound"
		<< setw(20) << "Media"
		<< setw(20) << "Call"
		<< setw(20) << "Navigation"
		<< setw(20) << "Notification" << endl;
	cout << "    "
		<< setw(15) << ""
		<< setw(20) << media_level_
		<< setw(20) << call_level_
		<< setw(20) << navigation_level_
		<< setw(20) << notification_level_ << endl;
}
void Sound::input() {
	media_level_ = Setting::InputLevelNumber("Media volume level");
	call_level_ = Setting::InputLevelNumber("Call volume level");
	navigation_level_ = Setting::InputLevelNumber("Navigation volume level");
	notification_level_ = Setting::InputLevelNumber("Notification volume level");
}

//Getters
unsigned int Sound::getCallLevel() {
	return call_level_;
}
unsigned int Sound::getMediaLevel() {
	return media_level_;
}
unsigned int Sound::getNavigationLevel() {
	return navigation_level_;
}
unsigned int Sound::getNotificationLevel() {
	return notification_level_;
}

//Setters
void Sound::setCallLevel(unsigned int call_level) {
	call_level_ = call_level;
}
void Sound::setMediaLevel(unsigned int media_level) {
	media_level_ = media_level;
}
void Sound::setNavigationLevel(unsigned int navigation_level) {
	navigation_level_ = navigation_level;
}
void Sound::setNotificationLevel(unsigned int notification_level) {
	notification_level_ = notification_level;
}
