#include"Setting.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<regex>

using namespace std;

//constructors
Setting::Setting(string personal_key) {
	personal_key_ = personal_key;
	owner_name_ = "";
	email_ = "";
	odo_number_ = 0;
	remind_service_ = 0;
}

// Function to show information of car
void Setting::info() {
	cout << left;
	cout << "    "
		<< setw(20) << "Owner name"
		<< setw(25) << "Email"
		<< setw(15) << "Personal key"
		<< setw(15) << "ODO number"
		<< setw(15) << "Remind service (km)" << endl;
	cout << "    "
		<< setw(20) << owner_name_
		<< setw(25) << email_
		<< setw(15) << personal_key_
		<< setw(15) << odo_number_
		<< setw(15) << remind_service_ << endl;
}

void Setting::inputData() {
	string owner_name;
	string email;
	string odo_str;
	string remind_service_str;

	//input and check the form owner name
	cout << "   Owner name: ";
	getline(cin, owner_name);
	while (!setOwnerName(owner_name)) {
		cout << "   *Invalid! Owner name: ";
		getline(cin, owner_name);
	}
	//input and check the form of email
	cout << "   Email: ";
	getline(cin, email);
	while (!setEmail(email)) {
		cout << "   *Invalid! Email: ";
		getline(cin, email);
	}
	//input and check the odo number
	cout << "   ODO number: ";
	getline(cin, odo_str);
	while (!setODO(odo_str)) {
		cout << "   *Invalid! ODO number: ";
		getline(cin, odo_str);
	}
	//input and check the remind service
	cout << "   Remind service: ";
	getline(cin, remind_service_str);
	while (!setRemindService(remind_service_str)) {
		cout << "   *Invalid! Remind service: ";
		getline(cin, remind_service_str);
	}
}

//Setters
bool Setting::setOwnerName(string owner_name) {
	if (checkOwnerName(owner_name)) {
		owner_name_ = owner_name;
		return true;
	}
	return false;
}
bool Setting::setEmail(string email) {
	if (checkEmail(email)) {
		email_ = email;
		return true;
	}
	return false;
}
bool Setting::setODO(string odo_str) {
	if (checkUnsignedInteger(odo_str)) {
		odo_number_ = stoi(odo_str);
		return true;
	}
	return false;
}
bool Setting::setRemindService(string remind_service_str) {
	if (checkUnsignedInteger(remind_service_str)) {
		remind_service_ = stoi(remind_service_str);
		return true;
	}
	return false;
}
void Setting::setODO(unsigned int odo_number) {
	odo_number_ = odo_number;
}
void Setting::setRemindService(unsigned int remind_service) {
	remind_service_ = remind_service;
}

//Getters
string Setting::getPersonalKey() {
	return personal_key_;
}
string Setting::getOwnerName() {
	return owner_name_;
}
string Setting::getEmail() {
	return email_;
}
int Setting::getODO() {
	return odo_number_;
}
int Setting::getRemindService() {
	return remind_service_;
}

bool Setting::checkOwnerName(string& owner_name) {
	//uppercase owner name string
	for (size_t i = 0; i < owner_name.length(); i++)
	{
		owner_name[i] = toupper(owner_name[i]);
	}
	//check the form owner name
	if (regex_match(owner_name, regex("[A-Z]+( ?[A-Z]+)*"))) return true;
	return false;
}
bool Setting::checkEmail(string email) {
	//check the form of email:abc@xyz.def
	if (regex_match(email, regex("[a-z0-9]{3,}@[a-z0-9]{3,}(\.[a-z0-9]{3,}){1,2}")))return true;
	return false;
}
bool Setting::checkPersonalKey(string personal_key) {
	//Personal key is a number that just only have 8 digits
	if (regex_match(personal_key, regex("[0-9]{8}"))) return true;
	return false;
}
bool Setting::checkUnsignedInteger(string str) {
	//check the string just contain unsigned integer
	if (regex_match(str, regex("[0-9]+"))) return true;
	return false;
}

int Setting::InputLevelNumber(string data_name) {
	string level_number = "";
	cout << "The level of " << data_name << " :";
	getline(cin, level_number);
	while (!checkUnsignedInteger(level_number)) {
		cout << " *Invalid! The level of " << data_name << " :";
		getline(cin, level_number);
	}
	return stoi(level_number);
}