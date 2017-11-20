#! /bin/bash

server_name=$(sh ./get_server_name.sh)
hidden_server_path=/$server_name/hidden_server
server_path=/$server_name
old_path=$(pwd)

main()
{
	echo "Begin to restart hidden server $server_name"
	sleep 1

	cd $hidden_server_path/publish_debug
	sh stop.sh

	svn up ../config
	svn up ../scripts

	exe_bins=$(ls $server_path/workspace/publish_debug/EXE*)
	cp -v $exe_bins .

	sh start.sh
	sh checkstatus.sh

	cd $old_path
}

main
