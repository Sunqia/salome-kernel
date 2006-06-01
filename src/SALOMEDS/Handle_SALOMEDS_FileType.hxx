// File generated by CPPExt (Transient)
//
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
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com

#ifndef _Handle_SALOMEDS_FileType_HeaderFile
#define _Handle_SALOMEDS_FileType_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif

#ifndef _Handle_TDataStd_Comment_HeaderFile
#include <Handle_TDataStd_Comment.hxx>
#endif

class Standard_Transient;
class Handle_Standard_Type;
class Handle(TDataStd_Comment);
class SALOMEDS_FileType;
Standard_EXPORT Handle_Standard_Type& STANDARD_TYPE(SALOMEDS_FileType);

class Handle(SALOMEDS_FileType) : public Handle(TDataStd_Comment) {
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
    Handle(SALOMEDS_FileType)():Handle(TDataStd_Comment)() {} 
    Handle(SALOMEDS_FileType)(const Handle(SALOMEDS_FileType)& aHandle) : Handle(TDataStd_Comment)(aHandle) 
     {
     }

    Handle(SALOMEDS_FileType)(const SALOMEDS_FileType* anItem) : Handle(TDataStd_Comment)((TDataStd_Comment *)anItem) 
     {
     }

    Handle(SALOMEDS_FileType)& operator=(const Handle(SALOMEDS_FileType)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(SALOMEDS_FileType)& operator=(const SALOMEDS_FileType* anItem)
     {
      Assign((Standard_Transient *)anItem);
      return *this;
     }

    SALOMEDS_FileType* operator->() 
     {
      return (SALOMEDS_FileType *)ControlAccess();
     }

    SALOMEDS_FileType* operator->() const 
     {
      return (SALOMEDS_FileType *)ControlAccess();
     }

   Standard_EXPORT ~Handle(SALOMEDS_FileType)();
 
   Standard_EXPORT static const Handle(SALOMEDS_FileType) DownCast(const Handle(Standard_Transient)& AnObject);
};
#endif
