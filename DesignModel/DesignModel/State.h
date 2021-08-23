#pragma once

#include "common.h"


class TCPState;
class TCPClosed;
class TCPOctetStream;


class TCPConnection
{
public:
	TCPConnection()
	{
		state_ = TCPClosed::Instance();
	}

	void ActiveOpen() {
		state_->ActiveOpen(this);
	}

	void PassiveOpen() {
		state_->PassiveOpen(this);
	}

	void Close() {
		state_->Close(this);
	}

	void Send() {
		state_->Send(this);
	}

	void Acknowledge() {
		state_->Acknowledge(this);
	}

	void Synchronize() {
		state_->Synchronize(this);
	}

	void ProcessOctet(){}

private:
	friend class TCPState;

	void ChangeState(TCPState* s)
	{
		state_ = s;
	}

	TCPState* state_;
};


class TCPState
{
public:
	virtual void Transmit(TCPConnection*){}

	virtual void ActiveOpen(TCPConnection*) {}

	virtual void PassiveOpen(TCPConnection*) {}

	virtual void Close(TCPConnection*) {}

	virtual void Synchronize(TCPConnection*) {}

	virtual void Acknowledge(TCPConnection* ){}

	virtual void Send(TCPConnection* ) {}

protected:
	void ChangeState(TCPConnection* t, TCPState* s)
	{
		t->ChangeState(s);
	}
};


class TCPEstablished : public TCPState
{
public:
	static TCPState* Instacne()
	{
		if (!instance_)
		{
			instance_ = new TCPEstablished();
		}
		return instance_;
	}

	virtual void Transmit(TCPConnection*, TCPOctetStream*)
	{

	}

	virtual void Close(TCPConnection* t)
	{

	}

private:
	static TCPEstablished* instance_;
};


class TCPListen : public TCPState
{
public:
	static TCPState* Instance()
	{
		if (!instance_)
		{
			instance_ = new TCPListen();
		}
		return instance_;
	}

private:
	static TCPListen* instance_;
};


class TCPClosed : public TCPState
{
public:
	static TCPState* Instance()
	{
		if (!instance_)
		{
			instance_ = new TCPClosed();
		}
		return instance_;
	}

	virtual void ActiveOpen(TCPConnection* t)
	{
		ChangeState(t, TCPEstablished::Instacne());
	}

	void PassiveOpen(TCPConnection* t)
	{
		ChangeState(t, TCPListen::Instance());
	}

private:
	static TCPClosed* instance_;
};

class Work;

// 描述工作和工作状态
class WorkState
{
public:
	virtual void WorkProgram(Work* work) = 0;
};

// 睡眠状态
class SleepingState : public WorkState
{
public:

};

// 下班休息状态
class RestState : public WorkState
{

};

// 晚上工作状态
class EveningState : public WorkState
{

};

// 下午工作状态
class AfternoonState : public WorkState
{

};

// 中午工作状态
class NoonState : public WorkState
{
public:
	void WorkProgram(Work* work)
	{

	}
};

// 上午工作状态
class ForenoonState : public WorkState
{
public:
	ForenoonState() :state_(new NoonState()) {}
	
	void WorkProgram(Work* work)
	{
		if (work->hour < 12)
		{
			cout << "当前工作时间：" << work->hour << endl;
		}
		else
		{
			work->SetState(state_);
		}
	}

private:
	NoonState* state_;
};

class Work
{
private:
	WorkState* state_;
	

public:
	// 自动设定当前状态
	Work(WorkState* state=nullptr): state_(state ? state: new ForenoonState()) {}

	void WorkPragrma()
	{

	}

	void SetState(WorkState* s)
	{
		state_ = s;
	}

	int hour;
};