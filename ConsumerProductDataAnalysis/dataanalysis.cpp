/*
* Name: Brandon Xu
* Project: ConsumerProductDataAnalysis
* File: dataanalysis.cpp
* Date: 4/11/23
* Description: Source file for the DataAnalysis class, which will wrap the rest
*			   of the classes into a cohesive application
*/

#include "dataanalysis.hpp"

void DataAnalysis::runAnalysis() {
    openFile();
    readLine();
    displayTrends();

    // Debug code
    /*mTreePurchased.inOrderTraversal();
    std::cout << std::endl;
    mTreeSold.inOrderTraversal();*/
}

void DataAnalysis::openFile() {
    mCsvStream.open("data.csv");
    if (!mCsvStream.is_open()) {
        std::cerr << "Failed to open data file!" << std::endl;
        exit(1);
    }
}

void DataAnalysis::readLine() {
    std::string line;
    std::getline(mCsvStream, line); // Skip the first line
    while (std::getline(mCsvStream, line)) {
        std::stringstream ss(line);
        std::string unitsStr, type, transaction;
        std::getline(ss, unitsStr, ',');
        std::getline(ss, type, ',');
        std::getline(ss, transaction, ',');
        int units = std::stoi(unitsStr);
        // std::cout << unitsStr << " " << type << " " << transaction << std::endl;
        insertTransaction(type, units, transaction);
    }
}

void DataAnalysis::insertTransaction(const std::string& type, int units, const std::string& transaction) {
    if (transaction == "Sold") {
        mTreeSold.insert(type, units);
    }
    else if (transaction == "Purchased") {
        mTreePurchased.insert(type, units);
    }
}

void DataAnalysis::displayTrends() {
    std::cout << "Sold Tree:" << std::endl;
    displayMinMax(mTreeSold);
    std::cout << std::endl << "Purchased Tree:" << std::endl;
    displayMinMax(mTreePurchased);
}

void DataAnalysis::displayMinMax(BST& tree) {
    if (tree.getPRoot() == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }
    std::cout << "Smallest:";
    tree.findSmallest();

    std::cout << "Largest:";
    tree.findLargest();

}