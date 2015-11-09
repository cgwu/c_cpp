#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.2
 Author:         myName

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start - Add your code below here

#include <MsgBoxConstants.au3>

;MsgBox($MB_ICONINFORMATION, "Tutorial", "Hello World!中国")

;正则表达式查打成功返回1，否则返回0
;MsgBox($MB_OK, "SRE Example 1 Result", StringRegExp("  test  ", 'test'))

Local $i = 0
While $i <= 5
    MsgBox($MB_SYSTEMMODAL, "", "Value of $i is: " & $i)
    $i = $i + 1
	Sleep(1000)		;等待1秒
WEnd
