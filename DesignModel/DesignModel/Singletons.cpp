#include "Singletons.h"

Singletons1* Singletons1::pInstance_ = nullptr;
int Singletons1::count_ = 0;

Singletons2 Singletons2::Instance_;


void test_singleton1()
{
    Singletons1* s = Singletons1::Instance();
    s->Wt("./11.log");
    Singletons1::Wt("./22.log");
}

void test_singleton2()
{
    
}
