#pragma once
#include "common.h"

class WriteFile
{
public:
    explicit WriteFile(const string& path)
    {
        //CreateFolder(path.substr(0, path.rfind('/')));
        fWriteFile_.open(path, ios::out | ios::trunc);  // ��ȷ��·������; ����ļ�����,��պ���д
    }

    void Write(const char* c, size_t size)
    {
        if (!fWriteFile_.is_open())
        {
            return;
        }
        fWriteFile_.write(c, size);
    }

    WriteFile& operator<<(const char* str)
    {
        fWriteFile_ << str << endl;
        return *this;
    }

    // ���ļ��ж�ȡ����д��
    /*void WriteFromFile(const string& rp, unsigned char fileid);
    void CreateFolder(const string& path);*/

private:
    ofstream fWriteFile_;
};

class Singletons1
{
public:
	static Singletons1* Instance()
	{
		if (!pInstance_)  // �ɱ�����Ҫһ��΢������ļ�⶯��
		{
			pInstance_ = new Singletons1;
		}
		return pInstance_;
	}

    static void Wt(const string &s)
    {
        cout << ++count_ << endl;
        WriteFile t(s);
        t << "good afternoon";
    }

	~Singletons1()
	{
		delete pInstance_;
		pInstance_ = nullptr;
	}

private:
    Singletons1() {}

private:
	static Singletons1* pInstance_;  // ������ʼ�������������ڵ��ù��캯����ʼ��
    static int count_;
};

/***
* ����һ�����⣺��ĳ��.cpp�� int a = Singletons2::Instance()->DoSomething();
* ��Բ�ͬ���뵥Ԫ�еĶ�̬��ʼ������C++��δ�涨���ʼ��˳��
* ���Զ�a�ĳ�ʼ����Instance()�п��ܴ���һ����δ����Ķ���
*/
class Singletons2 
{
public:
    static Singletons2* Instance()
    {
        return &Instance_;
    }

    void DoSomething()
    {}

private:
    static Singletons2 Instance_;  // ��̬��ʼ�����޹��캯����ͨ�������ڳ�������ʼ��
};


void test_singleton1();

void test_singleton2();


//template<typename T>
//class SingleThread
//{
//public:
//    typedef T VolatileType;
//};
//
//template
//<
//    typename T,
//    template <typename> class CreationPolicy=CreateUsingNew,
//    template <typename> class LifetimePolicy=DefaultLifeTime,
//    template <typename> class ThreadingModel=SingleThread,
//>
//class SingletonHolder
//{
//public:
//    static T& Instance();
//
//private:
//    static void DestroySingleton();
//    SingletonHolder();
//
//    typedef ThreadingModel<T>::VolatileType InstanceType;
//    static InstanceType* pInstance_;
//    static bool destroyed_;
//};
//
//template<typename T, class CreationPolicy<>, class LifetimePolicy<>, class ThreadingModel<>>
//inline T& SingletonHolder<T, CreationPolicy<>, LifetimePolicy<>, ThreadingModel<>>::Instance()
//{
//    if (!pInstance_)
//    {
//        typename ThreadingModel<T>::Lock guard;
//        if (!pInstance_)
//        {
//            if (destroyed_)
//            {
//                LifetimePolicy<T>::OnDeadference();
//                destroyed_ = false;
//            }
//            pInstance_ = CreationPolicy<T>::Create();
//            LifetimePolicy<T>::ScheduleCall(&DestroySingleton);
//        }
//    }
//    return *pInstance_;
//}
//
//template<typename T, class CreationPolicy<>, class LifetimePolicy<>, class ThreadingModel<>>
//inline void SingletonHolder<T, CreationPolicy<>, LifetimePolicy<>, ThreadingModel<>>::DestroySingleton()
//{
//    assert(!destroyed_);
//    CreationPolicy<T>::Destroy(pInstance_);
//    pInstance_ = 0;
//    destroyed_ = true;
//}
