struct XXXConfig
{
	struct CfgItem
	{
		int ReadConfig(TiXmlElement *data_element, int _seq)
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

/////////////////////////////////////////////////////////////////

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