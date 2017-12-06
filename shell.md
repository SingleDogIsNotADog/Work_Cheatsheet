# 时间相关

**获取当前时间戳**

```
$ date +%s
```

# 打包、解包

```
$ tar -zcv -f file.tar.gz <filelist> # 将文件打包成file.tar.gz
$ tar -zxv -f file.tar.gz # 在当前路径解压file.tar.gz
```

# 其他

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

或者使用参数扩展，这种方式效率更高：

```
$ word="hello world"
$ word=${word//hello/hi}
```
