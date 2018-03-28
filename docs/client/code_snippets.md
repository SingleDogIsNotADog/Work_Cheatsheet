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