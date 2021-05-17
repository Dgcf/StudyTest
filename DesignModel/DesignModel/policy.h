#pragma once
#include "common.h"

template<class T>
struct OptNewCreator
{
	static T* Creator()
	{
		return new T;
	}
};

template<class T>
struct PrototypeCreator
{
	PrototypeCreator(T* obj = 0)
		: pPrototype_(obj)
	{

	}

	T* Create()
	{
		return pPrototype_;
	}

private:
	T* pPrototype_;
};


template<template<typename T> class CreationPolicy>
class WidgetManager: public CreationPolicy<int>
{
public:
	void test()
	{
		cout << "WidgetManager" << endl;
	}
};