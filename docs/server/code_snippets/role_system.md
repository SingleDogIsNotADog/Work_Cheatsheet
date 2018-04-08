# 角色系统类定义

**xxx.hpp**

```
#ifndef __XXX_HPP__
#define __XXX_HPP__

#include "servercommon/xxxdef.hpp"
#include "obj/character/attribute.hpp"

class Role;

class XxX
{
public:
	XxX() : m_role(nullptr) {}
	~XxX() {}

	void SetRole(Role *role) { m_role = role; }
	void InitParam(Role *role, const XxXParam &param) { m_role = role; m_param = param; }
	void GetInitParam(XxXParam *param)	{ *param = m_param; }
	
	void ReCalcAttr(CharIntAttrs &base_add, bool is_recalc);
	
private:
	Role *m_role;
	XxXParam m_param;				// 系统参数
	CharIntAttrs m_attrs_add;		// 属性加成数值
};

#endif // __XXX_HPP__
```