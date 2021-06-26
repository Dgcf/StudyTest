#pragma once
#include "common.h"


template<typename T, typename Y>
class TypeList
{
	typedef T Head;
	typedef Y Tail; 
};

//template<typename Head, typename Tail>
//class TypeAt<0, TypeList<Head, Tail>>
//{
//	typedef Head Result;
//};
//
//template<unsigned int i, typename Head, typename ...Tail>
//class TypeAt
//{
//public:
//	typedef typename TypeAt<i-1, ...Tail>::Result Result;
//};




template<typename ...Args>
struct function_traits
{
    static const size_t nargs = sizeof...(Args);

    //typedef R result_type;

    template <size_t i>
    struct arg
    {
        typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
    };

    typename typedef arg<0>::type Result1;
    typename typedef arg<1>::type Result2;
    typename typedef arg<2>::type Result3;
    typename typedef arg<3>::type Result4;
    //typename typedef arg<4>::type Result5;

    template<size_t i>
    typename arg<i>::type GetNum()
    {
        return "hello";
    }

};



