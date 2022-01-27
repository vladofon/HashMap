#pragma once

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