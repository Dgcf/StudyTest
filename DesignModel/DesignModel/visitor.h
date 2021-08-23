#pragma once

#include "common.h"


class BaseVisitor
{
public:
	virtual ~BaseVisitor()
	{
	}
};


template<typename T, typename R = void>
class Visitor
{
public:
	typedef R ReturnType;
	virtual ReturnType Visit(T&) = 0;

};


namespace visitor
{
	class PrePerson
	{
	public:
		virtual void GetWorkStatus(string s) = 0;
		virtual void GetMoneyStatus(string s) = 0;
	};

	class PreMan : public PrePerson
	{
	public:
		void GetWorkStatus(string s)
		{
			if (s == "a")  // 成功
			{
				cout << "man: work" << endl;
			}
			else if (s == "b")  // 失败
			{
				cout << "man: no work" << endl;
			}
		}

		void GetMoneyStatus(string s)
		{
			if (s == "a")
			{
				cout << "man: work" << endl;
			}
			else if (s == "b")
			{
				cout << "man: no work" << endl;
			}
		}
	};

	class PreWoman : public PrePerson
	{
	public:
		void GetWorkStatus(string s)
		{
			if (s == "a")  // 成功
			{
				cout << "woman: work" << endl;
			}
			else if (s == "b")  // 失败
			{
				cout << "woman: no work" << endl;
			}
		}

		void GetMoneyStatus(string s)
		{
			if (s == "a")
			{
				cout << "woman: money" << endl;
			}
			else if (s == "b")
			{
				cout << "woman: no money" << endl;
			}
		}
	};


	class Visitor
	{
	public:
		virtual void GetManStatus(string s) = 0;
		virtual void GetWomanStatus(string s) = 0;
	};

	class WorkStatus : public Visitor
	{
	public:
		void GetManStatus(string s)
		{
			if (s == "a")  // 成功
			{
				cout << "man: work" << endl;
			}
			else if (s == "b")  // 失败
			{
				cout << "man: no work" << endl;
			}
		}

		void GetWomanStatus(string s)
		{
			if (s == "a")  // 成功
			{
				cout << "woman: work" << endl;
			}
			else if (s == "b")  // 失败
			{
				cout << "woman: no work" << endl;
			}
		}
	};

	class MoneyStatus : public Visitor
	{
	public:
		void GetManStatus(string s)
		{
			if (s == "a")
			{
				cout << "man: money" << endl;
			}
			else if (s == "b")
			{
				cout << "man: no money" << endl;
			}
		}

		void GetWomanStatus(string s)
		{
			if (s == "a")
			{
				cout << "woman: money" << endl;
			}
			else if (s == "b")
			{
				cout << "woman: no money" << endl;
			}
		}
	};

	class Person
	{
	public:
		virtual void GetStatus(Visitor* v, string s) = 0;
	};

	class Man : public Person
	{
	public:
		void GetStatus(Visitor* v, string s)
		{
			v->GetManStatus(s);
		}
	};

	class Woman : public Person
	{
	public:
		void GetStatus(Visitor* v, string s)
		{
			v->GetWomanStatus(s);
		}
	};

}
