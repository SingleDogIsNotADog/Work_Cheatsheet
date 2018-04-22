#<center>Coding Tips</center>

---

- 操作ObjID时候，要注意重置（比如死亡的时候），不然就可能误用到其他Obj

- 升级的前需要判断是否已满级

- 给予物品前，应当判断背包是否足够，并且要遵循**先消耗，后给予的原则**

- 单人副本，在进入场景时(OnRoleEnterScene)，判断场景中是否已有玩家，如果有，则需要踢出，见下面的代码片段：

```
if (m_is_finish || m_uid > 0)
{
	this->DelayKickOutRole(role);
	return;
}
```

- 执行SceneManager::GoTo后，Role将会失效，不能再使用了。