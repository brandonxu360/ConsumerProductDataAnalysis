/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: bst.hpp
* Date: 4/11/23
* Description: Source file for the BST class, which will be used to create
*			   BSTs containing transaction nodes
*/

#include "bst.hpp"

// Default constructor
BST::BST() {

	_pRoot = nullptr;

}

// Destructor - calls destroyTree()
BST::~BST() {

	destroyTree(_pRoot);

}

// Getter
Node* BST::getPRoot() {

	return _pRoot;

}

// Setter
void BST::setPRoot(Node* newPRoot) {

	_pRoot = newPRoot;

}

// Public insert function to hide pointer info
void BST::insert(std::string data, int units) {

	insert(_pRoot, data, units);

}

// Public traversal function that uses the private inOrderTraversal
void BST::inOrderTraversal()
{
    inOrderTraversal(_pRoot);
}

// Calls the private findSmallest function
void BST::findSmallest()
{
    findSmallest(_pRoot)->printData();
}

// Calls the private findLargest function
void BST::findLargest()
{
    findLargest(_pRoot)->printData();
}

// Visits each node postOrder and deletes them
void BST::destroyTree(Node* pT) {
    if (pT != nullptr) {
        destroyTree(pT->getPLeft());
        destroyTree(pT->getPRight());
    }
}

// Recursively insert into correct subtree based on mUnits
void BST::insert(Node*& pT, std::string data, int units) {

    if (pT == nullptr) { // Base case
        pT = new TransactionNode(data, units);
    }

    else if (auto pTransactionNode = dynamic_cast<TransactionNode*>(pT)) {
        if (units < pTransactionNode->getNumUnits()) {
            insert(pTransactionNode->getPLeft(), data, units);
        }
        else {
            insert(pTransactionNode->getPRight(), data, units);
        }
    }
}

// recursively visits and prints the contents (mDataand mUnits) of each node in the tree in order
void BST::inOrderTraversal(Node* pT)
{
    if (pT != nullptr) {
        inOrderTraversal(pT->getPLeft());
        pT->printData();
        inOrderTraversal(pT->getPRight());
    }
}

// Recursively finds the smallest node
Node* BST::findSmallest(Node* pT) {
    if (pT == nullptr || pT->getPLeft() == nullptr) {
        return pT;
    }
    else {
        return findSmallest(pT->getPLeft());
    }
}

// Recursively finds the largest node
Node* BST::findLargest(Node* pT) {
    if (pT == nullptr || pT->getPRight() == nullptr) {
        return pT;
    }
    else {
        return findLargest(pT->getPRight());
    }
}