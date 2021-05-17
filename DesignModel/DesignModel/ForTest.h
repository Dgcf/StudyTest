#pragma once

#include "Singletons.h"
#include "policy.h"

static int glo = Singletons2::Instance()->test();


void print_var();

void test_policy1();

