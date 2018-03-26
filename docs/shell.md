# 常用快捷键
	
```
CTRL+C              # 结束当前命令
CTRL+D              # 删除光标前的字符，同 <Delete> ，或者没有内容时，退出会话，或者交互模式输入文件结束符EOF
CTRL+K              # 删除光标位置到行末的内容
CTRL+U              # 删除光标位置到行首的内容
CTRL+W              # 删除光标左边的一个单词
CTRL+Z              # 暂停前台进程返回 bash，需要时可用 fg 将其切换回前台
```

# Shell命令

## Bash基本操作

```
exit                # 退出当前登陆
env                 # 显示环境变量
echo $SHELL         # 显示你在使用什么 SHELL

whereis bash        # 查找 bash 在哪里
which bash          # 查找哪个程序对应命令 bash

clear               # 清初屏幕内容
reset               # 重置终端（当你不小心 cat 了一个二进制，终端状态乱掉时使用）
```


## 目录操作

```
cd                  # 返回自己 $HOME 目录
cd {dirname}        # 进入目录
cd -                # 回到之前的目录
pwd                 # 显示当前所在目录
mkdir {dirname}     # 创建目录
mkdir -p {dirname}  # 递归创建目录
```

## 文件操作

```
ls                  # 显示当前目录内容，后面可接目录名：ls {dir} 显示指定目录
ls -l               # 列表方式显示目录内容，包括文件日期，大小，权限等信息
ls -a               # 显示所有文件和目录，包括隐藏文件（.开头的文件/目录名）
ln -s {fn} {link}   # 给指定文件创建一个软链接
cp {src} {dest}     # 拷贝文件，cp -r dir1 dir2 可以递归拷贝（目录）
rm {fn}             # 删除文件，rm -r 递归删除目录，rm -f 强制删除
mv {src} {dest}     # 移动文件，如果 dest 是目录，则移动，是文件名则覆盖
touch {fn}          # 创建或者更新一下制定文件
cat {fn}            # 输出文件原始内容
any_cmd > {fn}      # 执行任意命令并将标准输出重定向到指定文件
more {fn}           # 逐屏显示某文件内容，空格翻页，q 退出
head {fn}           # 显示文件头部数行，可用 head -3 abc.txt 显示头三行
tail {fn}           # 显示文件尾部数行，可用 tail -3 abc.txt 显示尾部三行
tail -f {fn}        # 持续显示文件尾部数据，可用于监控日志
vim {fn}            # 使用 vim 编辑文件
diff {f1} {f2}      # 比较两个文件的内容
wc {fn}             # 统计文件有多少行，多少个单词
chmod 644 {fn}      # 修改文件权限为 644，可以接 -R 对目录循环改权限
chown user1 {fn}    # 修改文件所有人为 user1, chown user1:group1 fn 可以修改组
grep {pat} {fn}     # 在文件中查找出现过 pat 的内容
grep -r {pat} .     # 在当前目录下递归查找所有出现过 pat 的文件内容
```

## 用户管理

```
whoami              # 显示我的用户名
passwd              # 修改密码，passwd {user} 可以用于 root 修改别人密码
last {user}         # 显示登陆记录
w                   # 查看谁在线
su -                # 切换到 root 用户并登陆（执行登陆脚本）
su -{user}          # 切换到某用户并登陆（执行登陆脚本）
id {user}           # 查看用户的 uid，gid 以及所属其他用户组
```

## 进程管理

```
ps                        # 查看当前会话进程
ps ax                     # 查看所有进程，类似 ps -e
ps aux                    # 查看所有进程详细信息，类似 ps -ef
ps -u {user}              # 查看某用户进程
ps aux | grep httpd       # 查看名为 httpd 的所有进程
kill {pid}                # 结束进程
kill -9 {pid}             # 强制结束进程，9/SIGKILL 是强制不可捕获结束信号
kill -l                   # 查看所有信号
kill -l TERM              # 查看 TERM 信号的编号
top                       # 查看最活跃的进程
top -u {user}             # 查看某用户最活跃的进程
any_command &             # 在后台运行某命令，也可用 CTRL+Z 将当前进程挂到后台
jobs                      # 查看所有后台进程（jobs）
bg                        # 查看后台进程，并切换过去
fg                        # 切换后台进程到前台
fg {job}                  # 切换特定后台进程到前台
trap cmd sig1 sig2        # 在脚本中设置信号处理命令
trap "" sig1 sig2         # 在脚本中屏蔽某信号
trap - sig1 sig2          # 恢复默认信号处理行为
```

## 其他命令

```
ssh user@host             # 以用户 user 登陆到远程主机 host
ssh -p {port} user@host   # 指定端口登陆主机

uname -a                  # 查看内核版本等信息
man {help}                # 查看帮助
uptime                    # 查看系统启动时间
date                      # 显示日期
cal                       # 显示日历
vmstat                    # 显示内存和 CPU 使用情况
vmstat 10                 # 每 10 秒打印一行内存和 CPU情况，CTRL+C 退出
free                      # 显示内存和交换区使用情况
df                        # 显示磁盘使用情况
du                        # 显示当前目录占用，du . --max-depth=2 可以指定深度

wget {url}                # 下载文件，可加 --no-check-certificate 忽略 ssl 验证
sz {file}                 # 发送文件到终端，zmodem 协议
rz                        # 接收终端发送过来的文件

tar -zcv -f file.tar.gz {filelist} # 将文件打包成file.tar.gz
tar -zxv -f file.tar.gz            # 在当前路径解压file.tar.gz
```

# Shell脚本

## 变量操作

```
varname=value             # 定义变量
echo $varname             # 查看变量内容
${#varname}               # 返回字符串长度

echo $$                   # 查看当前 shell 的进程号
echo $?                   # 查看最近一条命令的返回码
export VARNAME=value      # 设置环境变量（将会影响到子进程）

array[0]=valA             # 定义数组
array[1]=valB
array[2]=valC
array=(valA valB valC)    # 另一种方式

${array[i]}               # 取得数组中的元素
${#array[@]}              # 取得数组的长度
${#array[i]}              # 取得数组中某个变量的长度

${varname:-word}          # 如果变量不为空则返回变量，否则返回 word
${varname:=word}          # 如果变量不为空则返回变量，否则赋值成 word 并返回
${varname:+word}          # 如果变量不为空则返回 word，否则返回 null
${varname:offset:len}     # 取得字符串的子字符串`

${variable#pattern}       # 如果变量头部匹配 pattern，则删除最小匹配部分返回剩下的
${variable##pattern}      # 如果变量头部匹配 pattern，则删除最大匹配部分返回剩下的
${variable%pattern}       # 如果变量尾部匹配 pattern，则删除最小匹配部分返回剩下的
${variable%%pattern}      # 如果变量尾部匹配 pattern，则删除最大匹配部分返回剩下的
${variable/pattern/str}   # 将变量中第一个匹配 pattern 的替换成 str，并返回
${variable//pattern/str}  # 将变量中所有匹配 pattern 的地方替换成 str 并返回

$(cmd)                    # 运行cmd命令，并将标准输出内容捕获并返回
varname=$(id -u user)     # 将用户名为 user 的 uid 赋值给 varname 变量

num=$((1 + 2))            # 计算 1+2 赋值给 num，使用 bash 独有的 $((..)) 计算
num=$(($num + 1))         # 变量递增
num=$((num + 1))          # 变量递增，双括号内的 $ 可以省略
num=$((1 + (2 + 3) * 2))  # 复杂计算
```

## 函数

```
# 定义一个新函数
function myfunc() {
	# $1 代表第一个参数，$N 代表第 N 个参数
	# $# 代表参数个数
	# $0 代表被调用者自身的名字
	# $@ 代表所有参数，类型是个数组 
	# $* 空格链接起来的所有参数，类型是字符串
	{shell commands ...}
}

myfunc                    # 调用函数 myfunc 
myfunc arg1 arg2 arg3     # 带参数的函数调用
```

## 条件判断

```
statement1 && statement2  # and 操作符
statement1 || statement2  # or 操作符

exp1 -a exp2              # exp1 和 exp2 同时为真时返回真
exp1 -o exp2              # exp1 和 exp2 有一个为真就返回真
! expression              # 如果 expression 为假那返回真

str1 = str2               # 判断字符串相等，如 [ "$x" = "$y" ] && echo yes
str1 != str2              # 判断字符串不等，如 [ "$x" != "$y" ] && echo yes
str1 < str2               # 字符串小于，如 [ "$x" \< "$y" ] && echo yes
str2 > str2               # 字符串大于，注意 < 或 > 是字面量，输入时要加反斜杆
-n str1                   # 判断字符串不为空（长度大于零）
-z str1                   # 判断字符串为空（长度等于零）

-a file                   # 判断文件存在，如 [ -a /tmp/abc ] && echo "exists"
-d file                   # 判断文件存在，且该文件是一个目录
-f file                   # 判断文件存在，且该文件是一个普通文件（非目录等）
-r file                   # 判断文件存在，且可读
-w file                   # 判断文件存在，且可写
-x file                   # 判断文件存在，且执行

num1 -eq num2             # 数字判断：num1 == num2
num1 -ne num2             # 数字判断：num1 != num2
num1 -lt num2             # 数字判断：num1 < num2
num1 -le num2             # 数字判断：num1 <= num2
num1 -gt num2             # 数字判断：num1 > num2
num1 -ge num2             # 数字判断：num1 >= num2
```

## 分支控制：if 和经典 test

```
test {expression}         # 判断条件为真的话 test 程序返回0 否则非零
[ expression ]            # 判断条件为真的话返回0 否则非零

test "abc" = "def"        # 查看返回值 echo $? 显示 1，因为条件为假
test "abc" != "def"       # 查看返回值 echo $? 显示 0，因为条件为真

test -e /tmp; echo $?     # 调用 test 判断 /tmp 是否存在，并打印 test 的返回值
[ -f /tmp ]; echo $?      # 和上面完全等价，/tmp 肯定是存在的，所以输出是 0

test cond && cmd1         # 判断条件为真时执行 cmd1
[ cond ] && cmd1          # 和上面完全等价
[ cond ] && cmd1 || cmd2  # 条件为真执行 cmd1 否则执行 cmd2

# 判断 /etc/passwd 文件是否存在
# 经典的 if 语句就是判断后面的命令返回值为0的话，认为条件为真，否则为假
if test -e /etc/passwd; then
	echo "alright it exists ... "
else
	echo "it doesn't exist ... "
fi

# 和上面完全等价，[ 是个和 test 一样的可执行程序，但最后一个参数必须为 ]
# 这个名字为 "[" 的可执行程序一般就在 /bin 或 /usr/bin 下面，比 test 优雅些
if [ -e /etc/passwd ]; then   
	echo "alright it exists ... "
else
	echo "it doesn't exist ... "
fi

# 和上面两个完全等价
[ -e /etc/passwd ] && echo "alright it exists" || echo "it doesn't exist"

# 判断变量的值
if [ "$varname" = "foo" ]; then
	echo "this is foo"
elif [ "$varname" = "bar" ]; then
	echo "this is bar"
else
	echo "neither"
fi

# 复杂条件判断，注意，小括号是字面量，实际输入时前面要加反斜杆
if [ \( $x -gt 10 \) -a \( $x -lt 20 \) ]; then
	echo "yes, between 10 and 20"
fi
```

## 流程控制：while / for / case / until

```
# while 循环
while condition; do
	statements
done

i=1
while [ $i -le 10 ]; do
	echo $i; 
	i=$(expr $i + 1)
done

# for 循环：上面的 while 语句等价
for i in {1..10}; do
	echo $i
done

for name [in list]; do
	statements
done

# for 列举某目录下面的所有文件
for f in /home/*; do 
	echo $f
done

# case 判断
case expression in 
	pattern1 )
		statements ;;
	pattern2 )
		statements ;;
	* )
		otherwise ;;
esac

# until 语句
until condition; do
	statements
done
```

## 其他有趣的脚本

```
# 将文件编码转换，并输出到文件，file_in和file_out可以是同一个文件
iconv -f gb2312 -t utf8 file_in -o file_out

# 将当前目录下的所有文件（包括子目录）的修改时间改为当前时间
find ./* -name "*" -exec touch {} \;

showkey -a                           # 取得按键的 ASCII 码
lsof -i port:80                      # 哪个程序在使用 80 端口？
```

# 文本处理

## grep

```
grep 'Error' file                  # 在file中检索包含Error的行
grep -r 'Error' *                  # 在当前目录及其子目录中检索包含Error的行
grep -l 'Error' *                  # 在当前目录及其子目录中检索包含Error的行，只输出相关文件名
grep -v 'Error' file               # 在file中检索包含Error的行，只输出不匹配的行
```

## cut

```
cut -c 1-16                        # 截取每行头16个字符
cut -c 1-16 file                   # 截取指定文件中每行头 16个字符
cut -c3-                           # 截取每行从第三个字符开始到行末的内容
cut -d':' -f5                      # 截取用冒号分隔的第五列内容
cut -d';' -f2,10                   # 截取用分号分隔的第二和第十列内容
cut -d' ' -f3-7                    # 截取空格分隔的三到七列
echo "hello" | cut -c1-3           # 显示 hel
echo "hello sir" | cut -d' ' -f2   # 显示 sir
```

## awk / sed

```
awk '{print $5}' file              # 打印文件中以空格分隔的第五列
awk -F ',' '{print $5}' file       # 打印文件中以逗号分隔的第五列
awk '/str/ {print $2}' file        # 打印文件中包含 str 的所有行的第二列
awk -F ',' '{print $NF}' file      # 打印逗号分隔的文件中的每行最后一列

sed 's/regex/replace/g' file       # 替换文件中所有出现的字符串
sed -i 's/find/replace/g' file     # 替换文件中所有出现的字符并且覆盖文件
sed -i -r 's/^\s+//g' file         # 删除文件每行头部空格
sed '/^$/d' file                   # 删除文件空行并打印
sed -i 's/\s\+$//' file            # 删除文件每行末尾多余空格

sed '1i\Hello' file                # 在文件file的第一行插入Hello
```

# 参考资料

https://github.com/skywind3000/awesome-cheatsheets