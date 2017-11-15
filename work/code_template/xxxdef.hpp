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

typedef char XXXParamHex[sizeof(XXXParam) * 2 + 1];		// 存放到数据库字段的长度
UNSTD_STATIC_CHECK(sizeof(XXXParamHex) < 64);			// 数据库字段已定义大小为64字节

#pragma pack(pop)

#endif