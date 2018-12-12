#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

class CleverPtr
{
	Node* node;

public:
	CleaverPtr* next = NULL;
	CleverPtr(Node* node) {
		this->node = node;
	}
	void* get() const {
		this->node->freq++;
		return node->data;
	}
	CleaverPtr& operator=(const CleaverPtr& b) {
		CleaverPtr& a = *this;
		node = b.node;
		if (b.next == NULL)
			b.next = a;
		else
			for (auto* curr = a.next; curr->next != b; curr = curr->next)
				curr->next = a;
		a.next = b;
		return *this;
	}
};

struct Node
{
	int size;
	void* data;
	Node * next;
	int addr;
	int freq;
	bool is_free;
	bool isCreated;

	Node():
		size(0),
		addr(0),
		next(nullptr),
		is_free(false),
		isCreated(false),
		data(NULL){},
	     freq(0)
};

class Allocator
{
public:
	Allocator(int size)
	{
		this->memories = malloc(size);
		Node::Node *memories;
		memories->data = nullptr;
		memories->next = NULL;
		memories->addr = NULL;
		memories->freq = 0;
		memories->size = size;
	}
	~Allocator()
	{
		free(this->memories);
	}

public:
	void* memories;
	int create(int size); // создание менеджера памяти
	int destroy();
	CleaverPtr* alloc(int size);
	void free(CleaverPtr *h);
	void realloc(CleaverPtr *h, int size);
	void defrag();
	int get_block(int addr, int size);
};

