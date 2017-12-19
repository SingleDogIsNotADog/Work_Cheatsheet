// 系统数据存储结构
#ifndef __XXX_DEF_HPP__
#define __XXX_DEF_HPP__

#include "servercommon.h"

#pragma pack(push, 4)

struct XxXParam
{
	XxXParam() { this->Reset(); }

	void Reset()
	{	
	}
};

using XxXParamHex = char[sizeof(XxXParam) * 2 + 1];
static_assert(sizeof(XxXParamHex) < 64, "Incorrect size");

#pragma pack(pop)

#endif // __XXX_DEF_HPP__