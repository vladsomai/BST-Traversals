#include "BinaryTree.h"
/*
* This function uses std::queue, the function starts with the root and nullptr in the queue(first level of the tree)
* 
* Steps:
* 1. Pulls the head of the queue in "actual";
* 2. Delete the queue head(pop)
* 3. Check if "actual" is nullptr(true: print the node and add the children in the queue, false: increment level)
* 4. Finish when the queue is empty
*/
void binaryTree::printBinaryTree_Breadth_first(shared_ptr<node> actual)
{
	int level{1};

	if (this->root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return;
	}
	else
	{
		queue< shared_ptr<node> > que;

	    //Start
		que.push(this->root);
		que.push(nullptr);
		cout << "Level " << level << ": ";
		level++;

		while (true)
		{
			//Step 1
			this->actual = que.front();

			//Step 2
			que.pop();

			//Step 3
			if (this->actual != nullptr)
			{
				//print the actual node
				cout << this->actual->getData() << ' ';

				//add the children on the queue
				if (this->actual->getLeft() != nullptr)
				{
					que.push(this->actual->getLeft());
				}

				if (this->actual->getRight() != nullptr)
				{
					que.push(this->actual->getRight());
				}
			}
			else
			{
				//Step 4
				if (que.empty())
				{
					break;
				}

				cout << endl;
				cout << "Level " << level << ": ";

				//Delimiter of the Tree level.
				que.push(nullptr);

				//Increment level
				level++;
			}
		}
	}
}

void binaryTree::printBinaryTree_preorder(shared_ptr<node> actual)
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return;
	}
	else
	{
		if (this->root == actual)
		{
			cout << "R: " << actual->getData() << "\t";
		}

		if (actual->getLeft() != nullptr)
		{
			this->printBinaryTree_preorder(actual->getLeft());
		}

		if (actual != this->root)
		{
			cout << actual->getData() << "\t";
		}

		if (actual->getRight() != nullptr)
		{
			this->printBinaryTree_preorder(actual->getRight());
		}
	}
}

/*
* Recursive function to get in the depth of the tree
*/
void binaryTree::printBinaryTree_inorder(shared_ptr<node> actual)
{

	if (this->root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return;
	}
	else
	{
		if (actual->getLeft() != nullptr)
		{
			this->printBinaryTree_inorder(actual->getLeft());
		}

		cout << actual->getData() << "\t";

		if (actual->getRight() != nullptr)
		{
			this->printBinaryTree_inorder(actual->getRight());
		}
	}
}

void binaryTree::printBinaryTree_postorder(shared_ptr<node> actual)
{
	if (this->root == nullptr)
	{
		cout<<"\nTree is empty!\n"<<endl;
		return;
	}
	else
	{
		if (actual->getLeft() != nullptr)
		{
			//Call inorder
			this->printBinaryTree_inorder(actual->getLeft());
		}

		if (actual != this->root)
		{
			cout << actual->getData() << "\t";
		}

		if (actual->getRight() != nullptr)
		{
			this->printBinaryTree_inorder(actual->getRight());
		}
		cout << "R: " << this->root->getData() << "\t";
	}
}

void binaryTree::insertNode()
{
	int data;

	if (this->root == nullptr)
	{
		cout << "\nTree is empty!\n" << endl;
		cout << "Insert the root: "; cin >> data;

		this->root = make_shared<node>();
		this->root->setData(data);
	}
	else
	{
		cout<<"\nEnter a node: "; cin >> data;
		shared_ptr<node> newNode = make_shared<node>();
		newNode->setData(data);
		
		actual = this->root;
		while (actual != nullptr)
		{
			//insert to the left
			if (newNode->getData() <= actual->getData())
			{
				//check if insertion can be done
				if (actual->getLeft() == nullptr)
				{
					actual->setLeft(newNode);
					return;
				}
				else
				{
					//continue traversal 
					actual = actual->getLeft();
				}

			}
			//insert to the right
			else if (newNode->getData() > actual->getData())
			{
				//check if insertion can be done
				if (actual->getRight() == nullptr)
				{
					actual->setRight(newNode);
					return;
				}
				else
				{
					//continue
					actual = actual->getRight();
				}
			}
		}
	}
}

void binaryTree::insertNodeParam(int data)
{
	if (this->root == nullptr)
	{
		cout << "\nTree is empty!\n" << endl;
		this->root = make_shared<node>();
		this->root->setData(data);
	}
	else
	{
		cout << "\nEnter a node: ";
		shared_ptr<node> newNode = make_shared<node>();
		newNode->setData(data);
		actual = this->root;
		while (actual != nullptr)
		{
			if (newNode->getData() <= actual->getData())
			{
				if (actual->getLeft() == nullptr)
				{
					actual->setLeft(newNode);
					return;
				}
				else
				{
					actual = actual->getLeft();
				}
			}
			else if (newNode->getData() > actual->getData())
			{
				if (actual->getRight() == nullptr)
				{
					actual->setRight(newNode);
					return;
				}
				else
				{
					actual = actual->getRight();
				}
			}
		}
	}
}

shared_ptr<node> binaryTree::searchMinimum(shared_ptr<node> actual)
{
	if (this->root == nullptr)
	{
		cout << "\nTree is empty!\n" << endl;
		return actual;
	}
	else
	{
		while (actual->getLeft() != nullptr)
		{
			actual = actual->getLeft();
		}
	}
	return actual;
}

void binaryTree::searchNode(shared_ptr<node> actual)
{

	if (this->root == nullptr)
	{
		cout << "\nTree is empty!\n" << endl;
		return;
	}
	else
	{
		if (actual->getLeft() != nullptr)
		{
			this->searchNode(actual->getLeft());
		}
		if (actual->getData() == this->searchedNumber)
		{
			this->dataIsFound = true;
		}
		if (actual->getRight() != nullptr)
		{
			this->searchNode(actual->getRight());
		}
	}
}


/*
* Deletion of a node will be done on cases
* 1. Case 1: Both children are nullptr -> deletion can be performed.
* 2. Case 2: Left child is nullptr -> set "actual" to the right child.
* 3. Case 3: Right child is nullptr -> set "actual" to the left child.
* 4. Case 4: Both children are different from nullptr -> search for the smallest node in right subtree and set it in place of the deleted node.
*/
shared_ptr<node> binaryTree::deleteNode(shared_ptr<node> actual)
{
	if (actual == nullptr)
	{
		return  nullptr;
	}
	else if (this->searchedNumber < actual->getData())
	{
		cout << "\nThe number we are looking for is smaller, we enter the left subtree.\n";
		actual->setLeft(deleteNode(actual->getLeft()));
	}
	else if (this->searchedNumber > actual->getData())
	{
		cout << "\nThe number we are looking for is larger, we enter the right subtree.\n";
		actual->setRight(deleteNode(actual->getRight()));
	}
	else
	{
		//entering here sets that the node at which we are currently, is the one that needs to be deleted
		this->setDataIsFound();
		
		if (actual->getLeft() == nullptr && actual->getRight() == nullptr)//Case 1
		{
			actual = nullptr;
		}
		else if (actual->getLeft() == nullptr)//Case 2
		{
			actual = actual->getRight();
		}
		else if (actual->getRight() == nullptr)//Case 3
		{
			actual = actual->getLeft();
		}
		else//Case 4
		{
			shared_ptr<node> smallestNodeInRightSubtree = make_shared<node>();
			smallestNodeInRightSubtree = searchMinimum(actual->getRight());

			cout << "Deleting node: " << this->searchedNumber << " and replacing it with: " << smallestNodeInRightSubtree->getData() << endl;
			actual->setData(smallestNodeInRightSubtree->getData());
			
			this->setSearchedNumber(smallestNodeInRightSubtree->getData());
			actual->setRight(deleteNode(actual->getRight()));
		}
	}
	return actual;
}

void binaryTree::deleteMinimumNode()
{
	shared_ptr<node> smallestNodeInTree = make_shared<node>();
	smallestNodeInTree = searchMinimum(this->root);
	
	cout << "Deleting the lowest value: " << smallestNodeInTree->getData() << endl;
	this->setSearchedNumber(smallestNodeInTree->getData());
	deleteNode(this->root);
}