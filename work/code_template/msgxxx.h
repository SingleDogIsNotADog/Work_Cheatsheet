// 系统协议
#ifndef __MSG_XXX_HPP__
#define __MSG_XXX_HPP__

#include "servercommon/XXXdef.hpp"

#pragma pack(push) 
#pragma pack(4)

namespace Protocol
{
	enum XXX_REQ_TYPE 							// 操作类型
	{
		XXX_REQ_TYPE_INFO = 0,
		XXX_REQ_TYPE_XXX,

		XXX_REQ_TYPE_MAX,
	};

	class CSXXXOperaReq							// 协议号
	{
	public:
		CSXXXOperaReq();
		MessageHeader header;

		unsigned short req_type;
		unsigned short param_1;
		unsigned short param_2;
		unsigned short param_3;
	};

	class SCXXXInfo			 					// 协议号
	{
	public:
		SCXXXInfo();
		MessageHeader header;

		// 发给客户端的数据
	};
}

#pragma pack(pop)

#endif