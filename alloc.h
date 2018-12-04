
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <memory.h>

struct mem_handle_t {
// ����� ���������� ����� ������������ ������ ���� ������ (� ������)
int addr;
// ������ ����� � ������
int size;

mem_handle_t(int addr, int size) :
addr(addr),
size(size);

}; // ���������� ����� ������

typedef struct Node
{
int data;
struct Node *Next;
} Node;

 

typedef struct
{
// �������� ��������� ������,
// size: - ������ ���� ������ � ������,
// ������������ ��������: 0 - �����, 1 - �������

int (*create)(int size);
// �������� ��������� ������
// ������������ ��������: 0 - �����, 0 - �������
int (*destroy)();

// ��������� ����� ������ �������� block_size ����
mem_handle_t (*alloc)(int block_size);

// ������������ ����� ������ � ������������ h
// ������������ ��������: 0 - �����, 1 - ������� (��������, �������� ����������)

int (*free)(mem_handle_t h);

// ���������� ���������� ����������� ����� ������, ������� ����������� ��������� ������
// � ������, ���� ������ ����� �� ����������, ������������ ������� ���������� {0,0}
mem_handle_t (*get_block)(int addr, int size);


// ��������� �������������� ������
// ������������ ��������: 0 - �����, 1 - ������� (��������, �������� ����������)

int (*realloc)(mem_handle_t h, int size);

// �������������� ������
// ������������ ��������: 0 - �����, 1 - ������� (��������, �������� ����������)

int (*defrag)(mem_handle_t head);

} memory_manager_t;

void setup_memory_manager(memory_manager_t* mm);

#endif