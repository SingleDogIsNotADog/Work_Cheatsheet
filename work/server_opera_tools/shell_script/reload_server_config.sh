#! /bin/bash
# 重读服务器配置（热更）

server_name=$(sh ./get_server_name.sh)
server_path=/$server_name
old_path=$(pwd)

reload_type=$1

reload_func()
{
	mysql --socket=/data/game/mysql/mysql-3306.sock -u devel -pE3ERd6OZqF $server_name -e "insert into command (creator, type, cmd) values ('background', 2, 'Cmd Reload $reload_type 0 0')"

	echo "reload command already send, just wait for few second"
}

main()
{
	case "$reload_type" in
		1|2|3|4|5|6|7|8|9) reload_func ;;
		*) echo "wrong reload type $reload_type";;
	esac
}

main
