#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.2
 Author:         myName

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start - Add your code below here

Run("notepad.exe")
WinWaitActive("无标题 - 记事本")
Send("This is some text.\r\n这是我的文本")

WinClose("无标题 - 记事本")
WinWaitActive("记事本", "取消")
;WinWaitActive("Notepad", "Do you want to save") ; When running under Windows XP
Send("!n")