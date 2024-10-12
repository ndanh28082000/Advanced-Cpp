#include<iostream>
#include"BST.h"

using namespace std;

Node::Node(Car* car) {
	data = car;
	left = NULL;
	right = NULL;
}
Node* BST::insert(Car* car, Node* node) {
	if (car->getPersonalKey() < node->data->getPersonalKey()) {
		if (node->left != NULL) {
			return insert(car, node->left);
		}
		else {
			node->left = new Node(car);
			return node->left;
		}
	}
	else {
		if (node->right != NULL) {
			return insert(car, node->right);;
		}
		else{
			node->right = new Node(car);
			return node->right;
		}
	}
}
Node* BST::searchByKey(string key, Node* node) {
	if (node != NULL) {
		if (key == node->data->getPersonalKey()) {
			return node;
		}
		if (key < node->data->getPersonalKey()) {
			return searchByKey(key, node->left);
		}
		else {
			return searchByKey(key, node->right);
		}
	}
	else {
		return NULL;
	}
}
void BST::searchByName(string name, Node* node, int &count_) {
	if (node == NULL) {
		return;
	}
	searchByName(name, node->left, count_);
	if (name == node->data->getOwnerName()) {
		count_++;
		cout << count_;
		node->data->info();
	}
	searchByName(name, node->right, count_);
}
void BST::writeDataToFile(ofstream& file, Node* node) {
	if (node != NULL)
	{
		if (node != root_)
			file << endl;
		Car* car = node->data;
		file << "Common: "
			<< car->getPersonalKey() << ","
			<< car->getOwnerName() << ","
			<< car->getEmail() << ","
			<< car->getODO() << ","
			<< car->getRemindService() << "; ";
		Display* display = car->getDisplay();
		file << "Display: "
			<< display->getLightLevel() << ","
			<< display->getLightScreenLevel() << ","
			<< display->getLightTabloLevel() << "; ";
		Sound* sound = car->getSound();
		file << "Sound: "
			<< sound->getMediaLevel() << ","
			<< sound->getCallLevel() << ","
			<< sound->getNavigationLevel() << ","
			<< sound->getNotificationLevel() << "; ";
		General* general = car->getGeneral();
		file << "General: "
			<< general->getTimezone() << ","
			<< general->getLanguage();
		writeDataToFile(file, node->left);
		writeDataToFile(file, node->right);
	}
}
void BST::inOrder(Node* node) {
	if (node != NULL) {
		inOrder(node->left);
		cout << "***************************************************************************************************" << endl;
		node->data->info();
		inOrder(node->right);
	}
}
BST::BST() {
	root_ = NULL;
}
Node* BST::insert(Car* car) {
	if (root_ != NULL) {
		return insert(car, root_);
	}
	else {
		root_ = new Node(car);
		return root_;
	}
}
Node* BST::searchByKey(string key) {
	return searchByKey(key, root_);
}
void BST::searchByName(string name, int &count_) {
	searchByName(name, root_, count_);
}
void BST::writeDataToFile(string file_path) {
	//open file, delete all data and then write again
	//if there are not file, we will construct it
	ofstream file;
	file.exceptions(ofstream::failbit | ofstream::badbit);
	try {
		file.open(file_path, ios::out | ios::trunc);
		writeDataToFile(file, root_);
	}
	catch (const ofstream::failure& e) {
		cout << "--> Failed to write data to the file - " << e.what() << endl;
		system("pause");
	}
	catch (...) {
		cout << "--> Failed to write data to the file - " << endl;
		system("pause");
	}
}
void BST::readDataFromFile(string file_path)
{
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		file.open(file_path);
		string temp = "";
		while (!file.eof())
		{
			getline(file, temp, ' ');
			if (temp == "Common:")
			{
				// Personal key
				getline(file, temp, ',');
				Node* node = insert(new Car(temp));
				// Owner name
				getline(file, temp, ',');
				node->data->setOwnerName(temp);
				// Email
				getline(file, temp, ',');
				node->data->setEmail(temp);
				// ODO
				getline(file, temp, ',');
				node->data->setODO(temp);
				// Remind service
				getline(file, temp, ';');
				node->data->setRemindService(temp);

				// DISPLAY
				Display* display = node->data->getDisplay();
				file.seekg(10, ios::cur);
				getline(file, temp, ',');
				display->setLightLevel(stoi(temp));
				getline(file, temp, ',');
				display->setLightScreenLevel(stoi(temp));
				getline(file, temp, ';');
				display->setLightTabloLevel(stoi(temp));

				//SOUND
				Sound* sound = node->data->getSound();
				file.seekg(8, ios::cur);
				getline(file, temp, ',');
				sound->setMediaLevel(stoi(temp));
				getline(file, temp, ',');
				sound->setCallLevel(stoi(temp));
				getline(file, temp, ',');
				sound->setNavigationLevel(stoi(temp));
				getline(file, temp, ';');
				sound->setNotificationLevel(stoi(temp));

				//GENERAL
				General* general = node->data->getGeneral();
				file.seekg(10, ios::cur);
				getline(file, temp, ',');
				general->setTimezone(temp);
				getline(file, temp);
				general->setLanguage(temp);
			}
		}
	}
	catch (const ifstream::failure& e)
	{
		cout << "--> Failed to read data from the file - " << e.what() << endl;
		system("pause");
	}
	catch (...)
	{
		cout << "--> Failed to read data from the file" << endl;
		system("pause");
	}
}
void BST::inOrder()
{
	inOrder(root_);
}