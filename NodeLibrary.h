//evitam includerea bibliotecilor de mai multe ori
#pragma once
#include <iostream>
#include<string>
#include<memory>

using std::shared_ptr;

class node
{
private:
	int data;

	shared_ptr<node> left;
	shared_ptr<node> right;
public:
	int getData();
	void setData(int newData);

	shared_ptr<node> getLeft();
	shared_ptr<node> getRight();

	void setLeft(shared_ptr<node> newLeftNode);
	void setRight(shared_ptr<node> newRightNode);
	
	shared_ptr<node> returnTheRightNode(shared_ptr<node> actual) { return actual->getRight(); }
	shared_ptr<node> returnTheLeftNode(shared_ptr<node> actual) { return actual->getLeft(); }
	
	node()
	{
        this->data = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};