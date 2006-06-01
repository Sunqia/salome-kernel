// Copyright (C) 2005  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either 
// version 2.1 of the License.
// 
// This library is distributed in the hope that it will be useful 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public  
// License along with this library; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
//  File   : SALOMEDS_AttributeTableOfReal.hxx
//  Author : Sergey RUIN
//  Module : SALOME

#ifndef SALOMEDS_AttributeTableOfReal_HeaderFile
#define SALOMEDS_AttributeTableOfReal_HeaderFile

#include "SALOMEDSClient_AttributeTableOfReal.hxx"
#include "SALOMEDS_GenericAttribute.hxx"
#include "SALOMEDSImpl_AttributeTableOfReal.hxx"

// IDL headers
#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(SALOMEDS)
#include CORBA_SERVER_HEADER(SALOMEDS_Attributes)

#include <vector>

class SALOMEDS_AttributeTableOfReal: public SALOMEDS_GenericAttribute, public SALOMEDSClient_AttributeTableOfReal
{
public:  
  SALOMEDS_AttributeTableOfReal(const Handle(SALOMEDSImpl_AttributeTableOfReal)& theAttr);
  SALOMEDS_AttributeTableOfReal(SALOMEDS::AttributeTableOfReal_ptr theAttr);
  ~SALOMEDS_AttributeTableOfReal();

  virtual void SetTitle(const std::string& theTitle);
  virtual std::string GetTitle();
  virtual void SetRowTitle(int theIndex, const std::string& theTitle);
  virtual void SetRowTitles(const std::vector<std::string>& theTitles);
  virtual std::vector<std::string> GetRowTitles();
  virtual void SetColumnTitle(int theIndex, const std::string& theTitle);
  virtual void SetColumnTitles(const std::vector<std::string>& theTitles);
  virtual std::vector<std::string> GetColumnTitles();

  virtual void SetRowUnit(int theIndex, const std::string& theUnit);
  virtual void SetRowUnits(const std::vector<std::string>& theUnits);
  virtual std::vector<std::string> GetRowUnits();

  virtual int GetNbRows();
  virtual int GetNbColumns();
  virtual void AddRow(const std::vector<double>& theData);
  virtual void SetRow(int theRow, const std::vector<double>& theData);
  virtual std::vector<double> GetRow(int theRow);
  virtual void AddColumn(const std::vector<double>& theData);
  virtual void SetColumn(int theColumn, const std::vector<double>& theData);
  virtual std::vector<double> GetColumn(int theColumn);
  virtual void PutValue(double theValue, int theRow, int theColumn);
  virtual bool HasValue(int theRow, int theColumn);
  virtual double GetValue(int theRow, int theColumn);

  virtual std::vector<int> GetRowSetIndices(int theRow);
  virtual void SetNbColumns(int theNbColumns);    

};

#endif
