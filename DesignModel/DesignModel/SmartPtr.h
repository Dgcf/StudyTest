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