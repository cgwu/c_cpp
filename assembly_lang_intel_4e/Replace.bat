@echo off
cls
set filename=%1
rem  ��ȡ�ַ��� 0 ~ -4(������4���ַ�,������)
set filename= %filename:~0,-4%
echo %filename%
echo 1234
rem pause