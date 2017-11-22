# 什么是序列化？

序列化是将对象处理为字节流，从而存储对象或传输到内存、数据库或文件。 其主要目的是保存对象的状态，以便可以在需要时重新创建对象。相反的过程称为反序列化。

参见：https://msdn.microsoft.com/zh-cn/library/ms233843(v=vs.120).aspx

# 模板特例化

```
template<>
struct TLVTypeTraits<const char*>
{
	//...
};
```

什么是模板特例化（template specialization）？

类模板、类模板的成员或函数模板的重定义，其中指定了某些（或全部）模板参数。模板特例化版本必须出现在原模板的声明之后，必须出现在任何利用特殊实参来使用模板的代码之前。一个函数模板中的每个模板参数都必须完全特例化。

参见：《C++ Primer第五版》，p624。

# 写buffer的特殊姿势

通常的写buffer的方法，是使用sprintf，它使用格式化的方式将数据写入buffer，并返回实际写入的字符数。而且，会在末尾写入空字符。但需要序列化到buffer的数据不需要这个末尾的空字符，因此需要另一种写法。

见[示例代码](./src/main.cpp)。

# 什么是TLV？

- T：type，存储数据的类型，支持的类型定义在命名空间TLVType。

- L：length, 存储变长数据类型的数据长度。

- V：value, 数据内容。

一个数据，在buffer里要用这三个"字段"来表示，其中：

- T占据1个字节，见其定义：`typedef char TLVType_t;`

- L占据4个字节，见其定义：`typedef unsigned int TLVLength_t;`

- V占据的字节：`TLVTypeTraits<bool>::Length`

只有变长数据（DynLength），即`const char*`、`TLVSerializer`或者`TLVUnserializer`三种类型，才会使用L字段，因为定长类型的读写长度是确定了的。

# TLV类型列表

**TLVType_t**

可序列化的数据的类型。

**TLVLength_t**

序列化的变长数据的长度。

**TLVNull**

不知道干嘛用，看上去也没有什么用。

**TLVTypeTraits**

可序列化的类型的模板特例化。提供了一些静态接口，表示特定数据类型的性质。

**TLVSerializer**

序列化器，用于序列化其他类型的数据，也可以序列化TLVSerializer类型的数据。

**TLVUnserializer**

反序列化器，用于反序列化其他类型的数据，也可以反序列化TLVUnserializer类型的数据。
