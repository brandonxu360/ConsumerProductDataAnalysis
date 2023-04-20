/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: transactionnode.cpp
* Date: 4/11/23
* Description: Source file for the TransactionNode derived class, which inherits from abstract
*			   base class Node
*/

#include "transactionnode.hpp"

// Constructor that invokes Node constructor
TransactionNode::TransactionNode(const std::string data, int units)
    : Node(data), _numUnits(units)
{
    // Body of constructor is empty since base class constructor already sets left and right pointers to null
}

//Destructor
TransactionNode::~TransactionNode() {
    // Empty body
}

// Setter
void TransactionNode::setNumUnits(int units) {
    _numUnits = units;
}

// Getter
int TransactionNode::getNumUnits() {
    return _numUnits;
}

// Overriden Node function to print data
void TransactionNode::printData() {
    std::cout << "[Data: " << _data << " Units: " << _numUnits << "]" << std::endl;
}


