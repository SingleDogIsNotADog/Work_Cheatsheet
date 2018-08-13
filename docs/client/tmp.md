# 临时记录

---

## 客户端读取服列表

相关配置在文件：global_config.lua，搜索` http://`。

## 代码提交

提交时忽略文件：.asset, main.unity

## 如何修改View

- 运行游戏，切换到Scene面板，选中相关的UI，找到Hierarchy面板上对应的View

- 关掉游戏

- 在Project下面搜索这个View名字，把View的预制体拖曳到Hierarchy面板里，然后编辑预制体

- 编辑完毕Apply，再把它从Hierarchy面板移除，重启游戏观察改动

## 找到一个按钮在代码中的位置

**在Hierarchy面板中找到GameObject的方法**

先切换到Scene视图。

0. 如果知道GameObject的名字，就在Hierarchy面板中搜索框中搜索GameObject名字，搜索到后，按F键定位。

0. 先点击一下其他面板的空白地方，再使用左键拖动一个矩形框选GameObject（或单击选择）。在Hierarchy面板找到对应的GameObject。

在Inspector的UI Variable Bind Active(Script)组件中，找到Variables Name属性，然后在客户端代码里全局搜索，如果出现了这样的代码就代表找到了：

```lua
self.xxx = self:FindVariable("xxx")
```

## UI操作

### 按钮

**创建：**

- 右键父节点 -> UI -> Button

- 删掉原有的Button组件

- 添加组件：UI Grayscale, Button Ex, UI Event Bind Click

**设置灰度（UI Grayscale组件）：**

```
self.reward_btn.grayscale.GrayScale = 255
```

**设置是否可点击（Button Ex组件）：**

```
self.reward_btn.button.interactable = false
```

**处理点击事件（UI Event Bind Click组件）：**

self:ListenEvent("reward_click", BindTool.Bind(self.RewardOnClick, self))

这个reward_click名字可以在父节点的UI Name Table里添加定义。

### 文本

**创建：**

右键父节点 -> UI -> Text

添加相关的组件。

**绑定到变量：**

为UI添加一个UI Variable Bind Text组件，然后添加一个给它。这样当这个变量修改的时候，文本也会自动跟着修改。