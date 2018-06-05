**.vimrc文件设定**

```
set nu
set fileencoding=utf8
set nobackup
set autoindent
set tabstop=4
```

**字符串替换**

```
# 将全文的old替换成new
:%s/old/new/g

# 将20到27行的old替换成new
:20,27s/old/new/g
```

**其他**

```
# 跳转到指定行，如跳到第3行，敲入3gg
ngg
```