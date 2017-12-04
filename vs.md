[TOC]

# 相关设置

**设置字体**

工具 -> 选项 -> 环境 -> 字体和颜色

项背颜色的护眼色：204,232,207

**开启行号**

工具 -> 选项 -> 文本编辑器 -> 所有语言 -> 显示，开启行号

**资源管理器中跟踪源文件**

工具 -> 项目和解决方案 -> 常规，勾选在解决方案资源管理器中跟踪活动项

**取消中文的红色下划线**

顶部VAssistX -> Visual Assist Options -> Underlining -> 去掉Underline Spelling

# VS快捷键

- 全局查询：ctrl + shift + f

- 搜索文件中的函数：alt + m

- 跳到单词下一个位置：ctrl + f3

- 跳转大括号：ctrl + }

- 生成注释：ctrl + k，ctrl + c

- 取消注释：ctrl + k，ctrl + u

- ctrl + m + o: 折叠/展开当前块

- ctrl + m + l: 折叠/展开所有块

- 编译单个cpp文件：ctrl + f7

- 删除所有断点：ctrl + shift + f9

- 跳出当前函数体：shift + f11

- 打开附加到进程窗口：ctrl + alt + p

- 大写转小写：ctrl + u

- 小写转大写：ctrl + shift + u

# VS其他功能

**使用断点+条件调试**

键入F9在一行下断点后，在断点右侧右键，即可开启条件断点。

**使用书签**

书签可以标记代码位置，并给予一个说明，可以快速定位。

打开书签窗口：视图 -> 书签窗口

# VA快捷键

- 搜索项目文件：alt + shift + o

- 找名字：alt + shift + s

- 查询引用：alt + shift + f

- 头文件和源文件切换：alt + o

- 转到定义：alt + g

- 退回上一个视图：alt + 左键

- 全局改名：alt + shift + r

# VA其他功能

**快速包含头文件**

把鼠标放在类型名字上，按下面的箭头，可以找到自动添加头文件的按钮。

但是这样添加的头文件可能有格式的问题，比如使用了..，或者windows下的\符号，可能造成Linux下编译失败。因此还要检查一下。

**自定义代码模板**

打开编辑器：VAssistX -> Refector -> Edit Refactoring Snippets

然后就可以自行编辑代码模板。