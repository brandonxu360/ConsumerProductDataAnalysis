/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: transactionnode.hpp
* Date: 4/11/23
* Description: Header file for the TransactionNode derived class, which inherits from abstract 
*			   base class Node
*/

#include "node.hpp"

class TransactionNode : public Node {

public:
	
	// Constructor that invokes Node constructor
	TransactionNode(std::string data, int numUnits);
	~TransactionNode(); // Destructor

	void setNumUnits(int units); // Setter
	int getNumUnits(); // Getter

	void printData(); // Overriden Node function to print data

private:

	int _numUnits;
};
