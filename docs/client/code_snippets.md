# 协议

协议类型定义在文件protocol_xxx.lua中，xxx是协议号段，比如protocol_069.lua，定义的是6900 - 6999之间的协议。

## SC协议

```
SCXXX = SCXXX or BaseClass(BaseProtocolStruct)
function SCXXX:__init()
	self.msg_type = 8888
	self.count = 0
	self.item_list = {}
end

function SCXXX:Decode()
	self.count = MsgAdapter.ReadInt()
	self.item_list = {}
	
	for i = 1, self.count do
		local vo = {}
		vo.uid = MsgAdapter.ReadInt()
		vo.name = MsgAdapter.ReadStrN(32)
		vo.scene_id = MsgAdapter.ReadInt()
		vo.monster_id = MsgAdapter.ReadUShort()
		vo.item_id = MsgAdapter.ReadUShort()
		vo.drop_timestamp = MsgAdapter.ReadUInt()

		self.item_list[i] = vo
	end
end
```

## CS协议

```
CSXXX = CSXXX or BaseClass(BaseProtocolStruct)
function CSXXX:__init()
	self.msg_type = 6666
	self.is_auto_buy = 0
end

function CSXXX:Encode()
	MsgAdapter.WriteBegin(self.msg_type)
	MsgAdapter.WriteInt(self.is_auto_buy)
end
```

# 其他

**获取配置**

获取配置数据的接口由ConfigManager提供，它定义在文件：config_manager.lua

```
-- 获取一条配置
local gather_config = ConfigManager.Instance:GetAutoConfig("gather_auto").gather_list[self.vo.gather_id]
```

GetAutoConfig获取的是一张表，即gather_auto.lua里定义的表，然后直接访问其成员即可获取一条记录。

**获取时间相关**

```
local now_time = TimeCtrl.Instance:GetServerTime()  -- 获取服务器的当前时间
```

**获取场景类型：**

```
Scene.Instance:GetSceneType()
```

**获取场景中的对象**

场景中保存着视野中的Obj，可以通过一些列的Get方法获得。

```
-- 获得MainRole
local main_role = Scene.Instance:GetMainRole()

-- 获得所有的Role
local role_list = Scene.Instance:GetRoleList()
```

**拿到背包里某物品的个数**

```
ItemData.Instance:GetItemNumInBagById(item_id)
```

**获取主角色数据**

```
GameVoManager:GetMainRoleVo

local main_role_vo = GameVoManager.Instance:GetMainRoleVo()
```

它返回的是一个MainRoleVo对象，定义在文件game_vo.lua

**延迟执行函数**

```
GlobalTimerQuest:AddDelayTimer(func, time_sec)
```

**测试是否在跨服中**

```
if IS_ON_CROSSSERVER then
    -- do something
end
```

**播放提示字符串**

```
SysMsgCtrl:ErrorRemind
```

**调试打印**

```
print_log(msg)   -- 输出到正常输出窗口
print_error(msg) -- 输出的错误输出窗口
```

这个方法还可以输出调用堆栈，以及输出表的信息。

**输出调用堆栈**

```
print(debug.traceback())
```

debug.traceback()可以返回当前的调用堆栈字符串。

将调用堆栈输出至文件：

```
local file = io.open("traceback.txt", "w+")
file:write(debug.traceback())
file:flush()
```