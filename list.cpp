// Gustavo Coleto de Freitas 32076541
// João Vitor Teles Centrone 32033125

#include "list.h"
#include <string>

using namespace std;

Node* CreateNode()
{
	Node* node = new Node;
	
	return node;
}

LinkedList* Create()
{
	LinkedList* list = new LinkedList;
	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

void Insert(LinkedList* list, int id, string name)
{
	Node* newNode = new Node;

	newNode->id = id;
	newNode->name = name;
	newNode->prev = nullptr;
	newNode->next = list->head;

	if (list->head != nullptr)
	{
		list->head->prev = newNode;
	}
	list->count++;
	list->head = newNode;
}


void Append(LinkedList* list, int id, string name)
{
	Node* newNode = new Node;
	Node* last = list->head;

	newNode->id = id;
	newNode->name = name;

	newNode->next = nullptr;

	if (list->head == nullptr)
	{
		newNode->prev = nullptr;
		list->head = newNode;
	}

	while (last->next != nullptr)
	{
		last = last->next;
	}
	list->count++;
	last->next = newNode;

	newNode->prev = last;
	++list->count;
}


Node* RemoveHead(LinkedList* list)
{
	Node* toRemove = list->head;
	if (list->head == list->tail)
	{
		list->head = list->tail = nullptr;
	}
	else
	{
		list->head = list->head->next;
		list->head->prev = nullptr;
	}
	--list->count;
	toRemove->next = nullptr;
	return toRemove;
}


Node* RemoveTail(LinkedList* list)
{
	if (list->tail == list->head)
	{
		return RemoveHead(list);
	}

	Node* toRemove = list->tail;
	Node* prev = toRemove->prev;

	prev->next = list->head;
	list->head->prev = prev;
	list->tail = prev;
	list->count--;
	return toRemove;
}


Node* RemoveNode(LinkedList* list, int value)
{
	Node* toRemove = list->head;
	Node* previous = nullptr;

	while (toRemove != nullptr && toRemove->id != value)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	if (toRemove == list->head)
	{
		return RemoveHead(list);
	}
	else if (toRemove == list->tail)
	{
		return RemoveTail(list);
	}
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;

		--list->count;

		toRemove->next = nullptr;
		return toRemove;
	}

}


bool isEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}


void Print(const LinkedList* list)
{
	Node* value = list->head;
	while (value != nullptr)
	{
		cout << "[" << value->id << "] " << value->name << "\n";
		value = value->next;
	}
}

void PrintReverse(const LinkedList* list)
{
	Node* node = new Node;
	node = list->tail;
	for (int i = 0; i < list->count; i++)
	{
		cout << "[" << node->id << "]" << node->name << "\n";
		node = node->prev;
	}
	cout << "\n";
}

void PrintDoubleListInfo(const LinkedList* list)
{
	if (isEmpty(list))
	{
		std::cout << "Lista vazia!\n";
	}
	else
	{
		std::cout << "Lista:\n";
		Print(list);
	}
}


void Clear(LinkedList* list)
{
	Node* node = list->head;
	Node* next = nullptr;

	while (node != nullptr)
	{
		next = node->next;
		DestroyNode(node);
		node = next;
	}

	list->head = list->tail = nullptr;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}
