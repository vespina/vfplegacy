#IF VERSION(5) >= 800
	#DEFINE _TRY		TRY
	#DEFINE _CATCH	    CATCH TO ex
	#DEFINE _ENDTRY		ENDTRY
	#DEFINE _EMPTY		"EMPTY"
#ELSE
	#DEFINE _TRY		ex=TRY()
	#DEFINE _CATCH	    IF CATCH(@ex)
	#DEFINE _ENDTRY		ENDIF
	#DEFINE _EMPTY		"EMPTYOBJECT"
#ENDIF		
