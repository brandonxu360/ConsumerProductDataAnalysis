/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: bst.hpp
* Date: 4/11/23
* Description: Header file for the BST class, which will be used to create
*			   BSTs containing transaction nodes
*/

#include "transactionnode.hpp"

class BST {

public:

	BST(); // Default constructor
	~BST(); // Destructor - calls destroyTree()

	// Getters
	Node* getPRoot();

	// Setters
	void setPRoot(Node* newPRoot); 

	void insert(std::string data, int units); // Public insert function to hide pointer info
	void inOrderTraversal(); // Public traversal function that uses the private inOrderTraversal
	void findSmallest(); // Calls the private findSmallest function
	void findLargest(); // Calls the private findLargest function


private:

	Node* _pRoot;

	void destroyTree(Node* pT); // Visits each node postOrder and deletes them
	void insert(Node*& pT, std::string data, int units); // Recursively insert into correct subtree based on mUnits
	void inOrderTraversal(Node* pT); // Recursively visits and prints the contents (mDataand mUnits) of each node in the tree in order
	Node* findSmallest(Node* pT); // Recursively finds the smallest node
	Node* findLargest(Node* pT); // Recursively finds the largest node
};