#pragma once
#include "common.h"

template<typename, typename>
constexpr int tem_str1 = 11;

template<typename T>
constexpr int tem_str1<T, T> = 12;
