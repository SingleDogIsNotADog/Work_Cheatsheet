auto data_element = root_element->FirstChildElement("data");
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

	data_element = data_element->NextSiblingElement();
}

return 0;