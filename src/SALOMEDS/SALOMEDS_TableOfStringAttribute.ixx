//  File      : SALOMEDS_TableOfStringAttribute.ixx
//  Created   : Mon Apr  7 10:13:30 2003
//  Author    : Sergey Ruin
//  Project   : SALOME
//  Module    : SALOMEDS
//  Copyright : Open CASCADE

#include <SALOMEDS_TableOfStringAttribute.jxx>

#ifndef _Standard_TypeMismatch_HeaderFile
#include <Standard_TypeMismatch.hxx>
#endif

SALOMEDS_TableOfStringAttribute::~SALOMEDS_TableOfStringAttribute() {}
 


Standard_EXPORT Handle_Standard_Type& SALOMEDS_TableOfStringAttribute_Type_()
{

    static Handle_Standard_Type aType1 = STANDARD_TYPE(TDF_Attribute);
  if ( aType1.IsNull()) aType1 = STANDARD_TYPE(TDF_Attribute);
  static Handle_Standard_Type aType2 = STANDARD_TYPE(MMgt_TShared);
  if ( aType2.IsNull()) aType2 = STANDARD_TYPE(MMgt_TShared);
  static Handle_Standard_Type aType3 = STANDARD_TYPE(Standard_Transient);
  if ( aType3.IsNull()) aType3 = STANDARD_TYPE(Standard_Transient);
 

  static Handle_Standard_Transient _Ancestors[]= {aType1,aType2,aType3,NULL};
  static Handle_Standard_Type _aType = new Standard_Type("SALOMEDS_TableOfStringAttribute",
			                                 sizeof(SALOMEDS_TableOfStringAttribute),
			                                 1,
			                                 (Standard_Address)_Ancestors,
			                                 (Standard_Address)NULL);

  return _aType;
}


// DownCast method
//   allow safe downcasting
//
const Handle(SALOMEDS_TableOfStringAttribute) Handle(SALOMEDS_TableOfStringAttribute)::DownCast(const Handle(Standard_Transient)& AnObject) 
{
  Handle(SALOMEDS_TableOfStringAttribute) _anOtherObject;

  if (!AnObject.IsNull()) {
     if (AnObject->IsKind(STANDARD_TYPE(SALOMEDS_TableOfStringAttribute))) {
       _anOtherObject = Handle(SALOMEDS_TableOfStringAttribute)((Handle(SALOMEDS_TableOfStringAttribute)&)AnObject);
     }
  }

  return _anOtherObject ;
}
const Handle(Standard_Type)& SALOMEDS_TableOfStringAttribute::DynamicType() const 
{ 
  return STANDARD_TYPE(SALOMEDS_TableOfStringAttribute) ; 
}
Standard_Boolean SALOMEDS_TableOfStringAttribute::IsKind(const Handle(Standard_Type)& AType) const 
{ 
  return (STANDARD_TYPE(SALOMEDS_TableOfStringAttribute) == AType || TDF_Attribute::IsKind(AType)); 
}
Handle_SALOMEDS_TableOfStringAttribute::~Handle_SALOMEDS_TableOfStringAttribute() {}
