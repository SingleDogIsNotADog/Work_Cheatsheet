**发邮件**

```
{
	MailContentParam contentparam;

	contentparam.virtual_item_list.virtual_item[MAIL_VIRTUAL_ITEM_BIND_GOLD] = reward_gold_bind;

	const ItemBase *item_base = ITEMPOOL->GetItem(item_id);
	if (NULL != item_base)
	{
		contentparam.item_list[0].item_id = item_id;
		contentparam.item_list[0].num = num;
		contentparam.item_list[0].is_bind = is_bind ? 1 : 0;
		contentparam.item_list[0].invalid_time = item_base->CalInvalidTime();
	}

	int send_len = MailContent(contentparam.contenttxt, sizeof(contentparam.contenttxt), "key");
	if (send_len > 0)
	{
		MailRoute::MailToUser(m_role->GetUserId(), SYSTEM_MAIL_REASON_INVALID, contentparam);
	}
}
```

**发传闻**

```
int sendlen = gstr::SysMsgContent(gamestring::GAMESTRING_BUF, sizeof(gamestring::GAMESTRING_BUF), "key",
	);

if (sendlen > 0)
{
	SCENE_MGR->SystemMsgThread(gamestring::GAMESTRING_BUF, sendlen, SYS_MSG_CENTER_ROLL);
}
```

**广播形象**

```
RoleOtherFunc::BroadCastSpecialParamChange
```