@echo off
@rem 这是一个操作开发服的工具
@rem author: liudiwen

:loop
echo.
echo Select Menu:
echo.
echo 1. 重读配置
echo 2. 重启服务器
echo 3. 重启跨服
echo.
echo 0. 退出
echo.
set /p choice="Your choice: "

if %choice%==1 (
	start /w reload_server_config.bat
) else if %choice%==2 (
	start /w restart_server.bat
) else if %choice%==3 (
	start /w restart_hidden_server.bat
) else (
	echo Bye
	goto end
)
cls
goto loop

:end
pause()