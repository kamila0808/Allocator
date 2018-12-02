#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

struct mem_handle_t {
	int addr;
	int size;

	mem_handle_t(int addr, int size) :
		addr(addr),
		size(size)
		;

		bool operator==(const mem_handle_t& other) { return other.addr == addr && other.size == size; }
	bool operator!=(const mem_handle_t& other) { return !operator==(other); }
};

typedef struct
{
	int (*create)(int size);
	int (*destroy)();
	int (*alloc)(int size);
	int (*free)(mem_handle_t head);
	int (*realloc)(int size);
	int (*defrag)(mem_handle_t head);

	mem_handle_t (*alloc)(int block_size);

} memory_manager_t;

void setup_memory_manager(memory_manager_t* mm);

#endif

int (*create)(int size);
{
	m_head = nullptr;
	m_size = 0;
}

int (*alloc)(int size)
{
	template<typename T, class alloc = std::allocator<T>>
	class try_list
	{
	public:
		try_list()
		{
			m_head = nullptr;
			m_size = 0;
		}

		void push_back(T data)
		{
			if (m_head == nullptr)
			{
				m_head = m_allocator.allocate(sizeof(Node<T>));
				*m_head = data;
			}
			else
			{
				Node<T> *current = this->m_head;
				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				current->pNext = m_allocator.allocate(sizeof(Node<T>));
			}
			m_size++;
		}

	private:
		template<typename U>
		class Node
		{
		public:
			Node *pNext;
			U data;

			Node(U data = U(), Node *pNext = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
			}
		};
		int m_size;
		Node<T> *m_head;
		using node_alloc = typename alloc::template rebind<T>::other;
		node_alloc m_allocator;
	};

};






