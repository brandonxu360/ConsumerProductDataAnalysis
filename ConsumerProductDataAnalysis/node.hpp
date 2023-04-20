/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: node.hpp
* Date: 4/11/23
* Description: Header file for the Node base/abstract class, which will be be inherited by the TransactionNode class
*/

#include "header.hpp"

class Node {

// Protected data members
protected:

	std::string _data;
	Node* _pLeft;
	Node* _pRight;

// Member functions
public:
	
	Node(std::string data); // Constructor which accepts a string to set the data in the node
	virtual ~Node(); // Virtual destructor 

	// Setters
	void setData(std::string data);
	void setPLeft(Node* newPLeft);
	void setPRight(Node* newPRight);

	// Getters
	std::string getData() const;
	Node*& getPLeft();
	Node*& getPRight();

	virtual void printData() = 0; // Pure virtual function

};

