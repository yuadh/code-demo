::chcp 936
cls
@echo off
::�������Ŀ¼��Ϊ����Ҫ����easyx��Ŀ����Ŀ¼
set pojectDir=H:\code-demo\c\easyXprojects
::�������Ŀ¼��Ϊ����.vscode�����ļ���Ŀ¼
set configDir=H:\code-demo\c\easyXprojects\.config\.vscode
::�������Ŀ¼��Ϊ��Ӧ�����Ŀ¼
set cmd_2022="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
set /p value=����һ����Ŀ����,���ǽ���%pojectDir%��Ϊ�㴴����Ŀ¼:
md %pojectDir%\%value%\.vscode
copy %configDir% %pojectDir%\%value%\.vscode
echo ��������Ŀ¼ ���´������� code�ӿո�Ӹ��Ƶ�Ŀ¼��,Ȼ��س���VScode
ECHO.
echo %pojectDir%\%value%
ECHO.
pause
start %comspec% /k %cmd_2022%