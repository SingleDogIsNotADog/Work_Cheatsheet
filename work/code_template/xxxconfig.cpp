#include "xxxconfig.hpp"

bool XxXConfig::Init(const std::string &configname, std::string *err)
{
	INIT_CFG_START();

	INIT_CFG_LIST(other, InitOtherCfg);
	INIT_CFG_LIST(some1, InitSome1Cfg);

	return true;
}

const XxXSome1Config::CfgItem * XxXConfig::GetCfgItem(int seq)
{
	if (!this->IsValidSome1Seq(seq)) return nullptr;
	
	return &m_some1_cfg.cfg_item_list[seq];
}

int XxXConfig::InitOtherCfg(TiXmlElement *root_element)
{
	TiXmlElement *data_element = root_element->FirstChildElement("data");
	if (data_element)
	{
		// ...
	}

	return 0;
}

int XxXConfig::InitSome1Cfg(TiXmlElement *root_element)
{
	TiXmlElement *data_element = root_element->FirstChildElement("data");
	while (data_element)
	{
		int seq = 0;
		if (!ReadNonNegativeInt(data_element, "seq", seq) || !this->IsValidSome1Seq(seq, true)) return -10000;
		
		int ret = m_some1_cfg.cfg_item_list[seq].ReadConfig(data_element, seq);
		if (ret != 0)
		{
			return ret;
		}
		
		data_element = data_element->NextSiblingElement();
	}
	
	return 0;
}