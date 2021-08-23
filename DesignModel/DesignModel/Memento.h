#pragma once

#include "common.h"

class Originator;

class Memento
{
public:
	friend class Originator;

	// 窄接口
	string get_state() const
	{
		return state_;
	}

private:
	Memento(const string& s) : state_(s) {}

	// 宽接口
	void set_state(const Memento& s)
	{
		state_ = s.state_;
	}

private:
	string state_;
};

class Originator
{
private:
	string state_;

public:
	// 创建备忘录
	Memento* CreateMemento()
	{
		return new Memento(state_);
	}

	// 恢复备忘录
	void SetState(Memento m)
	{
		m.set_state(m);
	}
};

class Caretaker
{
private:
	Memento* memento_;

};

