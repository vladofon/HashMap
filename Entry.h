#pragma once
#include"List.h"
#include"LinkedList.h"

template<class K, class V>
class Entry
{
	class Node
	{
	public:
		K key;
		V value;

		long hash;

		Node(K key, V value, long hash)
		{
			this->key = key;
			this->value = value;
			this->hash = hash;
		}

		Node() {
			// Empty constructor for dynamic array
		}

		K getKey()
		{
			return this->key();
		}

		V getValue()
		{
			return this->value;
		}

		long getHash()
		{
			return this->hash;
		}
	};
};