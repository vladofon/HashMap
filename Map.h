#pragma once
#include "Comparable.h"


template<class K, class V>
class Map
{
public:
	virtual void put(K key, V value) = 0;

	virtual void get(K key) = 0;
};