#pragma once
#include "common.h"

class Request;
class Zhuguan;
class Manager;
class Director;



enum Kind
{
	LeaveKind = 0,
	CostKind = 1
};



/// <summary>
/// 请假流程：
/// 请一天假主管可批；请一天到三天之内经理批，三天到七天总监批，。。。
/// </summary>
class ChainOfResponsibility
{
public:
	ChainOfResponsibility(ChainOfResponsibility* c)
		: chain_(c)
	{}

	virtual void HandleProcess(int i)
	{
		if (chain_)
		{
			return;
			chain_->HandleProcess(i);  // 维护一个后继者链接
		}
		
	}

	void HandleRequest(Request* r)
	{

	}

private:
	ChainOfResponsibility* chain_;
};


class Zhuguan: public ChainOfResponsibility
{
public:
	Zhuguan(ChainOfResponsibility* c)
		: ChainOfResponsibility(c)
	{}

	void HandleProcess(int i)
	{
		if (i == 1)
		{
			cout << "Zhuguan agree" << endl;
		}
		else
		{
			ChainOfResponsibility::HandleProcess(i);
		}
	}
};


class Manager : public ChainOfResponsibility
{
public:
	Manager(ChainOfResponsibility* c)
		: ChainOfResponsibility(c)
	{}

	void HandleProcess(int i)
	{
		if (i <= 3 && i > 1)
		{
			cout << "Manager agree" << endl;
		}
		else
		{
			ChainOfResponsibility::HandleProcess(i);
		}
	}
};

class Director : public ChainOfResponsibility
{
public:
	Director()
		: ChainOfResponsibility(nullptr)
	{}

	void HandleProcess(int i)
	{
		if (i > 3)
		{
			cout << "Director agree" << endl;
		}
	}
};

class Request
{
public:
	virtual Kind GetKind() = 0;

};

class LeaveRequest
{
public:
	Kind GetKind()
	{
		return LeaveKind;
	}

	void AskForLeave(){}
};


