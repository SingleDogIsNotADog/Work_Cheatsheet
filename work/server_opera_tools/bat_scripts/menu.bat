@echo off
@rem ����һ�������������Ĺ���
@rem author: liudiwen

:loop
echo.
echo Select Menu:
echo.
echo 1. �ض�����
echo 2. ����������
echo 3. �������
echo.
echo 0. �˳�
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