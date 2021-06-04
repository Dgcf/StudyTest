#pragma once

#include "common.h"

class BaseMay
{
public:
	void Eat() {
		cout << "BaseMay::Eat()" << endl;
	}
};

class DerivedMay: public BaseMay
{

};