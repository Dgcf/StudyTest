#pragma once
#include "common.h"

class TypeInfo
{
public:
	TypeInfo();
	TypeInfo(const std::type_info&);
	TypeInfo(const TypeInfo&);
	TypeInfo& operator=(const TypeInfo&);

	bool before(const TypeInfo&);
	const char* name() const;

private:
	const std::type_info* pInfo_;
};