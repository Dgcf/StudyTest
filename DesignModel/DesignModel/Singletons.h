#pragma once
#include "common.h"

class WriteFile
{
public:
    explicit WriteFile(const string& path)
    {
        //CreateFolder(path.substr(0, path.rfind('/')));
        fWriteFile_.open(path, ios::out | ios::trunc);  // 先确保路径存在; 如果文件存在,清空后再写
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

    // 从文件中读取后再写入
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
		if (!pInstance_)  // 成本是需要一个微不足道的检测动作
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
	static Singletons1* pInstance_;  // 被动初始化，即在运行期调用构造函数初始化
    static int count_;
};

/***
* 存在一个问题：在某个.cpp中 int a = Singletons2::Instance()->DoSomething();
* 面对不同编译单元中的动态初始化对象，C++并未规定其初始化顺序，
* 所以对a的初始化中Instance()有可能传回一个尚未构造的对象
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
    static Singletons2 Instance_;  // 静态初始化，无构造函数可通过编译期常量来初始化
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
