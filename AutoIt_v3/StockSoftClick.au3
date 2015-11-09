#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.2
 Author:         myName

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start - Add your code below here

#include <AutoItConstants.au3>
#include <MsgBoxConstants.au3>

 ;ControlClick("招商证券智远理财服务平台", "", "Edit1")
MouseClick($MOUSE_CLICK_LEFT,1611/2,1266/2)


;Local $hWnd = WinWait("招商证券智远理财服务平台", "", 5)
; Local $sText = ControlGetText($hWnd, "", "Class:Button")

; Display the text of the edit control.
;MsgBox($MB_SYSTEMMODAL, "", "The text in Edit1 is: " & $sText)


;MsgBox($MB_ICONINFORMATION, "Tutorial", $hWnd)
;Local $ret = ControlClick($hWnd, "", "刷新")
;MsgBox(0, "", $ret)

;Local $ret =  ControlSetText("招商证券智远理财服务平台", "", "[CLASS:Button; INSTANCE:24]", "Refresh")
;MsgBox(0, "", $ret)