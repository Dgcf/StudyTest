#pragma once

#include "common.h"

class Originator;

class Memento
{
public:
	friend class Originator;

	// խ�ӿ�
	string get_state() const
	{
		return state_;
	}

private:
	Memento(const string& s) : state_(s) {}

	// ��ӿ�
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
	// ��������¼
	Memento* CreateMemento()
	{
		return new Memento(state_);
	}

	// �ָ�����¼
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

