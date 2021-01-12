#pragma once


class BaseVisitor;

template<typename R=void>
class BaseVisitable
{
public:
	typedef R ReturnType;
	virtual ~BaseVisitable() {}
	virtual R Accept(BaseVisitor&) = 0;

protected:

};

