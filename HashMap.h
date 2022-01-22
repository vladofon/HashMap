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

		this->table = new Node[capacity];
	}

	void put(K key, V value) override
	{
		long index = indexFor(key.hashCode());

		table[index] = Node(key, value);
	}

private:
	class Node
	{
	public:
		Node* pNext;
		K key;
		V value;

		Node(K key, V value, Node pNext = nullptr)
		{
			this->key = key;
			this->value = value;
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

	Node* table;

	long indexFor(long hash, long length)
	{
		return hash % (length - 1);
	}
};