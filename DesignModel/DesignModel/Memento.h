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

	}

private:
	// ��ӿ�
	void set_state()
	{

	}
};

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
	void GetState()
	{
		state_ = m_->get_state();
	}


};



