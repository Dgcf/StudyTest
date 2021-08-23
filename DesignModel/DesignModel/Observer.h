#pragma once

#include "common.h"


class Subject;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void Update(Subject* theChangedSubject) = 0;

protected:
	Observer() {}
};


class Subject
{
public:
	virtual ~Subject() {}

	virtual void Attach(Observer* o)
	{
		observers_->push_back(o);
	}

	virtual void Detach(Observer* o)
	{
		observers_->remove(o);
	}

	virtual void Notify()
	{
		for (std::list<Observer*>::iterator it = observers_->begin(); it != observers_->end(); ++it)
		{
			(*it)->Update(this);
		}
	}

protected:
	Subject(): observers_(new std::list<Observer*>()) {}

private:
	std::list<Observer*>* observers_;
};


class ClockTimer: public Subject
{
public:
	ClockTimer() {}

	virtual int GetHour()
	{
		return 21;
	}

	virtual int GetMinute()
	{
		return 30;
	}

	virtual int GetSecond()
	{
		return 41;
	}

	void Tick()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		Notify();
	}
};

class DigitalClock : public Observer
{
public:
	DigitalClock(ClockTimer* t) : subject_(t)
	{
		subject_->Attach(this);
	}

	virtual ~DigitalClock()
	{
		subject_->Detach(this);
	}

	virtual void Update(Subject* theChangedSubject)
	{
		if (theChangedSubject == subject_)
		{
			Draw();
		}
	}

	virtual void Draw()
	{
		cout << "GetHour: " << subject_->GetHour() << endl;
		cout << "GetMinute: " << subject_->GetMinute() << endl;
		cout << "GetSecond: " << subject_->GetSecond() << endl;
	}

private:
	ClockTimer* subject_;
};
