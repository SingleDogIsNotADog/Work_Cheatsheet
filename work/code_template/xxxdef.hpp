// 系统数据存储结构
#ifndef __XXX_DEF_HPP__
#define __XXX_DEF_HPP__

#include "servercommon.h"

#pragma pack(push, 4)

struct XXXParam
{
	XXXParam() { this->Reset(); }

	void Reset()
	{
		
	}

	
};

typedef char XXXParamHex[sizeof(XXXParam) * 2 + 1];
UNSTD_STATIC_CHECK(sizeof(XXXParamHex) < 64);

#pragma pack(pop)

#endif
