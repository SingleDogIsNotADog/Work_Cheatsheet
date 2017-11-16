// 系统配置（X-XXX.xls）
#ifndef __XXX_CONFIG_HPP__
#define __XXX_CONFIG_HPP__

#include "config/gameconfigcommon/gameconfigcommon.h"
#include "servercommon/xxxdef.hpp"

// 其它
struct XxXOtherConfig
{
	XxXOtherConfig() { this->Reset(); }
	void Reset()
	{
	}
	
};

class XxXConfig
{
public:
	XxXConfig();
	~XxXConfig();

	bool Init(const std::string &configname, std::string *err);			// Called by LogicConfigManager::Init

	const XxXOtherConfig & GetOtherCfg() { return m_other_cfg; }

protected:
	int InitOtherCfg(TiXmlElement *root_element);

private:
	XxXOtherConfig m_other_cfg;
};

#endif
