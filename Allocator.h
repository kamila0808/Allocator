#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

class CleverPtr
{
	void* data;
public:
	CleverPtr();
	void* get() const;
	~CleverPtr();
};

struct mem_handle_t
{
	int addr, size;
	mem_handle_t(int addr, int size) :
		addr(addr),	
		size(size);
	}; // дескриптор блока памяти

	typedef struct Node
{
	void* data;
	struct Node * Next;
	int addr;
	int freq = 0;
	int size;
	int block_size;
	int max_block_size;
} Node;

typedef struct
{
	int (*create)(int size); // создание менеджера памяти
	int (*destroy)();

	mem_handle_t (*alloc)(int block_size);
	int (*free)(mem_handle_t h);
	int (*realloc)(mem_handle_t h, int size);
	int (*defrag)(mem_handle_t head);

	mem_handle_t (*get_block)(int addr, int size);  
	int(*get_max_block_size)();
	int(*get_free_space)();
	void(*print_blocks)(); // распечатывает все выделенные блоки памяти в формате <аddr> <size>;

} memory_manager_t;

void setup_memory_manager(memory_manager_t* mm);

#endif