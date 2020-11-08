﻿#include "BinaryTree.h"
#include<memory>
#include<stdio.h>

/*
Aplicatia 8.2
Se cere să se implementeze următoarele modalităţi de traversare ale unui arbore binar:
 Căutare în adâncime varianta preordine
 Căutare în adâncime varianta inordine
 Căutare în adâncime varianta postordine
 Căutare prin cuprindere, varianta cu evidenţierea nivelurilor arborelui binar.
Utilizând implementarea de la aplicaţia 8.1 se cere în continuare:
 Să se construiască un arbore binar ordonat
 Să se afiseze pe ecran structura acestuia (vezi secvenţa [8.2.7.1.a])
 Să se parcurga arborele şi să se afişeze succesiunea nodurilor, în fiecare dintre
modalităţile de căutare mai sus precizate.

Am folosit codul scris la aplicatia 8.1 la care am adaugat functiile de afisare in varianta pre / in / post ordine



Am realizat programul in C++ pentru o mai buna structurare a tipurilor de date si usurinta de a lucra cu fiecare obiect.

Operatorul "Creeaza" l-am implementat in functia de insertie, pentru a fi mai usor de lucrat cu programul.

*/




int main()
{
	unique_ptr <binaryTree> binaryTree1 = make_unique<binaryTree>();
	int searched = 0;
	int toDelete = 0;
	int optiune = 0;

	do
	{	
		system("cls");
		cout <<"\n\n1.Inserare.\n";
		cout <<"2.Cauta.\n";
		cout <<"3.SuprimaMin\n";
		cout <<"4.Suprima.\n";

		cout << "5.Afisare preordine.\n";
		cout << "6.Afisare inordine.\n";
		cout << "7.Afisare postordine.\n";

		cout << "0.Exit.\n";
		

		cin >> optiune;


		switch (optiune)
		{
		case 0:
			printf("Exiting...\n\n\n");
			break;
			

		case 1:
			binaryTree1->insertNode();
			break;


		case 2:
			//dam un numar pentru cautare
			cout << "Introduceti numarul cautat: "; cin >> searched;
			binaryTree1->setSearchedNumber(searched);

			binaryTree1->searchNode(binaryTree1->getRoot());

			//daca variabila "DataIsFound" a fost setata pe true atunci am gasit numarul
			if (binaryTree1->getDataIsFound())
			{
				cout << "Succes! Numarul "<<binaryTree1->getSearchedNumber()<<" a fost gasit in arbore\n";
			}
			else
			{
				cout << "Eroare! Numarul " << binaryTree1->getSearchedNumber() << " nu a fost gasit in arbore\n";
			}

			//dupa ce am apelat functia de cautare, resetam variabila.
			binaryTree1->resetDataIsFound();
			break;

		case 3:
			binaryTree1->SupriMin();
			break;

		case 4:
			
			cout << "Introduceti numarul cautat: "; cin >> toDelete;
		    binaryTree1->setSearchedNumber(toDelete);
		    binaryTree1->deleteNode(binaryTree1->getRoot());


			//daca variabila "DataIsFound" a fost setata pe true atunci am gasit numarul
			if (binaryTree1->getDataIsFound())
			{
				cout << "Succes! Numarul " << toDelete << " a fost sters din arbore\n";
			}
			else
			{
				cout << "Eroare! Numarul " << toDelete << " nu a fost gasit in arbore, stergerea nu poate avea loc\n";
			}

			//dupa ce am apelat functia de stergere, resetam variabila.
			binaryTree1->resetDataIsFound();

			break;



		case 5:
			cout << "\nAfisare preordine\nArborele contine: \n";
			binaryTree1->printBinaryTree_preordine(binaryTree1->getRoot());
			cout << endl;
			break;


		case 6:
			cout << "\nAfisare inordine\nArborele contine: \n";
			binaryTree1->printBinaryTree_inordine(binaryTree1->getRoot());
			cout << endl;
			break;

		case 7:
			cout << "\nAfisare postordine\nArborele contine: \n";
			binaryTree1->printBinaryTree_postordine(binaryTree1->getRoot());
			cout << endl;
			break;

		default:
			printf("\nWrong option selected.\n");
			break;
		}

		system("pause");
	} while (optiune != 0);


	return 0;
}