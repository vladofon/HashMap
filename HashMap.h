#pragma once
#include "Map.h"

template<class K, class V>
class HashMap : public Map<K, V>
{
public:
	HashMap()
	{
		this->initialCapacity = 16;
		this->loadFactor = 0.75;
		this->capacity = initialCapacity;
		this->threshold = capacity * loadFactor;
		this->size = 0;

		this->table = new Node*[capacity];
		for (long i = 0; i < capacity; ++i)
			table[i] = nullptr;
	}

	void put(K key, V value) override
	{
		long hashCode = hash(key.hashCode());
		long index = indexFor(hashCode, capacity);

		if (table[index] == nullptr)
		{
			table[index] = new Node(key, value, hashCode);
		}
		else 
		{
			Node* current = table[index];

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}

			current->pNext = new Node(key, value, hashCode);
		}	
	}

	V get(K* key) override 
	{
		long hashCode = hash(key->hashCode());
		long index = indexFor(hashCode, capacity);

		Node* current = table[index];

		if (current->pNext == nullptr && current != nullptr)
		{
			return current->value;
		}
		while (current->pNext != nullptr)
		{
			if (current->key.equals(key))
			{
				return current->value;
			}

			current = current->pNext;
		}

		return V();
	}

	static long hash(long h)
	{
		unsigned long hash = h;
		hash ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static long indexFor(long hash, long length)
	{
		return hash & (length - 1);
	}



private:
	class Node
	{
	public:
		Node* pNext;
		K key;
		V value;

		long hash;

		Node(K key, V value, long hash, Node* pNext = nullptr)
		{
			this->key = key;
			this->value = value;
			this->hash = hash;
			this->pNext = pNext;
		}

		Node() {
			// Empty constructor for dynamic array
		}
	};

	long initialCapacity;
	double loadFactor;
	long threshold;
	long capacity;
	long size;

	Node** table;

	void increaseSize()
	{
		this->capacity = capacity * 2;
		this->threshold = capacity * loadFactor;
	}

	void resize()
	{
		if (size >= threshold)
		{
			increaseSize();
			Node** newTable = new Node * [capacity];

			// need Entry[] implementation for rehash table
		}
	}


};