#pragma once
#include "common.h"

class Mediator
{
};


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
