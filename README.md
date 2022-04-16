# vfplegacy.prg
Add support for some  VFP8+ features on older versions of VFP:

1. EMPTY CLASS
3. TRY-CATCH 
5. Exception CLASS
6. Collection CLASS5
7. ADDPROPERTY FUNCTION
8. EVL FUNCTION


#### EMPTY Class
Its not real Empty class, but it allows you write code using the empty class that will compile
and work in older versions of VFP.

    LOCAL oPerson
    oPerson = CREATE("Empty")
    ADDPROPERTY(oPerson, "FullName", "Victor Espina")


#### TRY-CATCH
Its a loose implementation of the benefits of TRY-CATCH blocks on older versions of VFP. You need to use 
the special function *NOEX()* to check if an error ocurred.

    TRY()
       some-code
       IF NOEX()
          some-more-code
       ENDIF
       
    IF CATCH(@ex)
       ?ex.Message
    ENDIF
    
You can write code that use TRY-CATCH blocks and will work in any version of VFP, by using special constants 
defined in vfpengine.h:

    #INCLUDE vfplegacy.h
    _TRY
       some-code
       IF NOEX()  && REQUIRED FOR OLDER VERSIONS OF VFP
          some-code
       ENDIF
    
    _CATCH
      ?ex.Message
    
    _ENDTRY
    
    
#### COLLECTION
This library includes a full implementation of the *Collection* class for older versions of VFP. Just take
in consideration that implicit element access is not supported, so instead of:

    Fruits = CREATE("Collection")
    Fruits.Add("Orange")
    Fruits.Add("Lemon")
    Fruits.Add("Apple")
    FOR EACH cFruit IN Fruits
       ?cFruit
    ENDFOR
    
You need to use the *Item()* accessor:
 
    FOR i = 1 TO Fruits.Count 
       cFruit = Fruits.Item(i)
       ?cFruit
    ENDFOR
 
 
