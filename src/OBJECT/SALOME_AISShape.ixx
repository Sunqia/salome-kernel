// File generated by CPPExt (Transient)
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
#include "SALOME_AISShape.jxx"

#ifndef _Standard_TypeMismatch_HeaderFile
#include <Standard_TypeMismatch.hxx>
#endif

SALOME_AISShape::~SALOME_AISShape() {}
 


Standard_EXPORT Handle_Standard_Type& SALOME_AISShape_Type_()
{

    static Handle_Standard_Type aType1 = STANDARD_TYPE(AIS_Shape);
  if ( aType1.IsNull()) aType1 = STANDARD_TYPE(AIS_Shape);
  static Handle_Standard_Type aType2 = STANDARD_TYPE(AIS_InteractiveObject);
  if ( aType2.IsNull()) aType2 = STANDARD_TYPE(AIS_InteractiveObject);
  static Handle_Standard_Type aType3 = STANDARD_TYPE(SelectMgr_SelectableObject);
  if ( aType3.IsNull()) aType3 = STANDARD_TYPE(SelectMgr_SelectableObject);
  static Handle_Standard_Type aType4 = STANDARD_TYPE(PrsMgr_PresentableObject);
  if ( aType4.IsNull()) aType4 = STANDARD_TYPE(PrsMgr_PresentableObject);
  static Handle_Standard_Type aType5 = STANDARD_TYPE(MMgt_TShared);
  if ( aType5.IsNull()) aType5 = STANDARD_TYPE(MMgt_TShared);
  static Handle_Standard_Type aType6 = STANDARD_TYPE(Standard_Transient);
  if ( aType6.IsNull()) aType6 = STANDARD_TYPE(Standard_Transient);
 

  static Handle_Standard_Transient _Ancestors[]= {aType1,aType2,aType3,aType4,aType5,aType6,NULL};
  static Handle_Standard_Type _aType = new Standard_Type("SALOME_AISShape",
			                                 sizeof(SALOME_AISShape),
			                                 1,
			                                 (Standard_Address)_Ancestors,
			                                 (Standard_Address)NULL);

  return _aType;
}


// DownCast method
//   allow safe downcasting
//
const Handle(SALOME_AISShape) Handle(SALOME_AISShape)::DownCast(const Handle(Standard_Transient)& AnObject) 
{
  Handle(SALOME_AISShape) _anOtherObject;

  if (!AnObject.IsNull()) {
     if (AnObject->IsKind(STANDARD_TYPE(SALOME_AISShape))) {
       _anOtherObject = Handle(SALOME_AISShape)((Handle(SALOME_AISShape)&)AnObject);
     }
  }

  return _anOtherObject ;
}
const Handle(Standard_Type)& SALOME_AISShape::DynamicType() const 
{ 
  return STANDARD_TYPE(SALOME_AISShape) ; 
}
Standard_Boolean SALOME_AISShape::IsKind(const Handle(Standard_Type)& AType) const 
{ 
  return (STANDARD_TYPE(SALOME_AISShape) == AType || AIS_Shape::IsKind(AType)); 
}
Handle_SALOME_AISShape::~Handle_SALOME_AISShape() {}
