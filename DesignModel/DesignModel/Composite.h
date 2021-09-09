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
	//CompositeEquipment(const char*) {}

private:
	list<Equipment*> equi_;
};


namespace composite
{
	class Component
	{
	public:
		virtual void Add(Component* c)
		{
			cout << "Component::Add" << endl;
		}

		virtual void Remove(Component c)
		{
			cout << "Component::Remove" << endl;
		}

		virtual void Display(int depth)
		{
			cout << "Component::Display" << endl;
		}
	};


	class Leaf : public Component
	{
	public:
		Leaf(string name): m(name) {}

		void Add(Component* c)
		{
			cout << "Leaf::Add_" << endl;
		}

		void Remove(Component* c)
		{
			cout << "Leaf::Remove" << endl;
		}

		void Display(int c)
		{
			cout << "Leaf::Display" << m << endl;
		}

	private:
		string m;
	};


	class Composite : public Component
	{
	private:
		std::list<Component*> lc;

	public:
		Composite(string name) {
			cout << name << endl;
		}

		void Add(Component* c)
		{
			lc.push_back(c);
		}

		void Remove(Component* c)
		{
			lc.remove(c);
		}

		void Display(int c)
		{
			cout << "Composite::Display" << endl;
			for (list<Component*>::iterator iter = lc.begin(); iter != lc.end(); ++iter)
			{
				(*iter)->Display(0);
			}
		}
	};

	inline void test()
	{
		Composite* root = new Composite("root");
		root->Add(new Leaf("Leaf A"));
		root->Add(new Leaf("Leaf B"));

		Composite* comp = new Composite("Composite X");
		comp->Add(new Leaf("Leaf XA"));
		comp->Add(new Leaf("Leaf XB"));
		root->Add(comp);

		Composite* comp2 = new Composite("Composite YY");
		comp2->Add(new Leaf("Leaf XYA"));
		comp2->Add(new Leaf("Leaf XYB"));
		comp->Add(comp2);

		root->Add(new Leaf("Leaf C"));
		Leaf* leaf = new Leaf("Leaf D");
		root->Add(leaf);
		root->Remove(leaf);

		root->Display(1);
	}
}