@echo off

set server_name=ug03
set ssh_cmd=ssh 192.168.9.60 -p 18888 -i key_liudiwen -l root -oStrictHostKeyChecking=no -q

echo �ض������У�
echo.
echo ȫ�֣�1
echo ���ܣ�2
echo ����3
echo ���4
echo ��Ʒ��5
echo �߼���6
echo ���䣺7
echo ʱװ��8
echo ������9
echo.
set /p type="reload type: "

cd ../ssh
%ssh_cmd% "cd ~/ldw_workspace && sh reload_server_config.sh %type%"

pause
exit