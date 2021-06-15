#pragma once
#include "common.h"


template<typename T>
class LockingProxy
{
public:
	LockingProxy(T* pObj): pointee_(pObj)
	{
		pointee_->Lock();
	}

	~LockingProxy()
	{
		pointee_->UnLock();
	}

	T* operator->() const
	{
		return pointee_;
	}

private:
	LockingProxy& operator=(const LockingProxy&);
	T* pointee_;
};


/****************************************
* 如何存储和访问指针对象的policy class
****************************************/
template<typename T>
class DefaultSPStorage
{
public:
	typedef T* StoredType;
	typedef T* InitPointerType;
	typedef T* PointerType;
	typedef T& ReferenceType;

	DefaultSPStorage() : pointee_(Default())
	{}

	DefaultSPStorage(const DefaultSPStorage&) = delete;

	DefaultSPStorage(const StoredType& p) : pointee_(p)
	{}

	PointerType operator->() const
	{
		return pointee_;
	}

	PointerType operator*() const
	{
		return *pointee_;
	}

	template<typename Y> 
	friend typename DefaultSPStorage<Y>::PointerType GetImpl(const DefaultSPStorage<Y>& sp);

	template<typename Y>
	friend const typename DefaultSPStorage<Y>::StoredType& GetImplRef(const DefaultSPStorage<Y>& sp);

	template<typename T>
	friend typename DefaultSPStorage<T>::StoredType GetImplRef(DefaultSPStorage<T>& sp);

protected:
	static StoredType Default()
	{
		return nullptr;
	}

	void Destroy()
	{
		delete pointee_;
	}

private:
	StoredType pointee_;
};


template<typename T>
inline typename DefaultSPStorage<T>::PointerType GetImpl(const DefaultSPStorage<T>& sp)
{
	return sp.pointee_;
}

template<typename T>
inline const typename DefaultSPStorage<T>::StoredType& GetImplRef(const DefaultSPStorage<T>& sp)
{
	return sp.pointee_;
}

template<typename T>
inline typename DefaultSPStorage<T>::StoredType GetImplRef(DefaultSPStorage<T>& sp)
{
	return sp.pointee_;
}


template<typename T>
class Locker
{
private:
	Locker();
	Locker& operator=(const Locker&);
	T* pointee_;

public:
	Locker(const T* p) : pointee_(const_cast<T*>(p))
	{
		if (pointee_)
		{
			pointee_->Lock();
		}
	}

	~Locker()
	{
		if(pointee_)
		{
			pointee_->UnLock();
		}
	}

	operator T* ()
	{
		return pointee_;  // ?
	}

	T* operator->()
	{
		return pointee_;
	}
};


template<typename T>
class LockedStorage
{
public:
	using StoredType = T*;
	using InitPointerType = T*;
	using PointerType = Locker<T>;
	using ReferenceType = T&;

	LockedStorage() : pointee_(Default()) {}
	~LockedStorage() {}
	LockedStorage(const LockedStorage& p) : pointee_(nullptr) {}
	LockedStorage(const StoredType& p) : pointee_(p) {}
	PointerType operator->()
	{
		return Locker<T>(pointee_);
	}

	template<typename T>
	friend typename LockedStorage<T>::InitPointerType GetImpl(const LockedStorage<T>& sp);

	template<typename T>
	friend const typename LockedStorage<T>::StoredType& GetImplRef(const LockedStorage<T>& sp);

	template<typename T>
	friend typename LockedStorage<T>::StoredType& GetImplRef(LockedStorage<T>& sp);

protected:
	static InitPointerType Default() { return nullptr; }

private:
	StoredType pointee_;
};


template<typename T>
inline typename LockedStorage<T>::InitPointerType GetImpl(const LockedStorage<T>& sp)
{
	return sp.pointee_;
}

template<typename T>
inline const typename LockedStorage<T>::StoredType& GetImplRef(const LockedStorage<T>& sp)
{
	return sp.pointee_;
}

template<typename T>
inline typename LockedStorage<T>::StoredType& GetImplRef(LockedStorage<T>& sp)
{
	return sp.pointee_;
}


/*********************************************
* 出错检查策略
*********************************************/
template<typename T>
class NoCheck
{
public:
	NoCheck() {}

	template<typename P1>
	NoCheck(const NoCheck<P1>&) {}

	static void OnDefault(const T&) {}

	static void OnInit(const T&) {}

	static void OnDereference(const T&) {}

	static void Swap(NoCheck&) {}
};

template<typename T>
class AssertCheck
{
public:
	AssertCheck() {}

	template<typename P1>
	AssertCheck(const AssertCheck<P1>&) {}

	static void OnDefault(const T&) {}

	static void OnInit(const T&) {}

	static void OnDereference(const T& t) 
	{
		assert(t);
	}

	static void Swap(AssertCheck&) {}
};

template<typename T>
class AssertCheckStrict
{
public:
	AssertCheckStrict() {}

	template<typename P1>
	AssertCheckStrict(const AssertCheckStrict<P1>&) {}

	template<typename P1>
	AssertCheckStrict(const AssertCheck<P1>&) {}

	template<typename P1>
	AssertCheckStrict(const NoCheck<P1>&) {}

	static void OnDefault(const T& t) {
		assert(t);
	}

	static void OnInit(const T& t) {
		assert(t);
	}

	static void OnDereference(const T& t)
	{
		assert(t);
	}

	static void Swap(AssertCheckStrict&) {
		assert(t);
	}
};


class NullPointerException : public std::runtime_error
{
public:
	NullPointerException(): std::runtime_error(""){}

	const char* what() const noexcept
	{
		cout << "Null Pointer Exception" << endl;
	}
};

template<typename T>
class RejectNullStatic
{
public:
	RejectNullStatic() {}

	template <class P1>
	RejectNullStatic(const RejectNullStatic<P1>&)
	{}

	template <class P1>
	RejectNullStatic(const NoCheck<P1>&)
	{}

	template <class P1>
	RejectNullStatic(const AssertCheck<P1>&)
	{}

	template <class P1>
	RejectNullStatic(const AssertCheckStrict<P1>&)
	{}

	static void OnDefault(const T&)
	{
		static const bool DependedFalse = sizeof(T*) == 0;  // 有什么用？

	}
};


template<typename T>
class RefCounted
{
public:
	RefCounted(){}
};


//template
//<
//	typename T,
//	template <typename> class OwnershipPolicy,
//	template <typename> class CheckingPolicy,
//	template <typename> class ThreadingModel
//>
//class SmartPtr : public CheckingPolicy<T>, public ThreadingModel<SmartPtr>
//{
//	T* operator->()
//	{
//		typename ThreadingModel<SmartPtr>::Lock guard(*this);
//		CheckingPolicy<T>::Check(pointee_);
//		return pointee_;
//	}
//
//	LockingProxy<T> operator->() const
//	{
//		return LockingProxy<T>(pointee_);
//	}
//
//private:
//	T* pointee_;
//};