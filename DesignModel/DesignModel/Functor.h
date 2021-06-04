#pragma once

#include "typelist.h"

template<typename R, typename TList>
class FunctorImpl;

template<typename R>
class FunctorImpl<R, NullType>
{
public:
	virtual R operator()() = 0;
	virtual FunctorImpl* clone() const = 0;
	virtual ~FunctorImpl() {}
};

template<typename R, typename P1>
class FunctorImpl<R, TYPELIST_1(P1)>
{
public:
	virtual R operator()(P1) = 0;
	virtual FunctorImpl* Clone() const = 0;
	virtual ~FunctorImpl() {}
};

template<typename R, typename P1, typename P2>
class FunctorImpl<R, TYPELIST_2(P1, P2)>
{
public:
	virtual R operator()(P1, P2) = 0;
	virtual FunctorImpl* Clone() const = 0;
	virtual ~FunctorImpl() {}
};


template<typename ParentFunctor, typename MyFunc>
class FunctorHandler : public FunctorImpl
	<
	typename ParentFunctor::ResultType,
	typename ParentFunctor::ParmList
	>
{
public:
	typedef typename ParentFunctor::ResultType ResultType;
	FunctorHandler(const MyFunc& fun) : fun_(fun) {}

	FunctorHandler* Clone() const
	{
		return new FunctorHandler(*this);  // ?
	}

	ResultType operator()()
	{
		return fun_();
	}

	ResultType operator()(typename ParentFunctor::Parm1 p1)
	{
		return fun_(p1);
	}

	ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2)
	{
		return fun_(p1, p2);
	}

private:
	MyFunc fun_;
};


template<typename ParentFunctor, typename PointerToObj, typename PointerToMemFn>
class MemFunHandler : public FunctorImpl
	<
	typename ParentFunctor::ResultType,
	typename ParentFunctor::ParmList
	>
{
public:
	typedef typename ParentFunctor::ResulType ResultType;
	MemFunHandler(const PointerToObj& pObj, PointerToMemFn pMemFn)
		: pObj_(pObj)
		, pMemFn_(pMemFn)
	{}

	MemFunHandler* Clone() const
	{
		return new MemFunHandler(*this);
	}

	ResultType operator()()
	{
		return ((*pObj_).*pMemFn_)();
	}

	ResultType operator()(typename ParentFunctor::Parm1 p1)
	{
		return ((*pObj_).*pMemFn_)(p1);
	}

	ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2)
	{
		return ((*pObj_).*pMemFn_)(p1, p2);
	}

private:
	PointerToObj pObj_;
	PointerToMemFn pMemFn_;
};


template<typename R, class TList>
class Functor
{
public:
	typedef TList ParmList;
	typedef R ResultType;
	typedef FunctorImpl<R, TList> Impl;
	typedef typename tl::TypeAtNonStrict<TList, 0, EmptyType>::Result Parm1;
	typedef typename tl::TypeAtNonStrict<TList, 1, EmptyType>::Result Parm2;

public:
	Functor()
	{
	}

	Functor(const Functor&)
	{
	}

	Functor& operator=(const Functor&)
	{
	}

	explicit Functor(std::unique_ptr<Impl> spImpl)
	{
	}

	template<typename Func>
	Functor(const Func& func);  // 以仿函数Func之对象为参数的Functor构造函数,好像不支持函数指针
	

	ResultType operator()()
	{
		return (*spImpl_)();
	}

	ResultType operator()(Parm1 p1)
	{
		return (*spImpl_)(p1);
	}

	ResultType operator()(Parm1 p1, Parm2 p2)
	{
		return (*spImpl_)(p1, p2);
	}

	/*template<typename ...Args>
	ResultType operator()(Args... args)
	{
		ResultType tmp;
		return tmp;
	}*/

private:
	
	std::unique_ptr<Impl> spImpl_;
};

template<typename R, class TList>
template<typename Func>
inline Functor<R, TList>::Functor(const Func& fun)
	: spImpl_(new FunctorHandler<Functor, Func>(fun))  
{
}
