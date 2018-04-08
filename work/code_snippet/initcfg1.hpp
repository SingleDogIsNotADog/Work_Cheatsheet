bool XxXConfig::Init(const std::string &configname, std::string *err)
{
	PRE_LOAD_CONFIG2;

	LOAD_CONFIG2("other", InitOtherCfg);

	return true;
}

/////////////////////////////////////////////////////////////////////////

auto data_element = root_element->FirstChildElement("data");
while (data_element)
{
	int seq = 0;
	if (!ReadNonNegativeInt(data_element, "seq", seq) || !this->IsValidXXXSeq(seq, true)) return -1000;

	int ret = m_xxx_cfg.cfg_item_list[seq].ReadConfig(data_element, seq);
	if (ret != 0)
	{
		return ret;
	}

	data_element = data_element->NextSiblingElement();
}

return 0;

////////////////////////////////////////////////////////////////////////

auto data_element = root_element->first_node("data");
while (data_element)
{
	int seq = 0;
	if (!GetSubNodeValue(data_element, "seq", seq) || !this->IsValidXXXSeq(seq, true)) return -1000;

	int ret = m_xxx_cfg.cfg_item_list[seq].ReadConfig(data_element, seq);
	if (ret != 0)
	{
		return ret;
	}

	data_element = data_element->next_sibling();
}

return 0;