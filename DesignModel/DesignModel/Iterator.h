#pragma once

#include "common.h"

list<int>::iterator iter;

template<typename Item>
class List
{
public:
	List();
	long Count() const;
	Item& Get(long index) const;
};


template<typename Item>
class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item CurrentItem() const = 0;

protected:
	Iterator();
};


template<typename Item>
class ListIterator : public Iterator<Item>
{
public:
	ListIterator(const List<Item>* aList)
		: _list(aList), _current(0)
	{}

	virtual void First()
	{
		_current = 0;
	}

	virtual void Next() {
		_current++;
	}

	virtual bool IsDone() const
	{
		return _current >= _list->Count();
	}

	virtual Item CurrentItem() const
	{
		if (IsDone())
		{
			throw IteratorOutOfBounds;
		}
		
		return _list->Get(_current);
	}

private:
	const List<Item>* _list;
	long _current;
};

