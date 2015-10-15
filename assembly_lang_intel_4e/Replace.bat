@echo off
cls
set filename=%1
rem  截取字符串 0 ~ -4(倒数第4个字符,不包含)
set filename= %filename:~0,-4%
echo %filename%
echo 1234
rem pause