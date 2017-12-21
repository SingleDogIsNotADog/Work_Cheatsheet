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
	int ReadConfig(TiXmlElement *data_element)
	{
		if (has_read) return -1000;
		has_read = 1;
		
		if (!GetSubNodeValue(data_element, "some_data", some_data)) return -1;
		return 0;
	}
	
	int has_read = 0;
	int some_data = 0;
};

// 普通配置1
struct XxXSome1Config
{
	struct CfgItem
	{
		int ReadConfig(TiXmlElement *data_element, int _seq)
		{
			if (has_read) return -1000;
			has_read = 1;
			
			seq = _seq;
			if (!GetSubNodeValue(data_element, "some_data", some_data)) return -1;
			return 0;
		}
		
		int has_read = 0;
		int seq = 0;
		int some_data = 0;
	};
	
	CfgItem cfg_item_list[SOME1_CFG_MAX_COUNT];
};

class XxXConfig
{
public:
	bool Init(const std::string &configname, std::string *err);

	const XxXOtherConfig & GetOtherCfg() { return m_other_cfg; }
	const XxXSome1Config::CfgItem * GetCfgItem(int seq);

	bool IsValidSome1Seq(int seq, bool is_init = false);
	
private:
	int InitOtherCfg(TiXmlElement *root_element);
	int InitSome1Cfg(TiXmlElement *root_element);

private:
	XxXOtherConfig m_other_cfg;
	XxXSome1Config m_some1_cfg;
};

inline bool XxXConfig::IsValidSome1Seq(int seq, bool is_init = false)
{
	if (seq < 0 || seq >= SOME1_CFG_MAX_COUNT) return false;
	
	if (!is_init && !m_some1_cfg.cfg_item_list[seq].has_read) return false;
	
	return true;
}

#endif // __XXX_CONFIG_HPP__