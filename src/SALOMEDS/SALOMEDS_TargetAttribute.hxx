//  File      : SALOMEDS_TargetAttribute.hxx
//  Created   : Fri Aug 16 10:20:05 2002
//  Author    : Yves FRICAUD

//  Project   : SALOME
//  Module    : SALOMEDS
//  Copyright : Open CASCADE 2002
//  $Header: 

#ifndef _SALOMEDS_TargetAttribute_HeaderFile
#define _SALOMEDS_TargetAttribute_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Handle_SALOMEDS_TargetAttribute_HeaderFile
#include <Handle_SALOMEDS_TargetAttribute.hxx>
#endif

#include <TDataStd_Relation.hxx>
#ifndef _Handle_TDF_Attribute_HeaderFile
#include <Handle_TDF_Attribute.hxx>
#endif
#ifndef _Handle_TDF_RelocationTable_HeaderFile
#include <Handle_TDF_RelocationTable.hxx>
#endif
#ifndef _TDF_LabelList_HeaderFile
#include <TDF_LabelList.hxx>
#endif
#ifndef _Handle_TDF_Reference_HeaderFile
#include <Handle_TDF_Reference.hxx>
#endif
class Standard_GUID;
class TDF_Label;
class TDF_Attribute;
class TDF_RelocationTable;


class SALOMEDS_TargetAttribute : public TDataStd_Relation {

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
 // Methods PUBLIC
 // 
Standard_EXPORT static const Standard_GUID& GetID() ;
Standard_EXPORT static  Handle_SALOMEDS_TargetAttribute Set(const TDF_Label& label) ;
Standard_EXPORT SALOMEDS_TargetAttribute();
Standard_EXPORT void SALOMEDS_TargetAttribute::Append(TDF_Label& theReferencedObject);
Standard_EXPORT void SALOMEDS_TargetAttribute::Get(TDF_LabelList& theReferencedObjects);
Standard_EXPORT void SALOMEDS_TargetAttribute::Remove(TDF_Label& theReferencedObject);
Standard_EXPORT  const Standard_GUID& ID() const;

//  Standard_EXPORT   void Restore(const Handle(TDF_Attribute)& with) ;
//  Standard_EXPORT   Handle_TDF_Attribute NewEmpty() const;
//  Standard_EXPORT   void Paste(const Handle(TDF_Attribute)& into,const Handle(TDF_RelocationTable)& RT) const;

Standard_EXPORT ~SALOMEDS_TargetAttribute();




 // Type management
 //
 Standard_EXPORT friend Handle_Standard_Type& SALOMEDS_TargetAttribute_Type_();
 Standard_EXPORT const Handle(Standard_Type)& DynamicType() const;
 Standard_EXPORT Standard_Boolean	       IsKind(const Handle(Standard_Type)&) const;

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


};





// other inline functions and methods (like "C++: function call" methods)
//


#endif