#! /bin/bash

server_name=$(sh ./get_server_name.sh)
server_path=/$server_name
old_path=$(pwd)

check_status()
{
	if [ "$1" != "0" ]; then
		cd $old_path
		exit 1
	fi
}

main()
{
	echo "Begin to restart server $server_name"
	sleep 1

	cd $server_path/workspace/server
	check_status $?
	sh publish_debug.sh

	cd $server_path/workspace/publish_debug
	sh start.sh
	sh checkstatus.sh

	cd $old_path
}

main
