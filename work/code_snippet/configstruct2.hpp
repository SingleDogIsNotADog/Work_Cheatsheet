struct XXXConfig
{
	struct CfgItem
	{
		int ReadConfig(TiXmlElement *data_element, int _seq, int _level)
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