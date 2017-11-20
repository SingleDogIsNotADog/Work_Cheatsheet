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
	echo "Begin to build debug version of $server_name"
	sleep 1

	cd $server_path/workspace/server/src
	check_status $?

	svn up .

	echo "Building ..."
	sh cbuild.sh debug | grep warning
	echo "Down"

	cd $old_path
}

main
