#include <stdio.h>
#include <iostream>
#include <vector>
#include "Allocator.h"

using namespace std;

int mem_size; // общий размер памяти
bool mem; // признак создания

vector <int> block, addr;

// создание менеджера памяти
int create(int size, mem_handle_t h)
{
	if (mem == 1 || size < 1) return 1;  // неудача

	mem_size = size;
	mem = 1;
	h = nullptr;
	return 0;
}
// удаление менеджера памяти
int destroy(mem_handle_t h)
{
	if (mem == 0) return 1;
	Node *Next;

	if (*h != NULL)
	{
		Next *h;
		do
		{
			Next = Delete(Next);
		} while (Next != NULL);
		*h = NULL;
	}
	mem = 0;
	return 0;
}

mem_handle_t alloc(int block_size) {

	//CleverPtr ClevPtr;
	Node NewNode;
	NewNode = New(NewNode);

	if (NewNode != Null)
	{
		NewNode->data = data;
		NewNode->Next = (*Node)->Next;
		(*Node)->Next = NewNode;
	}
}

int free(mem_handle_t h)
{
	struct mem_handle_t *h;
	h = data - sizeof(struct mem_handle_t);
	if (h == head)
	{
		head = h.Next;
	}
	else {while (head = Next) head = h.Next;}
	return 0;
}

int realloc(mem_handle_t h, int size)
{
	Node node;

	for (node = h; node = NULL; node = node->next);

	if (NewNode != Null)
	{
		for (i = 0; i < size; i++) {
			NewNode = New(NewNode);
			NewNode->data = data;
			NewNode->Next = (*Node)->Next;
			(*Node)->Next = NewNode;
		}
	}
///////////////////////////////////////////////////////
	int defrag(mem_handle_t head) { }

	CleverPtr::CleverPtr(void* data)
	{
		this.data = data;
	}
	int CleverPtr::get(void* data)
	{
		if (  )
		{
			return freq++;
		}
	}
///////////////////////////////////////////////////////
	// int get_max_block_size()
	// {
	// 	if (!created) {	return 0; }
	// 	if (mem_size - block_size < 0) { return 0; }
	// 	return block_size;
	// }

	//int get_free_space(){	}

	void print_blocks()
	{
		for (int i = 0; i < h.size(); i++) {
			cout << h[i].addr << " " << h[i].size << endl;
		}
	}

	void setup_memory_manager(memory_manager_t* mm)
	{
		mm->create = create;
		mm->destroy = destroy;
		mm->alloc = alloc;
		mm->free = free;
		mm->defrag = defrag;
		mm->realloc = realloc;
		mm->get_max_block_size = get_max_block_size;
		mm->get_free_space = get_free_space;
		mm->print_blocks = print_blocks;
	}