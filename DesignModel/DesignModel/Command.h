#pragma once
#include "common.h"


class Receiver
{
public:
	virtual void Action() = 0;
};


class ConcreteRcv1 : public Receiver
{
public:
	void Action()
	{
		cout << "ConcreteRcv1::Action" << endl;
	}
};


class ConcreteRcv2 : public Receiver
{
public:
	void Action()
	{
		cout << "ConcreteRcv2::Action" << endl;
	}
};


class Command
{
public:
	Command(Receiver* r)
		: r_(r)
	{}

	virtual void  Execute()
	{
		cout << "Execute Do nothing" << endl;
	}

	virtual void UnExecute()
	{
		cout << "UnExecute Do nothing" << endl;
	}

protected:
	Receiver* r_;
};


class ConcreteCmd1 : public Command
{
public:
	ConcreteCmd1(Receiver* r) : Command(r)
	{}

	void Execute()
	{
		r_->Action();
	}

	void UnExecute()
	{
		cout << "ConcreteCmd1::UnExecute" << endl;
	}
};


class ConcreteCmd2 : public Command
{
public:
	ConcreteCmd2(Receiver* r) : Command(r)
	{}

	void Execute()
	{
		r_->Action();
	}

	void UnExecute()
	{
		cout << "ConcreteCmd1::UnExecute" << endl;
	}
};


class Invoker
{
private:
	std::list<Command*> cmds_;

public:
	void SetCmd(Command* cmd)
	{
		// 
		cmds_.push_back(cmd);
	}

	void CancelCmd(Command* cmd)
	{
		//cmds_.erase(cmd);
	}

	void Notify()
	{
		for (std::list<Command*>::iterator it = cmds_.begin(); it != cmds_.end(); ++it)
		{
			(*it)->Execute();
		}
	}
};
