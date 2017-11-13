@rem 提交代码，设置workplace即可
@echo off

set workplace=D:\mg55_cn\server

set commit_path1=%workplace%\sql_change
set commit_path2=%workplace%\src\gameworld
set commit_path3=%workplace%\src\crossserver
set commit_path4=%workplace%\src\dataaccess
set commit_path5=%workplace%\src\loginserver
set commit_path6=%workplace%\src\gateway
set commit_path7=%workplace%\src\servercommon
set commit_path8=%workplace%\src\scripts
set commit_path9=%workplace%\src\config

TortoiseProc.exe /closeonend:0 /command:commit /path:"%commit_path1%*%commit_path2%*%commit_path3%*%commit_path4%*%commit_path5%*%commit_path6%*%commit_path7%*%commit_path8%*%commit_path9%"