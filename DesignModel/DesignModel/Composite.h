#pragma once

#include "common.h"

class Watt;
class Currency;

template<typename T> class Iterator;

class Equipment
{
public:
	virtual ~Equipment();

	const char* Name() { return name_; }
	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();

	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);
	virtual Iterator<Equipment*>* CreateIterator();

protected:
	Equipment(const char*) {}

private:
	const char* name_;
};


class FloppyDisk : public Equipment
{
public:
	FloppyDisk(const char*);
	virtual ~FloppyDisk();

	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();
};


class CompositeEquipment : public Equipment
{
public:
	virtual ~CompositeEquipment() {}

	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();

	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);
	virtual Iterator<Equipment*>* CreateIterator();

protected:
	CompositeEquipment(const char*) {}

private:
	list<Equipment*> equi_;
};


