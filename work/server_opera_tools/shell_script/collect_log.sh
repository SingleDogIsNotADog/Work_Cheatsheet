#! /bin/bash

server=$(sh ./get_server_name.sh)

serious_logs=/${server}/temp/log/gamelog_0/seriouserror/*
dblogs=/${server}/temp/log/dblog

main()
{
	grep 'Camp::LoadCampMemCache' $serious_logs
	grep -r 'RoleInit_4' $dblogs
}

main
