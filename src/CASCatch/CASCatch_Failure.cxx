#include "CASCatch_Failure.hxx"
#include "CASCatch_ErrorHandler.hxx"
#include <Standard_TypeMismatch.hxx>
#include <Standard_Type.hxx>
#include <string.h>

IMPLEMENT_STANDARD_HANDLE( CASCatch_Failure, Standard_Transient )
IMPLEMENT_STANDARD_RTTIEXT( CASCatch_Failure, Standard_Transient ) 


#ifndef NO_CXX_EXCEPTION
static Handle(CASCatch_Failure) RaisedError;
#endif

//================================================================================
/*! Public -
 * \brief creates a CASCatch_Failure
 */
//================================================================================ 
CASCatch_Failure::CASCatch_Failure () { myMessage = "Signal detected";}


//================================================================================
/*! Public -
 * \brief creates a CASCatch_Failure with a message
 * \param an exception message
 */
//================================================================================ 
CASCatch_Failure::CASCatch_Failure (const Standard_CString AString) 
{
  if(AString) {
     myMessage = new Standard_Character[strlen(AString) + 1];
     strcpy(myMessage,AString);
  }
}

//================================================================================
/*! Public -
 * \brief returns the last caught exception
 */
//================================================================================ 
Handle(CASCatch_Failure) CASCatch_Failure::Caught() 
{
#ifdef NO_CXX_EXCEPTION
  return CASCatch_ErrorHandler::LastCaughtError();
#else
  return RaisedError ;
#endif
}

//================================================================================
/*! Public -
 * \brief raises a CASCatch_Failure exception
 * \param an exception message
 */
//================================================================================ 
void CASCatch_Failure::Raise (const Standard_CString AString) 
{ 
  Handle(CASCatch_Failure) E = new CASCatch_Failure()  ;
  E->Reraise (AString) ;
}


//================================================================================
/*! Public -
 * \brief re-raises a CASCatch_Failure exception
 * \param an exception message
 */
//================================================================================
void CASCatch_Failure::Reraise (const Standard_CString AString) 
{
  if(AString){
    myMessage = new Standard_Character[strlen(AString) + 1];
    strcpy(myMessage,AString);
  }

#ifdef NO_CXX_EXCEPTION
  CASCatch_ErrorHandler::Error(this) ;
  CASCatch_ErrorHandler::Abort();
#else
  RaisedError = this ;
  Throw() ;
#endif
}

//================================================================================
/*! Public -
 * \brief returns an exception message
 */
//================================================================================ 
Standard_CString CASCatch_Failure::GetError() const
{
  return myMessage;
}

//================================================================================
/*! Public -
 * \brief Is called when using standard C++ exceptions
 */
//================================================================================ 
void CASCatch_Failure::Throw() const
{
#ifndef NO_CXX_EXCEPTION
  throw CASCatch_Failure() ;
#endif
}
