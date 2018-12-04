
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <memory.h>

struct mem_handle_t {
// адрес размещения блока относительно начала всей памяти (в байтах)
int addr;
// размер блока в байтах
int size;

mem_handle_t(int addr, int size) :
addr(addr),
size(size);

}; // дескриптор блока памяти

typedef struct Node
{
int data;
struct Node *Next;
} Node;

 

typedef struct
{
// создание менеджера памяти,
// size: - размер всей памяти в байтах,
// возвращаемое значение: 0 - успех, 1 - неудача

int (*create)(int size);
// удаление менеджера памяти
// возвращаемое значение: 0 - успех, 0 - неудача
int (*destroy)();

// выделение блока памяти размером block_size байт
mem_handle_t (*alloc)(int block_size);

// освобождение блока памяти с дескриптором h
// возвращаемое значение: 0 - успех, 1 - неудача (например, неверный дескриптор)

int (*free)(mem_handle_t h);

// возвращает дескриптор выделенного блока памяти, целиком содержащего указанный регион
// в случае, если такого блока не существует, возвращается нулевой дескриптор {0,0}
mem_handle_t (*get_block)(int addr, int size);


// выделение дополнительной памяти
// возвращаемое значение: 0 - успех, 1 - неудача (например, неверный дескриптор)

int (*realloc)(mem_handle_t h, int size);

// дефрагментация памяти
// возвращаемое значение: 0 - успех, 1 - неудача (например, неверный дескриптор)

int (*defrag)(mem_handle_t head);

} memory_manager_t;

void setup_memory_manager(memory_manager_t* mm);

#endif