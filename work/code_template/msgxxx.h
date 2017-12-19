// 系统协议
#ifndef __MSG_XXX_HPP__
#define __MSG_XXX_HPP__

#include "servercommon/xxxdef.hpp"

#pragma pack(push, 4)

namespace Protocol
{
	enum XXX_REQ_TYPE
	{
		XXX_REQ_TYPE_INFO = 0,
		XXX_REQ_TYPE_XXX,

		XXX_REQ_TYPE_MAX,
	};

	// 协议号
	class CSXxXOperaReq
	{
	public:
		CSXxXOperaReq();
		MessageHeader header;

		unsigned short req_type;
		unsigned short param_1;
		unsigned short param_2;
		unsigned short param_3;
	};

	// 协议号
	class SCXxXInfo
	{
	public:
		SCXxXInfo();
		MessageHeader header;

		
	};
}

#pragma pack(pop)

#endif // __MSG_XXX_HPP__