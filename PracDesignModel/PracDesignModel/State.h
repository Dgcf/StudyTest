#pragma once

#include "common.h"

namespace state
{
	// 普通流程：
	namespace common
	{
		enum State
		{
			Unknown = -1,
			Listen,
			Established,
			CloseWait,
			LastAck,
			Closed
		};

		class TcpConnection
		{
		private:
			State state_;

		public:
			State GetState() const
			{
				return state_;
			}

			void CreateSocket()
			{
				cout << "Create Socket, start listen" << endl;
				state_ = Listen;
			}

			void ConnectClient()
			{
				cout << "connect client, established" << endl;
				state_ = Established;
			}

			void ClientClosed()
			{
				cout << "client disconnect, close_wait" << endl;
				state_ = CloseWait;
			}

			void ServerClosed()
			{
				cout << "Server Closed" << endl;
				state_ = Closed;
			}
		};

		void User()
		{
			TcpConnection c;
			c.CreateSocket();
		}

		class WorkContext
		{
		public:
			void SetWorkState(int h)
			{
				if (h < 12)
				{
					cout << "morning" << endl;
				}
				else if (h < 13)
				{
					cout << "afternoon" << endl;
				}
				else if (h < 21)
				{
					cout << "evening" << endl;
				}
			}
		};
	}

	// 状态模式
	namespace statepattern
	{
		class WorkContext
		{
		private:
			WorkState* state_;

		public:
			WorkContext(WorkState* t) : state_(t) {}

			void SetWorkState(int h)
			{
				state_->Handle(this, h);
			}

		private:
			friend class WorkState;
			void ChangeState(WorkState* t)
			{
				state_ = t;
			}
		};

		class WorkState
		{
		private:
			//WorkState* state_;

		public:
			/*WorkState(WorkState* s)
				: state_(s) {}
			*/

			virtual void Handle(WorkContext* c, int h)
			{
				//state_->Handle(h);
			}

			/*void RequestHandle(WorkState* t)
			{
				t->Handle()
			}*/

			virtual void ChangeState(WorkContext* c, WorkState* t)
			{
				c->ChangeState(t);
			}
		};

		class EveningState : public WorkState
		{
		private:
			static EveningState* state_;

		public:
			static EveningState* Instance()
			{
				if (!state_)
				{
					return new EveningState;
				}
			}
		public:
			/*EveningState(WorkState* s) : WorkState(s)
			{}*/

			void Handle(WorkContext* c, int h)
			{
				if (h < 21)
				{
					cout << "Evening State" << endl;
				}
				else
				{
					cout << "nonthing" << endl;
				}
			}
		};

		class NoonState : public WorkState
		{
		private:
			static NoonState* state_;
		public:
			static NoonState* Instance()
			{
				if (!state_)
				{
					return new NoonState;
				}
			}
		public:
			/*NoonState(WorkState* s) : WorkState(s)
			{}*/

			void Handle(WorkContext* c, int h)
			{
				if (h < 13)
				{
					cout << "Noon" << endl;
					ChangeState(c, EveningState::Instance());
				}
				else
				{
					EveningState::Instance()->Handle(c, h);
				}
			}
		};

		class MorningState : public WorkState
		{
		private:
			static MorningState* state_;
		public:
			static MorningState* Instance()
			{
				if (!state_)
				{
					return new MorningState;
				}
			}

			void Handle(WorkContext* c, int h)
			{
				if (h < 12)
				{
					cout << "It's 12 hour" << endl;
					ChangeState(c, NoonState::Instance());
				}
				else
				{
					NoonState::Instance()->Handle(c, h);
				}
			}
		};
	}
	
}