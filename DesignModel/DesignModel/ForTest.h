#pragma once

#include "Singletons.h"
#include "policy.h"
#include "typelist.h"

static int glo = Singletons2::Instance()->test();

void print_var();

void test_policy1();

void test_typelist();

