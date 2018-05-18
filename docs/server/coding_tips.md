# Coding Tips

---

!!!note
	- 升级的前需要判断是否已满级。

	- 给予物品前，应当判断背包是否足够，并且要遵循**先消耗，后给予的原则**。

!!!warning
	- 执行SceneManager::GoTo成功后，Role将会失效，不能再使用了。

	- 操作ObjID时候，要注意重置（比如死亡的时候），不然就可能误用到其他Obj。

!!!Bug
	- 成员变量一定一定要初始化，不然使用到未初始化的变量，后果无法预知。

## 副本相关

单人副本，在进入场景时(OnRoleEnterScene)，判断场景中是否已有玩家，如果有，则需要踢出，见下面的代码片段：

```c++
if (m_is_finish || m_uid > 0)
{
	this->DelayKickOutRole(role);
	return;
}
```

副本逻辑设计要注意“开关”，比如OnFinish之前需要设置m_is_finish标记，并：

```c++
void OnFinish()
{
	if (m_is_finish) return; // 避免多次调用OnFinish
	m_is_finish = 1;
	// ...
}
```

要避免值为0的scene_key，其场景将被拒绝创建

## 特殊形象

玩家使用了特殊形象，那么需要把这个形象通知给其它玩家。

有这几种情况需要通知：

1. 玩家激活，把激活的信息发给（AOI）可视区域内的所有玩家

2. 有新的玩家进入可视区域，把玩家的信息（包括激活信息）发给他

3. 玩家登陆，告知玩家自己当前使用的形象

然后客户端就可以根据玩家的特殊形象信息来做显示了。

**第一种情况**，发送激活信息到AOI：

```cpp
static Protocol::SCXXX xxx;
Scene *scene = m_role->GetScene();
if (scene != NULL) 
{
    // 初始化协议
    scene->GetZoneMatrix()->NotifyAreaMsg(m_role->GetObserHandle(), (void*)&xxx, sizeof(xxx));
}
```

通常协议应该包含该玩家的objid，这样客户端才能正确显示。

**第二种情况**，修改 `SCVisibleObjEnterRole`，这个协议会在一个Obj进入玩家视野时发送。

添加相关形象的激活信息。

**第三种情况**，修改`SCRoleInfoAck`，这个协议会在玩家登陆时发送。