#include "xxxconfig.hpp"

bool XxXConfig::Init(const std::string &configname, std::string *err)
{
	INIT_CFG_START();

	INIT_CFG_LIST(other, InitOtherCfg);

	return true;
}

int XxXConfig::InitOtherCfg(TiXmlElement *root_element)
{
	TiXmlElement *data_element = root_element->FirstChildElement("data");
	if (NULL == data_element)
	{
		return -10000;
	}

	// ...
	
	return 0;
}