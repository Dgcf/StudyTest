#include "Mediator.h"

namespace mediator
{
/**************************************************************************************
* 案例：各个国家需要对某个提案进行投票表决
* Colleague：每个国家，具体为China,American,Russia,Japan
* Mediator: WTO(世贸组织)，WHO(世卫组织), WB(世界银行)——非中介者模式下这些对象不需要
**************************************************************************************/

	namespace common
	{
		class China;
		class American;
		class Russia;
		class Japan;

		class Country
		{
		public:
			void Agree()
			{
				cout << "Agree" << endl;
			}

			void DisAgree()
			{
				cout << "Disagree" << endl;
			}
		};

		class China: public Country
		{
		private:
			American* a;
			Russia* r;
			Japan* j;

		public:
			// 发起倡议并请求投票
			void VoteAboutWto()
			{
				a->DisAgree();
				r->Agree();
				j->DisAgree();
			}

			void VoteAboutWB()
			{
				a->Agree();
				r->Agree();
				j->DisAgree();
			}
		};

		class American: public Country
		{
		private:
			China* c;
			Russia* r;
			Japan* j;

		public:
			void VoteAboutWto()
			{
				c->DisAgree();
				r->Agree();
				j->DisAgree();
			}
		};

		class Russia : public Country
		{
		private:
			American* a;
			China* c;
			Japan* j;

		public:
			void VoteAboutWto()
			{
				c->Agree();
				a->DisAgree();
				j->DisAgree();
			}
		};

		class Japan : public Country
		{
		private:
			American* a;
			China* c;
			Russia* r;

		public:
			void VoteAboutWto()
			{
				a->Agree();
				c->DisAgree();
				r->DisAgree();
			}
		};
	}

	namespace mediatorpattern
	{
		class Mediator;
		class Country
		{
		protected:
			Country(Mediator* m) : t(m) {}
			Mediator* t;
		};

		class China: public Country
		{
		public:
			China(Mediator* m) : Country(m) {}
			void VoteAboutWto()
			{
				t->Vote();
			}
		};

		class America: public Country
		{
		public:

		};

		class Russia : public Country
		{
		public:

		};

		class Japan : public Country
		{
		public:

		};

		class Mediator
		{
		public:
			void Vote()
			{
			}
		};

		class WTO: public Mediator
		{
		private:
			China* c;
			America* a;
			Russia* r;
			Japan* j;

		public:
			WTO(China* _c, America* _a, Russia* _r, Japan* _j) :
				c(_c), a(_a), r(_r), j(_j)
			{}

			void Vote()
			{

			}
		};
	}
}