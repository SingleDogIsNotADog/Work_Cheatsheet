## 目录相关

```dos
md d:\test								rem 在D盘根目录创建一个目录test
md test									rem 在当前目录创建一目录test

cd test									rem 切换到当前目录下的test目录
cd /D d:\project\testdos\test			rem 从任意目录切换到d:\project\testdos\test目录

rd /S /Q test 							rem 删除test目录及其所有内容，不询问
```

## 文件相关

```dos
copy /Y test.txt test\					rem 把test.txt文件复制到test目录下，不询问
xcopy /S test d:\test2\					rem 把test目录和其所有内容拷贝到d盘根目录下的test2目录

copy /B file +,,						rem 更新file的修改日期为当前日期

ren old_name new_name					rem 修改文件名

del file_name							rem 删除文件
del /S /Q * > nul 2>&1					rem 此命令删掉了当前目录及其子目录中所有文件，且不会提示任何信息
```

## 其他

```dos
help copy								rem 查看copy命令的使用方法

title ug04_cn							rem 把窗口标题设置为ug04_cn

@echo hello								rem 输出hello，@的功能是让命令内容不回显
@echo off								rem 关闭命令回显
echo.									rem 输出换行

echo 完毕 & pause > nul                 rem 暂停，输出自定义的提示，这里是完毕
```

## 脚本案例

```
@echo off
set /a var=0							rem 设置一个变量，/a表示此变量是数字

:start
set /a var+=1
echo %var%
if %var% leq 3 goto start
pause
```