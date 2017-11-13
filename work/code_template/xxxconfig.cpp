#include "xxxconfig.hpp"

XxXConfig::XxXConfig()
{
}

XxXConfig::~XxXConfig()
{
}

bool XxXConfig::Init(const std::string &configname, std::string *err)
{
	INIT_CFG_START();

	// 其他配置信息
	INIT_CFG_LIST(other, InitOtherCfg);

	return true;
}

int XxXConfig::InitOtherCfg(TiXmlElement *RootElement)
{
	TiXmlElement *data_element = RootElement->FirstChildElement("data");
	if (NULL == data_element)
	{
		return -10000;
	}

	// read value
	
	return 0;
}