### 时间相关

**获取当前时间戳**

```
$ date +%s
```

### 其他

**将文件编码转换，并输出到文件**

```shell
$ iconv -f gb2312 -t utf8 file_in -o file_out # file_in和file_out可以是同一个文件
```

**将当前目录下的所有文件（包括子目录）的修改时间改为当前时间**

```
$ find ./* -name "*" -exec touch {} \;
```

**字符串替换**

word是一个字符串"hello world"，将里面的hello替换成hi：

```
$ word="hello world"
$ word=$(echo $word | sed 's/hello/hi/g')
```
