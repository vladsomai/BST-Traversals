#include "BinaryTree.h"
#include<memory>
#include<stdio.h>

void treeMenu();
using std::unique_ptr;
using std::make_unique;

shared_ptr<binaryTree> CreateBinTree();

int main()
{
	treeMenu();
}

void treeMenu()
{
	shared_ptr <binaryTree> binTree = CreateBinTree();
	int searched = 0;
	int toDelete = 0;
	int option = 0;

	do
	{
		system("cls");
		cout << "\n\n1.Insert\n";
		cout << "2.Search\n";
		cout << "3.Delete minimum node\n";
		cout << "4.Delete\n";

		cout << "5.Print preorder\n";
		cout << "6.Print inorder\n";
		cout << "7.Print postorder\n";
		cout << "8.Print breadth first / level\n";

		cout << "0.Exit.\n";

		cin >> option;

		switch (option)
		{
		case 0:
			printf("Exiting...\n\n\n");
			break;

		case 1:
			binTree->insertNode();
			break;

		case 2:
			cout << "Enter the number you want to find: "; cin >> searched;
			binTree->setSearchedNumber(searched);
			binTree->searchNode(binTree->getRoot());

			if (binTree->getDataIsFound())
			{
				cout << "Succes! Number " << binTree->getSearchedNumber() << " has been found in the tree\n";
			}
			else
			{
				cout << "Error! Number " << binTree->getSearchedNumber() << " could not be found in the tree\n";
			}
			binTree->resetDataIsFound();
			break;

		case 3:
			binTree->deleteMinimumNode();
			break;

		case 4:
			cout << "Enter the node to be deleted: "; cin >> toDelete;
			binTree->setSearchedNumber(toDelete);
			binTree->deleteNode(binTree->getRoot());
			if (binTree->getDataIsFound())
			{
				cout << "Succes! Number " << toDelete << " has been deleted from the tree!\n";
			}
			else
			{
				cout << "Error! Number " << toDelete << " could not be found in the tree\n";
			}
			binTree->resetDataIsFound();
			break;

		case 5:
			cout << "\nPreorder\nTree contains: \n";
			binTree->printBinaryTree_preorder(binTree->getRoot());
			cout << endl;
			break;

		case 6:
			cout << "\nInorder\nTree contains: \n";
			binTree->printBinaryTree_inorder(binTree->getRoot());
			cout << endl;
			break;

		case 7:
			cout << "\nPostorder\nTree contains: \n";
			binTree->printBinaryTree_postorder(binTree->getRoot());
			cout << endl;
			break;

		case 8:
			cout << "\nBreadth first\nTree contains: \n";
			binTree->printBinaryTree_Breadth_first(binTree->getRoot());
			cout << endl;
			break;

		default:
			cout << "\nWrong option selected." << endl;
			break;
		}

		system("pause");
	} while (option != 0);


}

shared_ptr<binaryTree> CreateBinTree()
{
	unique_ptr <binaryTree> binaryTree1 = make_unique<binaryTree>();

	binaryTree1->insertNodeParam(7);
	binaryTree1->insertNodeParam(5);
	binaryTree1->insertNodeParam(6);
	binaryTree1->insertNodeParam(2);
	binaryTree1->insertNodeParam(9);
	binaryTree1->insertNodeParam(10);
	binaryTree1->insertNodeParam(8);
	binaryTree1->insertNodeParam(13);

	return binaryTree1;
}