#pragma once


template<int>
struct CompileTimeError;

template<> struct CompileTimeError<true> {};

#define DESIGN_STATIC_CHECK(expr, msg) \
  CompileTimeError<(expr!=0)> ERROR##msg;   // ÊÇ·ñ×ã¹»£¿