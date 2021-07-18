#pragma once

#include "common.h"


class Memento;

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
	void SetMemento(const Memento& memento)
	{

	}
};


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
