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
