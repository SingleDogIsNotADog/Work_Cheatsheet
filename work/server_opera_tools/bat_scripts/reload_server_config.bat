@echo off

set server_name=ug03
set ssh_cmd=ssh 192.168.9.60 -p 18888 -i key_liudiwen -l root -oStrictHostKeyChecking=no -q

echo 重读类型有：
echo.
echo 全局：1
echo 技能：2
echo 任务：3
echo 怪物：4
echo 物品：5
echo 逻辑：6
echo 掉落：7
echo 时装：8
echo 场景：9
echo.
set /p type="reload type: "

cd ../ssh
%ssh_cmd% "cd ~/ldw_workspace && sh reload_server_config.sh %type%"

pause
exit