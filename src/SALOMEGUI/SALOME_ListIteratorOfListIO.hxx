// File generated by CPPExt (Value)
//                     Copyright (C) 1991,1995 by
//  
//                      MATRA DATAVISION, FRANCE
//  
// This software is furnished in accordance with the terms and conditions
// of the contract and with the inclusion of the above copyright notice.
// This software or any other copy thereof may not be provided or otherwise
// be made available to any other person. No title to an ownership of the
// software is hereby transferred.
//  
// At the termination of the contract, the software and all copies of this
// software must be deleted.

#ifndef _SALOME_ListIteratorOfListIO_HeaderFile
#define _SALOME_ListIteratorOfListIO_HeaderFile

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_SALOME_InteractiveObject_HeaderFile
#include <Handle_SALOME_InteractiveObject.hxx>
#endif
#ifndef _Handle_SALOME_ListNodeOfListIO_HeaderFile
#include <Handle_SALOME_ListNodeOfListIO.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoMoreObject;
class Standard_NoSuchObject;
class SALOME_ListIO;
class SALOME_InteractiveObject;
class SALOME_ListNodeOfListIO;


#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

class SALOME_ListIteratorOfListIO  {

public:

    void* operator new(size_t,void* anAddress) 
      {
        return anAddress;
      }
    void* operator new(size_t size) 
      { 
        return Standard::Allocate(size); 
      }
    void  operator delete(void *anAddress) 
      { 
        if (anAddress) Standard::Free((Standard_Address&)anAddress); 
      }
 // Methods PUBLIC
 // 
Standard_EXPORT SALOME_ListIteratorOfListIO();
Standard_EXPORT SALOME_ListIteratorOfListIO(const SALOME_ListIO& L);
Standard_EXPORT   void Initialize(const SALOME_ListIO& L) ;
Standard_EXPORT   Standard_Boolean More() const;
Standard_EXPORT   void Next() ;
Standard_EXPORT   Handle_SALOME_InteractiveObject& Value() const;


friend class SALOME_ListIO;



protected:

 // Methods PROTECTED
 // 


 // Fields PROTECTED
 //


private: 

 // Methods PRIVATE
 // 


 // Fields PRIVATE
 //
Standard_Address current;
Standard_Address previous;


};

#define Item Handle_SALOME_InteractiveObject
#define Item_hxx "SALOME_InteractiveObject.hxx"
#define TCollection_ListNode SALOME_ListNodeOfListIO
#define TCollection_ListNode_hxx "SALOME_ListNodeOfListIO.hxx"
#define TCollection_ListIterator SALOME_ListIteratorOfListIO
#define TCollection_ListIterator_hxx "SALOME_ListIteratorOfListIO.hxx"
#define Handle_TCollection_ListNode Handle_SALOME_ListNodeOfListIO
#define TCollection_ListNode_Type_() SALOME_ListNodeOfListIO_Type_()
#define TCollection_List SALOME_ListIO
#define TCollection_List_hxx "SALOME_ListIO.hxx"

#include <TCollection_ListIterator.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)
//


#endif