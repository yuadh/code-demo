::chcp 936
cls
@echo off
::将下面的目录改为你需要创建easyx项目的主目录
set pojectDir=H:\code-demo\c\easyXprojects
::将下面的目录改为你存放.vscode配置文件的目录
set configDir=H:\code-demo\c\easyXprojects\.config\.vscode
::将下面的目录改为对应的你的目录
set cmd_2022="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
set /p value=输入一个项目名称,我们将在%pojectDir%中为你创建新目录:
md %pojectDir%\%value%\.vscode
copy %configDir% %pojectDir%\%value%\.vscode
echo 复制以下目录 在新窗口输入 code加空格加复制的目录名,然后回车打开VScode
ECHO.
echo %pojectDir%\%value%
ECHO.
pause
start %comspec% /k %cmd_2022%