#pragma once
#include "Comparable.h"
#include "LinkedList.h"
#include "Entry.h"

template<class K, class V>
class Map
{
public:
	virtual void put(K key, V value) = 0;

	virtual V get(K* key) = 0;

	virtual List<Entry<K, V>>* entrySet() = 0;

	virtual List<V>* values() = 0;

	virtual List<K>* keyList() = 0;

	virtual bool containsKey(K* key) = 0;

	virtual bool containsValue(V* value) = 0;
};