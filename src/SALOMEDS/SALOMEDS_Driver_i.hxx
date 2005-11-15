#ifndef __SALOMEDS_DRIVER_I_H__
#define __SALOMEDS_DRIVER_I_H__

#include <CORBA.h>
#include <TCollection_AsciiString.hxx>
#include "SALOMEDSImpl_Driver.hxx"
#include "SALOMEDSImpl_SComponent.hxx"
#include "SALOMEDSImpl_SObject.hxx"

#include <SALOMEconfig.h>   
#include CORBA_SERVER_HEADER(SALOMEDS) 
#include CORBA_SERVER_HEADER(SALOME_Component)

class Standard_EXPORT SALOMEDS_Driver_i :  public virtual SALOMEDSImpl_Driver 
{
protected:
  SALOMEDS::Driver_var _driver;
  CORBA::ORB_var _orb;

public:

  SALOMEDS_Driver_i(SALOMEDS::Driver_ptr theDriver, CORBA::ORB_ptr theORB) 
    {
      _driver = SALOMEDS::Driver::_duplicate(theDriver);
      _orb = CORBA::ORB::_duplicate(theORB);        
    }

  ~SALOMEDS_Driver_i();

  virtual TCollection_AsciiString GetIOR() 
    {
      CORBA::String_var ior = _orb->object_to_string(_driver);
      return TCollection_AsciiString(ior);
    }

  virtual unsigned char* Save(const Handle(SALOMEDSImpl_SComponent)& theComponent,
			      const TCollection_AsciiString& theURL,
			      long& theStreamLength,
			      bool isMultiFile);

  virtual unsigned char* SaveASCII(const Handle(SALOMEDSImpl_SComponent)& theComponent,
				   const TCollection_AsciiString& theURL,
				   long& theStreamLength,
				   bool isMultiFile);
  
  virtual bool Load(const Handle(SALOMEDSImpl_SComponent)& theComponent,
		    const unsigned char* theStream,
		    const long theStreamLength,
		    const TCollection_AsciiString& theURL,
		    bool isMultiFile);

  virtual bool LoadASCII(const Handle(SALOMEDSImpl_SComponent)& theComponent,
			 const unsigned char* theStream,
			 const long theStreamLength,
			 const TCollection_AsciiString& theURL,
			 bool isMultiFile);

  virtual void Close(const Handle(SALOMEDSImpl_SComponent)& theComponent);
 
  virtual TCollection_AsciiString ComponentDataType() 
    {
      CORBA::String_var ior = _driver->ComponentDataType();
      return TCollection_AsciiString(ior);
    }


  virtual TCollection_AsciiString IORToLocalPersistentID(const Handle(SALOMEDSImpl_SObject)& theSObject,
							 const TCollection_AsciiString& IORString,
							 bool isMultiFile,
							 bool isASCII);

  virtual TCollection_AsciiString LocalPersistentIDToIOR(const Handle(SALOMEDSImpl_SObject)& theSObject,
							 const TCollection_AsciiString& aLocalPersistentID,
							 bool isMultiFile,
							 bool isASCII);

  virtual bool CanCopy(const Handle(SALOMEDSImpl_SObject)& theObject);

  virtual unsigned char* CopyFrom(const Handle(SALOMEDSImpl_SObject)& theObject, 
				  int& theObjectID,
				  long& theStreamLength);

  virtual bool CanPaste(const TCollection_AsciiString& theComponentName, int theObjectID);

  virtual TCollection_AsciiString PasteInto(const unsigned char* theStream,
					    const long theStreamLength,
					    int theObjectID,
					    const Handle(SALOMEDSImpl_SObject)& theObject);

  virtual unsigned char* DumpPython(const Handle(SALOMEDSImpl_Study)& theStudy, 
				    bool isPublished, 
				    bool& isValidScript,
				    long& theStreamLength);
};

#include "SALOME_NamingService.hxx"
#include "SALOME_LifeCycleCORBA.hxx"

class SALOMEDS_DriverFactory_i : public virtual SALOMEDSImpl_DriverFactory 
{
protected:  
  CORBA::ORB_ptr        _orb;
  SALOME_NamingService* _name_service;

public:
  
  SALOMEDS_DriverFactory_i(CORBA::ORB_ptr theORB) 
    {
      _orb = CORBA::ORB::_duplicate(theORB);
      _name_service = new SALOME_NamingService(_orb);
    }


  ~SALOMEDS_DriverFactory_i() 
  {
    delete _name_service;
  }
   
  virtual SALOMEDSImpl_Driver* GetDriverByType(const TCollection_AsciiString& theComponentType);

  virtual SALOMEDSImpl_Driver* GetDriverByIOR(const TCollection_AsciiString& theIOR);
};

#endif 