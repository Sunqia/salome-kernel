using namespace std;
//  File      : Plot2d_CurveContainer.cxx
//  Created   : UI team, 05.09.00
//  Descrip   : Curve container class

//  Modified  : Mon Dec 03 15:37:21 2001
//  Author    : Vadim SANDLER
//  Project   : SALOME
//  Module    : Plot2d
//  Copyright : Open CASCADE 2001
//  $Header$

#include "Plot2d_CurveContainer.h"

/*!
  Constructor
*/
Plot2d_CurveContainer::Plot2d_CurveContainer()
{
  myCurves.setAutoDelete( false );
}
/*!
  Destructor
*/
Plot2d_CurveContainer::~Plot2d_CurveContainer()
{
  
}
/*!
  Adds curve if not exist yet in the container
*/
void Plot2d_CurveContainer::addCurve( Plot2d_Curve* curve )
{
  if ( myCurves.find( curve ) < 0 )
    myCurves.append( curve );
}
/*!
  Removes curve form the container ( and deletes it if <alsoDelete> is true )
*/
void Plot2d_CurveContainer::removeCurve( const int index, bool alsoDelete )
{
  Plot2d_Curve* curve = myCurves.take( index );
  if ( curve && alsoDelete )
    delete curve;
}
/*!
  Clears container contents ( removes and deletes all curves )
*/
void Plot2d_CurveContainer::clear( bool alsoDelete )
{
  while( myCurves.count() > 0 ) {
    Plot2d_Curve* curve = myCurves.take( 0 );
    if ( curve && alsoDelete )
      delete curve;
  }
}
/*!
  Gets nb of curves in container
*/
int Plot2d_CurveContainer::count()
{
  return myCurves.count();
}
/*!
  Returns true if contains no curves
*/
bool Plot2d_CurveContainer::isEmpty()
{
  return myCurves.isEmpty();
}
/*!
  Gets curve by index
*/
Plot2d_Curve* Plot2d_CurveContainer::curve( const int index )
{
  return myCurves.at( index );
}

