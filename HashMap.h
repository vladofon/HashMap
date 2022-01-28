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

		this->entryList = new LinkedList<Entry<K, V>>();
	}

	void put(K key, V value) override
	{
		long hashCode = hash(key.hashCode());
		long index = indexFor(hashCode, capacity);

		table[index].add(Entry<K, V>(key, value, hashCode));

		entryList->add(Entry<K, V>(key, value, hashCode));
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

	List<Entry<K, V>>* entrySet()
	{
		return entryList;
	}

	bool containsKey(K* key)
	{
		long hashCode = hash(key->hashCode());
		long index = indexFor(hashCode, capacity);

		long counter = 0;

		while (counter != table[index].getSize())
		{
			if (table[index].get(counter).getKey().equals(key))
			{
				return true;
			}

			counter++;
		}

		return false;
	}	
	
	bool containsValue(V* value)
	{
		long counter = 0;

		while (counter != entryList->getSize())
		{
			if (entryList->get(counter).getValue().equals(value))
			{
				return true;
			}

			counter++;
		}

		return false;
	}

	List<V>* values()
	{
		LinkedList<V>* mapValues = new LinkedList<V>();

		long counter = 0;

		while (counter != entryList->getSize())
		{
			mapValues->add(entryList->get(counter).getValue());
			counter++;
		}

		return mapValues;
	}	
	
	List<K>* keyList()
	{
		List<K>* mapKeys = new LinkedList<K>();

		long counter = 0;

		while (counter != entryList->getSize())
		{
			mapKeys->add(entryList->get(counter).getKey());
			counter++;
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
	List<Entry<K, V>>* entryList;

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