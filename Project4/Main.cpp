#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<regex>

#include"Car.h"
#include"BST.h"

using namespace std;

BST btree;

void menu();
void menu2();
void menu3();

unsigned int inputSelection(unsigned int num_of_choices);
bool YNQuestion();
string inputPersonalKey();

void inputDisplay();
void inputGeneral();
void inputSound();

Car* inputDataCar();

void printDisplay();
void printGeneral();
void printSound();
void printAllSetting();

int main() {
	General::downloadLanguage("languages.txt");
	General::downloadTimezone("timezones.txt");
	btree.readDataFromFile("Setting.txt");
	menu();
	return 0;
}

/*
Display menu screen and meet its requirements
*/
void menu() {
	system("cls");
	cout << "--- SELECT MENU ---\n";
	cout << "1. Input setting information\n";
	cout << "2. Print setting information\n";
	cout << "3. Exit\n";
	// input selection
	switch (inputSelection(3)) {
	case 1:
		system("cls");
		menu2();
		break;
	case 2:
		system("cls");
		menu3();
		break;
	case 3:
		system("cls");
		cout << "--- GOODBYE! SEE YOU LATER ---";
		exit(0); //End the project
		break;
	}
}
void menu2() {
	cout << "--- SELECT MENU ---\n";
	cout << "1. Display setting\n";
	cout << "2. Sound setting\n";
	cout << "3. General setting\n";
	cout << "4. Exit\n";
	//input selection
	switch (inputSelection(4)) {
	case 1:
		inputDisplay();
		break;
	case 2:
		inputSound();
		break;
	case 3:
		inputGeneral();
		break;
	case 4:
		menu();
		break;
	}
}
void menu3() {
	cout << "--- SELECT MENU ---\n";
	cout << "1. Print Display setting information\n";
	cout << "2. Print Sound setting information\n";
	cout << "3. Print General setting information\n";
	cout << "4. Print All setting information\n";
	cout << "5. Exit\n";
	//input selection 
	switch (inputSelection(5)) {
	case 1:
		system("cls");
		cout << "--- Display setting ---\n";
		printDisplay();
		system("pause");
		menu3();
		break;
	case 2:
		system("cls");
		cout << "--- Sound setting ---\n";
		printSound();
		system("pause");
		menu3();
		break;
	case 3:
		system("cls");
		cout << "--- General setting ---\n";
		printGeneral();
		system("pause");
		menu3();
		break;
	case 4:
		system("cls");
		cout << "--- All setting ---\n";
		printAllSetting();
		system("pause");
		menu3();
		break;
	case 5:
		menu();
		break;
	}
}

/*
require user input selection and check it
@param num_of_choices total of choices
@return user's choice
*/
unsigned int inputSelection(unsigned int num_of_choices) {
	string selection = "";
	while (true) {
		cout << "Your selection: ";
		getline(cin, selection);
		//check if the selection is in the range 1-num_of_choices
		if (regex_match(selection, regex("[1-" + to_string(num_of_choices) + "]"))) {
			return stoi(selection);
		}
		else {
			cout << "  *Invalid!";
		}
	}
}

bool YNQuestion() {
	string temp = "";
	while (true) {
		cout << "Your selection: ";
		getline(cin, temp);
		if (temp == "y" || temp == "Y") {
			return true;
		}
		else if (temp == "n" || temp == "N") {
			return false;
		}
		else {
			cout << "  *Invalid! Please input your selection again";
		}
	}
}

string inputPersonalKey()
{
	//input and check personal key
	string key_number = "";
	cout << "   Key number: ";
	getline(cin, key_number);
	while (!Car::checkPersonalKey(key_number))
	{
		cout << "     * Invalid! Key number: ";
		getline(cin, key_number);
	}
	return key_number;
}

void inputDisplay() {
	while (true) {
		system("cls");
		cout << "--- Input Display Setting ---\n";
		//input data of car
		cout << "Data car:" << endl;
		Car* car = inputDataCar();
		//input setting of display
		cout << "Display Setting: " << endl;
		car->getDisplay()->input();

		//show data of Display setting
		system("cls");
		cout << "--- Input Display Setting ---\n";
		car->Setting::info();
		car->getDisplay()->info();

		//update Display setting data to the file
		btree.writeDataToFile("Setting.txt");

		cout << "Will you input for next car? (y/n)" << endl;
		if (!YNQuestion()) {
			//back to screen 1
			break;
		}
	}
	menu();
}

void inputGeneral() {
	while (true)
	{
		system("cls");
		cout << "--- Input General Setting ---\n";
		//input data car 
		cout << "Data car:" << endl;
		Car* car = inputDataCar();
		system("pause");
		//input setting of general 
		cout << "General Setting: " << endl;
		car->getGeneral()->input();

		//show data of general setting
		system("cls");
		cout << "--- Input General Setting ---\n";
		car->Setting::info();
		car->getGeneral()->info();

		//update Display setting data to the file
		btree.writeDataToFile("Setting.txt");

		cout << "Will you input for next car? (y/n)" << endl;
		if (!YNQuestion()) {
			//back to screen 1
			break;
		}
	}
	menu();
}

void inputSound() {
	while (true) {
		system("cls");
		cout << "--- Input Sound Setting ---\n";
		//input data car
		cout << "Data car:" << endl;
		Car* car = inputDataCar();
		//input setting of sound
		cout << "Sound Setting: " << endl;
		car->getSound()->input();

		//show data of sound setting
		system("cls");
		cout << "--- Input Sound Setting ---\n";
		car->Setting::info();
		car->getSound()->info();

		//update Display setting data to the file
		btree.writeDataToFile("Setting.txt");

		cout << "Will you input for next car? (y/n)" << endl;
		if (!YNQuestion()) {
			//back to screen 1
			break;
		}
	}
	menu();
}

Car* inputDataCar() {
	string key_number = inputPersonalKey();
	// Find the location of car in BST
	Node* res = btree.searchByKey(key_number);
	string msg = "";
	if (res != NULL)
	{
		msg = "--> This car has already existed, data will be overwriten";
	}
	else
	{
		msg = "--> This is a new car, data will be appended to your list";
		res = btree.insert(new Car(key_number));
	}
	// input other data
	// update data for car that has already existed or input data for new car
	res->data->inputData();
	cout << msg << endl;
	return res->data;
}

void printDisplay() {
	system("cls");
	cout << "--- Display Setting ---\n";
	string key_number = inputPersonalKey();
	Node* node = btree.searchByKey(key_number);
	if (node != NULL) {
		system("cls");
		cout << "--- Display Setting ---\n";
		cout << left;
		cout << setw(20) << "Owner name"
			<< setw(25) << "Email"
			<< setw(15) << "Key"
			<< setw(10) << "ODO"
			<< setw(15) << "Serrvice (km)"
			<< setw(10) << "Light"
			<< setw(10) << "Screen"
			<< setw(10) << "Taplo" << endl;
		node->data->infoDisplay();
	}
	else {
		cout << "This car does not existed!" << endl;
	}
}
void printGeneral() {
	system("cls");
	cout << "--- General Setting ---\n";
	string key_number = inputPersonalKey();
	Node* node = btree.searchByKey(key_number);
	if (node != NULL) {
		system("cls");
		cout << "--- General Setting ---\n";
		cout << left;
		cout << setw(20) << "Owner name"
			<< setw(25) << "Email"
			<< setw(15) << "Key"
			<< setw(10) << "ODO"
			<< setw(15) << "Serrvice (km)"
			<< setw(10) << "TimeZone"
			<< setw(10) << "Language" << endl;
		node->data->infoGeneral();
	}
	else {
		cout << "This car does not existed!" << endl;
	}
}
void printSound() {
	system("cls");
	cout << "--- Sound Setting ---\n";
	string key_number = inputPersonalKey();
	Node* node = btree.searchByKey(key_number);
	if (node != NULL) {
		system("cls");
		cout << "--- Sound Setting ---\n";
		cout << left;
		cout << setw(20) << "Owner name"
			<< setw(25) << "Email"
			<< setw(15) << "Key"
			<< setw(10) << "ODO"
			<< setw(15) << "Serrvice (km)"
			<< setw(10) << "Media"
			<< setw(10) << "Call"
			<< setw(10) << "Navigation"
			<< setw(10) << "Notification" << endl;
		node->data->infoSound();
	}
	else {
		cout << "This car does not existed!" << endl;
	}
}
void printAllSetting() {
	system("cls");
	cout << "--- All Setting ---" << endl;
	//display all search selections
	cout << "1.Search by Personal key" << endl;
	cout << "2.Search by Owner name" << endl;
	if (inputSelection(2) == 1) {
		system("cls");
		cout << "--- All Setting ---" << endl;
		//input and find personal key
		string key_number = inputPersonalKey();
		Node* node = btree.searchByKey(key_number);
		if (node != NULL) {
			system("cls");
			cout << "--- All Setting ---" << endl;
			node->data->info();
		}
		else {
			cout << "  --> This car does not exist!" << endl;
		}
	}
	else {
		system("cls");
		cout << "--- All Setting ---" << endl;
		//input and find owner name
		string owner_name = "";
		cout << "  Owner name: ";
		getline(cin, owner_name);
		while (!Car::checkOwnerName(owner_name)){
			cout << "     * Invalid! Owner name: ";
			getline(cin, owner_name);
		}
		int count_ = 0;
		btree.searchByName(owner_name, count_);
		if (count_ == 0) {
			cout<< "  --> This car does not exist!" << endl;
		}
	}
}
