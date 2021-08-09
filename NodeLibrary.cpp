#include "NodeLibrary.h"

int node::getData()
{
	return this->data;
}

void node::setData(int newData)
{
	this->data = newData;
}

shared_ptr<node> node::getLeft()
{
	return this->left;
}

shared_ptr<node> node::getRight()
{
	return this->right;
}

void node::setLeft(shared_ptr<node> newLeftNode)
{
	this->left = newLeftNode;
}

void node::setRight(shared_ptr<node> newRightNode)
{
	this->right = newRightNode;
}