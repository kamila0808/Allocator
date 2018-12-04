#include <stdio.h>
#include <iostream>
#include <vector>
#include "alloc001.h"

using namespace std;


int mem_size; // общий размер памяти
bool mem; // признак созданиея

vector <int> block, addr;


int create(int size,mem_handle_t h){
if (mem == 1 || size < 1) return 1;

mem_size = size;
mem = 1;
h = nullptr;
return 0;
}

//************************************************

int destroy(mem_handle_t h){

if (mem == 0) return 1;
Node *Next;

if(*h != HULL)
{
Next *h;
do
{
Next = Delete(Next);
} while(Next != NULL);
*h=NULL;
}
mem = 0;
return 0;
}

//************************************************

mem_handle_t alloc(int block_size){

Node Newnode;

NewNode=New(NewNode);

if (NewNode!=Null)
{
NewNode->data=data;
NewNode->Next=(*Node)->Next;
(*Node)->Next=NewNode;
}

// mem_handle_t ans(0,0);
// if (mem == 0 || block_size == 0) return ans;


// if (block_size + full > mem_size) return ans;

// full += block_size;

// int index = ((int)block.size()) - 1;

// block.push_back(block_size);
// if (addr.size() == 0) addr.push_back(0);
// else addr.push_back(block[index] + addr[index]);
// index ++;

// ans.addr = addr[addr.size()-1];
// ans.size = block[block.size()-1];

// return ans;

}

//************************************************

int free(mem_handle_t h){

// if (mem == 0 || addr.empty()) return 1;/

// addr.pop_back();
// full -= block[block.size() - 1];
// block.pop_back();

return 0;
}

int realloc(mem_handle_t h, int size)
{

Node node;

for (node=h;node=NULL;node=node->next);

if (NewNode!=Null)
{
for (i=0;i<size;i++) {
NewNode=New(NewNode);
NewNode->data=data;
NewNode->Next=(*Node)->Next;
(*Node)->Next=NewNode;
}
}

int defrag(mem_handle_t head)
{

}
;

 

//************************************************

void setup_memory_manager(memory_manager_t* mm) {
mm->create = create;
mm->destroy = destroy;
mm->alloc = alloc;
mm->free = free;
mm->get_max_block_size = get_max_block_size;
mm->get_free_space = get_free_space;
mm->print_blocks = print_blocks;
}