// 系统配置（X-XXX.xls）
#ifndef __XXX_CONFIG_HPP__
#define __XXX_CONFIG_HPP__

#include "config/gameconfigcommon/gameconfigcommon.h"
#include "servercommon/xxxdef.hpp"

#define XXX_CFG() LOGIC_CONFIG->GetXxXCfg()
#define XXX_OTHER_CFG() LOGIC_CONFIG->GetXxXCfg().GetOtherCfg()

// 其它
struct XxXOtherConfig
{
	
};

class XxXConfig
{
public:
	bool Init(const std::string &configname, std::string *err);

	const XxXOtherConfig & GetOtherCfg() { return m_other_cfg; }

private:
	int InitOtherCfg(TiXmlElement *root_element);

private:
	XxXOtherConfig m_other_cfg;
};

#endif // __XXX_CONFIG_HPP__