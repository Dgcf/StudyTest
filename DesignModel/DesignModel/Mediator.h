#pragma once
#include "common.h"
class Mediator
{
};


class DialogDirector;

class Widget
{
private:
	DialogDirector* dir_;

public:
	Widget(DialogDirector* d)
		: dir_(d)
	{}

	virtual void changed()
	{
		dir_->WidgetChanged();
	}
};


class ListWidget: public Widget
{
private:
	string test_;

public:
	ListWidget(DialogDirector* d)
		: Widget(d)
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


class ButtonWidget : public Widget
{
private:
	string test_;

public:
	ButtonWidget(DialogDirector* d)
		: Widget(d)
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


class EntryWidget : public Widget
{
private:
	string test_;

public:
	EntryWidget(DialogDirector* d)
		: Widget(d)
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


class DialogDirector
{
public:
	virtual void WidgetChanged()
	{

	}

	virtual void CreateWidget() = 0;

};


class FontDialogDirector : public DialogDirector
{
private:
	ListWidget* list_;
	ButtonWidget* button_;
	EntryWidget* entry_;

public:
	void CreateWidget()
	{
		list_ = new ListWidget(this);
		button_ = new ButtonWidget(this);
		entry_ = new EntryWidget(this);
	}

	virtual void WidgetChanged()
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
	ListWidget* list_;
	ButtonWidget* button_;
	EntryWidget* entry_;

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

class P;
class A;
class B;
class C;
class D;


// Mediator
class Mediator
{
public:
	virtual void Changed()
	{}
};


class P
{
private:
	Mediator* m_;

public:
	P(Mediator* m)
		: m_(m)
	{}

	virtual void SayNo()
	{
		m_->Changed();
	}

	virtual void go()
	{
		m_->Changed();
	}
};

class A: public P
{
public:
	A(Mediator* am)
		: P(am)
	{

	}

	void SetMediator(Mediator* m)
	{}

	string str_;

	void DoSomething()
	{
		SayNo();
	}
};


class B: public P
{
public:
	B(Mediator* am)
		: P(am)
	{

	}
	string str_;
};

class C: public P
{
public:
	C(Mediator* am)
		: P(am)
	{

	}
	string str_;
};

class D: public P
{
public:
	D(Mediator* am)
		: P(am)
	{

	}
	string str_;
};


class AMediator: public Mediator
{
public:
	AMediator()
	{
	
	}

	void Changed()
	{
		b_->str_ = "agree A";
		c_->str_ = "disagree A";
		d_->str_ = "neutral A";
	}

private:
	A* a_;
	B* b_;
	C* c_;
	D* d_;
};