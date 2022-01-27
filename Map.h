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

	virtual LinkedList<Entry<K, V>> entrySet() = 0;

	virtual LinkedList<V> values() = 0;

	virtual LinkedList<K> keyList() = 0;
};