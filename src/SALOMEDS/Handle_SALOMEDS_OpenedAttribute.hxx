//  File      : Handle_SALOMEDS_OpenedAttribute.hxx
//  Created   : Tue Jul 09 16:42:38 2002
//  Author    : Yves FRICAUD

//  Project   : SALOME
//  Module    : SALOMEDS
//  Copyright : Open CASCADE 2002
//  $Header$

#ifndef _Handle_SALOMEDS_OpenedAttribute_HeaderFile
#define _Handle_SALOMEDS_OpenedAttribute_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif

#ifndef _Handle_TDataStd_Integer_HeaderFile
#include <Handle_TDataStd_Integer.hxx>
#endif

class Standard_Transient;
class Handle_Standard_Type;
class Handle(TDataStd_Integer);
class SALOMEDS_OpenedAttribute;
Standard_EXPORT Handle_Standard_Type& STANDARD_TYPE(SALOMEDS_OpenedAttribute);

class Handle(SALOMEDS_OpenedAttribute) : public Handle(TDataStd_Integer) {
  public:
    inline void* operator new(size_t,void* anAddress) 
      {
        return anAddress;
      }
    inline void* operator new(size_t size) 
      { 
        return Standard::Allocate(size); 
      }
    inline void  operator delete(void *anAddress) 
      { 
        if (anAddress) Standard::Free((Standard_Address&)anAddress); 
      }
//    inline void  operator delete(void *anAddress, size_t size) 
//      { 
//        if (anAddress) Standard::Free((Standard_Address&)anAddress,size); 
//      }
    Handle(SALOMEDS_OpenedAttribute)():Handle(TDataStd_Integer)() {} 
    Handle(SALOMEDS_OpenedAttribute)(const Handle(SALOMEDS_OpenedAttribute)& aHandle) : Handle(TDataStd_Integer)(aHandle) 
     {
     }

    Handle(SALOMEDS_OpenedAttribute)(const SALOMEDS_OpenedAttribute* anItem) : Handle(TDataStd_Integer)((TDataStd_Integer *)anItem) 
     {
     }

    Handle(SALOMEDS_OpenedAttribute)& operator=(const Handle(SALOMEDS_OpenedAttribute)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(SALOMEDS_OpenedAttribute)& operator=(const SALOMEDS_OpenedAttribute* anItem)
     {
      Assign((Standard_Transient *)anItem);
      return *this;
     }

    SALOMEDS_OpenedAttribute* operator->() 
     {
      return (SALOMEDS_OpenedAttribute *)ControlAccess();
     }

    SALOMEDS_OpenedAttribute* operator->() const 
     {
      return (SALOMEDS_OpenedAttribute *)ControlAccess();
     }

   Standard_EXPORT ~Handle(SALOMEDS_OpenedAttribute)();
 
   Standard_EXPORT static const Handle(SALOMEDS_OpenedAttribute) DownCast(const Handle(Standard_Transient)& AnObject);
};
#endif