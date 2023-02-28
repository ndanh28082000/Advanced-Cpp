#include<iostream>
#include<iomanip>
#include"Display.h"
#include"Setting.h"

using namespace std;

void Display::info() {
	cout << left;
	cout << "    "
		<< setw(15) << "Display:"
		<< setw(20) << "Light"
		<< setw(20) << "Screen light"
		<< setw(20) << "Taplo light" << endl;
	cout << "    "
		<< setw(15) << ""
		<< setw(20) << light_level_
		<< setw(20) << light_screen_level_
		<< setw(20) << light_tablo_level_ << endl;
}
void Display::input() {
	light_level_ = Setting::InputLevelNumber("Light level");
	light_screen_level_ = Setting::InputLevelNumber("Screen light level");
	light_tablo_level_ = Setting::InputLevelNumber("Tablo light level");
}

//Getters
unsigned int Display::getLightLevel() {
	return light_level_;
}
unsigned int Display::getLightScreenLevel() {
	return light_screen_level_;
}
unsigned int Display::getLightTabloLevel() {
	return light_tablo_level_;
}

//Setters
void Display::setLightLevel(unsigned int light_level) {
	light_level_ = light_level;
}
void Display::setLightScreenLevel(unsigned int light_screen_level) {
	light_screen_level_ = light_screen_level;
}
void Display::setLightTabloLevel(unsigned int light_tablo_level) {
	light_tablo_level_ = light_tablo_level;
}