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

## 如何从代码里获取一个UI对象

在UI控件的父节点的Inspector面板中，找到UI Name Table组件，其中有其子节点对应的名字以及其对应的UI控件。

然后在代码里使用father:FindObj("name")来获取对象：

```
self.reward_btn = self:FindObj("reward_btn")
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