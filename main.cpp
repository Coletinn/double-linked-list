// Gustavo Coleto de Freitas 32076541
// João Vitor Teles Centrone 32033125

#include <iostream>
#include <clocale>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List) ***\n";

	LinkedList* list = Create();
	PrintDoubleListInfo(list);

	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");
	PrintDoubleListInfo(list);

	Clear(list);
	PrintDoubleListInfo(list);

	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);
	
	Node* temp = RemoveNode(list, 44);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << "\n";
	PrintDoubleListInfo(list);

	temp = RemoveHead(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << "\n";
	PrintDoubleListInfo(list);

	temp = RemoveTail(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << "\n";
	PrintDoubleListInfo(list);

	cout << "Fim.\n";
}