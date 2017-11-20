@echo off

set server_name=ug03
set ssh_cmd=ssh 192.168.9.60 -p 18888 -i key_liudiwen -l root -oStrictHostKeyChecking=no -q

cd ../ssh
%ssh_cmd% "cd ~/ldw_workspace && sh restart_hidden_server.sh"

pause
exit