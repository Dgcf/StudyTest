#pragma once

#include "typetraits.h"
#include "VariableTemp.h"
#include "VariableParameter.h"
#include "tem.h"
#include "Sfinae.h"


class ForTest
{
public:
	void test_conjunction();

	void test_is_same_type();

	void test_varitemp();

	void test_addressof();

	void test_voidtemp();

	void test_variable_parm();

	void test_sfinae();

	void test_variable_type();
};

