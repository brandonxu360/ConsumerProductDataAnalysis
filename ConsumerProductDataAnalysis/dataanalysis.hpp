/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: dataanalysis.hpp
* Date: 4/11/23
* Description: Header file for the DataAnalysis class, which will wrap the rest
*			   of the classes into a cohesive application
*/

#include "bst.hpp"

class DataAnalysis {

public:

	void runAnalysis();

private:

	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	void openFile();
	void readLine();
	void insertTransaction(const std::string& type, int units, const std::string& transaction);
	void displayTrends();
	void displayMinMax(BST& tree);
};