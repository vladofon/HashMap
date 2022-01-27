#pragma once
#include "Map.h"
#include"List.h"
#include"LinkedList.h"
#include"Entry.h"

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

		this->table = new LinkedList<Entry<K, V>>[capacity];
		for (long i = 0; i < capacity; i++)
		{
			table[i] = LinkedList<Entry<K, V>>();
		}

		this->entryList = LinkedList<Entry<K, V>>();
	}

	void put(K key, V value) override
	{
		long hashCode = hash(key.hashCode());
		long index = indexFor(hashCode, capacity);

		table[index].add(Entry<K, V>(key, value, hashCode));

		entryList.add(Entry<K, V>(key, value, hashCode));
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

	LinkedList<Entry<K, V>> entrySet()
	{
		return entryList;
	}

	LinkedList<V> values()
	{
		LinkedList<V> mapValues = LinkedList<V>();

		long counter = 0;

		while (counter != entryList.getSize())
		{
			mapValues.add(entryList.get(counter).getValue());
		}

		return mapValues;
	}	
	
	LinkedList<K> keyList()
	{
		LinkedList<K> mapKeys = LinkedList<K>();

		long counter = 0;

		while (counter != entryList.getSize())
		{
			mapKeys.add(entryList.get(counter).getKey());
		}

		return mapKeys;
	}

private:

	long initialCapacity;
	double loadFactor;
	long threshold;
	long capacity;
	long size;

	LinkedList<Entry<K, V>>* table;
	LinkedList<Entry<K, V>> entryList;

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