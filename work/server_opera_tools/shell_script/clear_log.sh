#! /bin/bash

server=$(sh ./get_server_name.sh)

log_dir=/${server}/temp/log/

echo Stop server now
cd /$server/workspace/publish_debug
sh stop.sh

echo Remove all log files
rm -fr $log_dir

echo Start server now
cd /$server/workspace/publish_debug
sh start.sh
