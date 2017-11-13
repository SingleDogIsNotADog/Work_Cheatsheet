// 系统类模板
#ifndef __XXX_HPP__
#define __XXX_HPP__

#include "servercommon/xxxdef.hpp"
#include "obj/character/attribute.hpp"

class Role;

class XXX
{
public:
	XXX() : m_role(NULL) {}
	~XXX() {}

	void SetRole(Role *role) { m_role = role; }
	void InitParam(Role *role, const XXXParam &param) { m_role = role; m_param = param; }
	void GetInitParam(XXXParam *param)	{ *param = m_param; }
	
	void ReCalcAttr(CharIntAttrs &base_add, bool is_recalc);	// 重算系统加成属性
	
private:
	Role *m_role;
	XXXParam m_param;				// 系统参数
	CharIntAttrs m_attrs_add;		// 属性加成数值
};

#endif