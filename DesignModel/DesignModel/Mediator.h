#pragma once
#include "common.h"


class DialogDirector
{
public:
	virtual void WidgetAChanged()
	{

	}

	virtual void CreateWidgetA() 
	{
	}

};

class WidgetA
{
private:
	DialogDirector* dir_;

public:
	WidgetA(DialogDirector* d)
		: dir_(d)
	{}

	virtual void changed()
	{
		dir_->WidgetAChanged();
	}
};


class ListWidgetA: public WidgetA
{
private:
	string test_;

public:
	ListWidgetA(DialogDirector* d)
		: WidgetA(d)
	{}

	void set_str(const string& s)
	{
		test_ = s;
	}

	string get_str() const
	{
		return test_;
	}
};


class ButtonWidgetA : public WidgetA
{
private:
	string test_;

public:
	ButtonWidgetA(DialogDirector* d)
		: WidgetA(d)
	{}

	void set_str(const string& s)
	{
		test_ = s;
	}

	string get_str() const
	{
		return test_;
	}
};


class EntryWidgetA : public WidgetA
{
private:
	string test_;

public:
	EntryWidgetA(DialogDirector* d)
		: WidgetA(d)
	{}

	void set_str(const string& s)
	{
		test_ = s;
	}

	string get_str() const
	{
		return test_;
	}
};


class FontDialogDirector : public DialogDirector
{
private:
	ListWidgetA* list_;
	ButtonWidgetA* button_;
	EntryWidgetA* entry_;

public:
	void CreateWidgetA()
	{
		list_ = new ListWidgetA(this);
		button_ = new ButtonWidgetA(this);
		entry_ = new EntryWidgetA(this);
	}

	virtual void WidgetAChanged()
	{
		list_->set_str("FontDialogDirector");
		button_->set_str("FontDialogDirector");
		entry_->set_str("FontDialogDirector");
	}

	void ListCtrl()
	{
		list_->changed();
	}
};


class FormalDialog
{
private:
	ListWidgetA* list_;
	ButtonWidgetA* button_;
	EntryWidgetA* entry_;

public:
	void ListCtrl()
	{

	}

	void ButtonCtrl()
	{

	}

	void EntryCtrl()
	{

	}
};



// 中介者接口类:国际组织
class InterOrg
{
public:
	virtual void Declare(const string& str) = 0;
	virtual ~InterOrg() {}
};

class Country
{
protected:
	InterOrg* mediator_;

public:
	Country(InterOrg* m) : mediator_(m) {}

	virtual string GetCountry() const = 0;
	virtual void Declare(const string& str) = 0;
};

class China : public Country
{
public:
	China(InterOrg* i) : Country(i) {}

	void Declare(const string& str)
	{
		mediator_->Declare("attack");
	}

	string GetCountry() const
	{
		return "China";
	}
};

class American : public Country
{
public:
	American(InterOrg* i) : Country(i) {}

	void Declare(const string& str)
	{
		cout << "American does not agree" << endl;
	}

	string GetCountry() const
	{
		return "American";
	}
};

class Japan : public Country
{
public:
	Japan(InterOrg* i) : Country(i) {}

	void Declare(const string& str)
	{
		cout << "Japan does not agree" << endl;
	}

	string GetCountry() const
	{
		return "Japan";
	}
};

class Russia : public Country
{
public:
	Russia(InterOrg* i) : Country(i) {}

	void Declare(const string& str)
	{
		cout << "Russia agree" << endl;
	}

	string GetCountry() const
	{
		return "Russia";
	}
};

// 世界卫生组织
class WHO: public InterOrg
{
public:
	void Declare(const string& str)
	{
		american_->Declare("No");
		japan_->Declare("No");
		russia_->Declare("yes");
	}

	void Init(China* c, American* a, Japan* j, Russia* r)
	{
		china_ = c;
		american_ = a;
		japan_ = j;
		russia_ = r;
	}
	
private:
	China* china_;
	American* american_;
	Japan* japan_;
	Russia* russia_;
};

// 教科文组织
class Unesco : public InterOrg
{

};

// 世界银行
class WorldBank : public InterOrg
{

};


