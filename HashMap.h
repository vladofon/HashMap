#pragma once
#include "Map.h"
#include"List.h"
#include"LinkedList.h"

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

		this->table = new LinkedList<Entry<K,V>>[capacity];
		for (long i = 0; i < capacity; i++)
		{
			table[i] = LinkedList<Entry<K, V>>();
		}
	}

	void put(K key, V value) override
	{
		long hashCode = hash(key.hashCode());
		long index = indexFor(hashCode, capacity);

		table[index].add(Entry<K,V>(key, value, hashCode));
	}

	V get(K* key) override 
	{
		long hashCode = hash(key->hashCode());
		long index = indexFor(hashCode, capacity);

		if (table[index].getSize() != 0)
		{
			for (long i = 0; i < table[index].getSize(); i++)
			{
				if (table[index].get(i).getKey().equals(key))
				{
					return table[index].get(i).getValue();
				}
			}
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
	template<class K, class V>
	class Entry
	{
	public:
		K key;
		V value;

		long hash;

		Entry(K key, V value, long hash)
		{
			this->key = key;
			this->value = value;
			this->hash = hash;
		}

		Entry() {
			// Empty constructor for dynamic array
		}

		K getKey()
		{
			return this->key;
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

	long initialCapacity;
	double loadFactor;
	long threshold;
	long capacity;
	long size;

	LinkedList<Entry<K,V>>* table;

	void increaseSize()
	{
		this->capacity = capacity * 2;
		this->threshold = capacity * loadFactor;
	}

	void resize()
	{
		if (size >= threshold)
		{
			/*increaseSize();
			Node** newTable = new Node * [capacity];*/

			// need Entry[] implementation for rehash table
		}
	}


};