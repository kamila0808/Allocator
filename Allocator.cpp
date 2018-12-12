#include <stdio.h>
#include <iostream>
#include <vector>
#include "Allocator.h"

using namespace std;

int mem_size; // общий размер памяти
bool mem; // признак создания

vector <int> block, addr;

//////////////////////// создание менеджера памяти//////////////////
int Allocator::create(int size)
{
	if (mem == 1 || size < 1) return 1;  // неудача

	mem_size = size;
	mem = 1;
	h = nullptr;
	return 0;
}
/////////////////////////////////////////////////////////

//////////////////////// удаление менеджера памяти///////////////////
int Allocator::destroy()
{
	if (mem == 0) return 1;
	Node *next;

	if (*h != NULL)
	{
		next *h;
		do
		{
			next = Delete(next);
		} while (next != NULL);
		*h = NULL;
	}
	mem = 0;
	return 0;
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
CleverPtr* Allocator::alloc(int size) {

	Node NewNode;
	NewNode = New(NewNode);
	if (NewNode != Null)
	{
		NewNode->data = data;
		NewNode->next = (*Node)->next;
		(*Node)->next = NewNode;
	}

	CleverPtr result = CleverPtr::CleverPtr(NewNode);
	return &result;
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// void Allocator::free(CleaverPtr *h)
// {
// 	struct MemoryManager *h;
// 	h = data - sizeof(struct MemoryManager);
// 	if (h == first)
// 	{
// 		first = h.next;
// 	}
// 	else {while (first = next) first = h.next;}
// 	return 0;
// }
/////////////////////////////////////////////////////////


int Allocator::sort(Node *start)
//параметр - указатель на начало списка.
{
	Node *node;
// указатель для внешнего цыкла for
	Node *n_node;
// для внутреннего
	for (node = start->next; node != NULL; node = node->next)
//пробегаемся по всех узлах списка
		for (n_node = start->next; n_node->next != NULL; n_node = n_node->next)
//а здесь только до узла, next которого указывает на NULL
//обычный обмен значениями
			if (n_node->freq > n_node->next->freq) {
				int tmp;
				tmp = n_node->data; //
				n_node->data = n_node->next->data;
				n_node->next->data = tmp;
			}
	return 0;
}

void Allocator::defrag()
{
	Node *node;
	Node *adr, *adr1;
	adr = h;
	for (node = h->next; node != NULL; node = node->next) {
		adr1 = node;
		if (adr1 - adr != sizeof(Node)) {
			h->next = h;
			h = NULL;
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////
void Allocator::realloc(CleaverPtr *h, int size)
{
	Node *node;
	for (node = h->next; node != NULL; node = node->next) {}

	h = node;
	Node *tmp = (Node*) malloc(sizeof(Node));

	tmp->data = data;
	tmp->next = h;
	tmp->freq = 0;
	h = tmp;
	return 0;
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
int Allocator::get_block(int addr, int size) {}

/////////////////////////////////////////////////////////

