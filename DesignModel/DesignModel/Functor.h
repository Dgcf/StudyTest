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

template<typename R, class TList>
class Functor
{
public:
	Functor();
	Functor(const Functor&);
	Functor& operator=(const Functor&);
	explicit Functor(std::shared_ptr<Impl> spImpl);

private:
	typedef FunctorImpl<R, TList> Impl;
	std::shared_ptr<Impl> spImpl_;
};