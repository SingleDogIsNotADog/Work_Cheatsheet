# 配置类定义

## 配置文件结构体

**xxxconfig.hpp**

```
// 系统配置（X-XXX.xls）
#ifndef __XXX_CONFIG_HPP__
#define __XXX_CONFIG_HPP__

#include "config/gameconfigcommon/gameconfigcommon.h"
#include "servercommon/xxxdef.hpp"

class XxXConfig
{
public:
	bool Init(const std::string &configname, std::string *err);

	const XxXOtherConfig & GetOtherCfg() { return m_other_cfg; }
	const XxXSomeConfig::CfgItem * GetCfgItem(int seq);

	bool IsValidSomeSeq(int seq, bool is_init = false);
	bool IsValidSomeSeqLevel(int seq, int level, bool is_init = false);
	
private:
	int InitOtherCfg(rapidxml::xml_node<> *root_element);
	int InitSomeCfg(rapidxml::xml_node<> *root_element);

private:
	XxXOtherConfig m_other_cfg;
	XxXSomeConfig m_some_cfg;
};

inline bool XxXConfig::IsValidSomeSeq(int seq, bool is_init)
{
	if (seq < 0 || seq >= SOME_CFG_MAX_COUNT) return false;
	if (!is_init && !m_some_cfg.cfg_item_list[seq].has_read) return false;
	
	return true;
}

inline bool XxXConfig::IsValidSomeSeqLevel(int seq, int level, bool is_init)
{
	if (seq < 0 || seq >= XXX_ITEM_MAX_COUNT || level < 0 || level >= XXX_SUB_ITEM_MAX_COUNT) return false;
	if (!is_init && !m_some_cfg.cfg_item_list[seq * XXX_SUB_ITEM_MAX_COUNT + level].has_read) return false;

	return true;
}

#endif // __XXX_CONFIG_HPP__
```

**xxxconfig.cpp**

```
#include "xxxconfig.hpp"

bool XxXConfig::Init(const std::string &configname, std::string *err)
{
	PRE_LOAD_CONFIG2;

	LOAD_CONFIG2("other", InitOtherCfg);

	return true;
}
```

## 配置表结构体

**hpp**

```
struct XXXConfig
{
	struct CfgItem
	{
		int ReadConfig(rapidxml::xml_node<> *data_element, int _seq)
		{
			if (has_read) return -1;
			has_read = 1;

			seq = _seq;

			return 0;
		}

		int has_read = 0;
		int seq = 0;					// 索引
		
	};
	
	CfgItem cfg_item_list[XXX_MAX_COUNT];
};
```

```
struct XXXConfig
{
	struct CfgItem
	{
		int ReadConfig(rapidxml::xml_node<> *data_element, int _seq, int _level)
		{
			if (has_read) return -1;
			has_read = 1;

			seq = _seq;
			level = _level;

			return 0;
		}

		int has_read = 0;
		int seq = 0;					// 索引
		int level = 0;

	};
	
	CfgItem cfg_item_list[XXX_ITEM_MAX_COUNT * XXX_SUB_ITEM_MAX_COUNT];
};
```

**cpp**

```
auto data_element = root_element->first_node("data");
while (data_element)
{
	int seq = 0;
	if (!ReadNonNegativeInt(data_element, "seq", seq) || !this->IsValidXXXSeq(seq, true)) return -1000;

	int ret = m_xxx_cfg.cfg_item_list[seq].ReadConfig(data_element, seq);
	if (ret != 0)
	{
		return ret;
	}

	data_element = data_element->next_sibling();
}

return 0;
```

```
auto data_element = root_element->first_node("data");
while (data_element)
{
	int seq = 0, level = 0;
	if (!ReadNonNegativeInt(data_element, "seq", seq) || !ReadNonNegativeInt(data_element, "level", level)) return -1000;

	if (!this->IsValidXXXSeqLevel(seq, level, true)) return -1001;

	int ret = m_xxx_cfg.cfg_item_list[seq * XXX_SUB_ITEM_MAX_COUNT + level].ReadConfig(data_element, seq, level);
	if (ret != 0)
	{
		return ret;
	}

	data_element = data_element->next_sibling();
}

return 0;
```