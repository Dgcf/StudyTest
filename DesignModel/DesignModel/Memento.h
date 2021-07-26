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

	}

private:
	// 宽接口
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
	// 创建备忘录
	void CreateMemento()
	{
		m_ = new Memento();
	}

	// 恢复备忘录
	void GetState()
	{
		state_ = m_->get_state();
	}


};



