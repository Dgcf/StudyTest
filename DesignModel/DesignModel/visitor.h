#pragma once

#include "common.h"

class BaseVisitor
{
public:
	virtual ~BaseVisitor()
	{

	}
};


template<typename T, typename R=void>
class Visitor
{
public:
	typedef R ReturnType;
	virtual ReturnType Visit(T&) = 0;

};