/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: node.cpp
* Date: 4/11/23
* Description: Source file for the Node base/abstract class, which will be be inherited by the TransactionNode class
*/

#include "node.hpp"

// Constructor which accepts a string to set the data in the node
Node::Node(std::string data) {

	_data = data;
	_pLeft = nullptr;
	_pRight = nullptr;

}

// Virtual destructor
Node::~Node() {

}

// Setters
void Node::setData(std::string data) {
	_data = data;
}

void Node::setPLeft(Node* newPLeft) {
	_pLeft = newPLeft;
}

void Node::setPRight(Node* newPRight) {
	_pRight = newPRight;
}

// Getters
std::string Node::getData() const {
	return _data;
}

Node*& Node::getPLeft() {
	return _pLeft;
}

Node*& Node::getPRight() {
	return _pRight;
}


