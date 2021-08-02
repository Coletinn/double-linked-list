// Gustavo Coleto de Freitas 32076541
// João Vitor Teles Centrone 32033125

#include <iostream>
#include <string>

using namespace std;
 
struct Node
{
	int id; 
	std::string name;
	Node* prev;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

Node* CreateNode();
LinkedList* Create();
void Insert(LinkedList* list, int id, std::string name);
void Append(LinkedList* list, int id, std::string name);
Node* RemoveHead(LinkedList* list);
Node* RemoveTail(LinkedList* list);
Node* RemoveNode(LinkedList* list, int value);

bool isEmpty(const LinkedList* list);
void Print(const LinkedList* list);
void PrintDoubleListInfo(const LinkedList* list);
void Clear(LinkedList* list);
void DestroyNode(Node* node);


