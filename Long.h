#pragma once
#include "Comparable.h"

class Long : public Comparable<Long>
{
public:
	long data;

	Long(long data)
	{
		this->data = data;
	}

	Long()
	{
		this->data = 0;
	}

	inline bool equals(Long* item) const noexcept 
	{ 
		if (item == this)
		{
			return true;
		}
		if (item == nullptr)
		{
			return false;
		}

		return (item->data == this->data);
	}

	inline long hashCode() const noexcept 
	{ 
		long prime = 31;
		int result = 1;

		result = prime * result + data;
		return result;
	}
};