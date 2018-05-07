# 代码小片段

---

## 发协议

```c++
// 给玩家发
SEND_TO_ROLE

// 发非定长协议给客户端，协议末尾是一个数组
SEND_TO_ROLE2

// 发送给周围能看到自己的玩家（包括自己）
SEND_TO_AREA

// 给场景中的所有玩家发
Scene::SendToRole

// 给所有在线玩家发
World::SendToAllGateway
```

## 发邮件

```c++
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

	int send_len = gstr::MailContent(contentparam.contenttxt, sizeof(contentparam.contenttxt), "key");
	if (send_len > 0)
	{
		MailRoute::MailToUser(m_role->GetUserId(), SYSTEM_MAIL_REASON_INVALID, contentparam);
	}
}

// 简单的发奖励邮件
gstr::MailContent(gamestring::GAMESTRING_BUF, sizeof(gamestring::GAMESTRING_BUF), "key");
gamecommon::MailToUser(uid, rewards, gamestring::GAMESTRING_BUF);
```

## 发传闻

```c++
// 发给全服
{
	int sendlen = gstr::SysMsgContent(gamestring::GAMESTRING_BUF, sizeof(gamestring::GAMESTRING_BUF), "key",
		);

	if (sendlen > 0)
	{
		SCENE_MGR->SystemMsgThread(gamestring::GAMESTRING_BUF, sendlen, SYS_MSG_CENTER_ROLL);
	}
}

// 发给国家
{
	int sendlen = gstr::SysMsgContent(gamestring::GAMESTRING_BUF, sizeof(gamestring::GAMESTRING_BUF), "key",
		);
	
	if (sendlen > 0)
	{
		SCENE_MGR->SystemMsgToCamp(camp_type, gamestring::GAMESTRING_BUF, sendlen);
	}
}

```

## 重算属性和战力

```c++
void XxX::ReCalcAttr(CharIntAttrs &base_add, bool is_recalc)
{
	if (is_recalc)
	{
		m_attrs_add.Reset();

		// add m_attrs_add
	}

	m_role->GetCapability()->ReCalcCap(CAPABILITY_TYPE_XXX, m_attrs_add);
	m_role->GetCapability()->AddCap(CAPABILITY_TYPE_XXX, m_other_capability); // 如果有的话

	base_add.Add(m_attrs_add.m_attrs);
}
```

## 其他

```c++
// 获取范围内的Obj对象
ObjID obj_list[64] = {0};
int count = scene->GetZoneMatrix()->GetObjByArea(center_pos, x_range, y_range, obj_list, sizeof(obj_list) / sizeof(obj_list[0]));
for (int i = 0; i < count; ++ i)
{
	// ...
}
```