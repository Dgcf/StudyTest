#pragma once

#include "common.h"


class Memento;

class Originator
{
private:
	Memento* m_;
	string state_;

public:
	// ��������¼
	void CreateMemento()
	{
		m_ = new Memento();
	}

	// �ָ�����¼
	void SetMemento(const Memento& memento)
	{

	}
};


class Memento
{
public:
	friend class Originator;

	// խ�ӿ�
	string get_state() const
	{
		
	}

private:
	// ��ӿ�
	void set_state()
	{

	}
};
