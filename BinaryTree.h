#pragma once
#include "NodeLibrary.h"
#include<queue>

using std::endl;
using std::cout;
using std::cin;
using std::queue;
using std::make_shared;

class binaryTree
{
private:
	  shared_ptr<node> root;
	  shared_ptr<node> actual;
	  bool dataIsFound;
	  int searchedNumber;
public:
	void insertNode();
	void insertNodeParam(int nodeToBeInserted);
	void searchNode(shared_ptr<node> nodeToBeSearched);
	void deleteMinimumNode();
	void printBinaryTree_preorder(shared_ptr<node> actual);
	void printBinaryTree_inorder(shared_ptr<node> actual);
	void printBinaryTree_postorder(shared_ptr<node> actual);
	void printBinaryTree_Breadth_first(shared_ptr<node> actual);
	shared_ptr<node> deleteNode(shared_ptr<node> actual);

	shared_ptr<node> searchMinimum(shared_ptr<node>);
	shared_ptr<node> getRoot() { return this->root; }

	//for seach function to be implemented:
	void setSearchedNumber(int searchedNum) { this->searchedNumber = searchedNum; }
	int getSearchedNumber() { return this->searchedNumber; }
	void setDataIsFound()   { this->dataIsFound = true; }
	void resetDataIsFound() { this->dataIsFound = false; }
	bool getDataIsFound()   { return dataIsFound; }

	binaryTree()
	{
		this->searchedNumber = 0;
		this->dataIsFound = false;
		this->root = nullptr;
		this->actual = nullptr;
	}
};