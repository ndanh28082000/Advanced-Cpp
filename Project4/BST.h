#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Car.h"

using namespace std;

//struct to control a node in BST(binary search tree)
struct Node {
	Car* data;
	Node* left;
	Node* right;
	Node(Car* car);
};

//class to control the BST-save the data of cars
class BST {
private:
	Node* root_;
	Node* insert(Car* car, Node* node);
	Node* searchByKey(string key, Node* node);
    void searchByName(string name, Node* node, int &count_);
	void writeDataToFile(ofstream& file, Node* node);
	void inOrder(Node* node);
public:
	BST();
	Node* insert(Car* car);
	Node* searchByKey(string key);
	void searchByName(string name, int &count_);
	void writeDataToFile(string file_path);
	void readDataFromFile(string file_path);
	void inOrder();
};

#endif // !BST_H
