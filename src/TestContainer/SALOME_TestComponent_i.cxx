using namespace std;
//=============================================================================
// File      : SALOME_TestComponent_i.cxx
// Created   : jeu jui 12 12:28:26 CEST 2001
// Author    : Paul RASCLE, EDF - MARC TAJCHMAN, CEA
// Project   : SALOME
// Copyright : EDF 2001
// $Header$
//=============================================================================

#include "utilities.h"
#include "SALOME_TestComponent_i.hxx"
#include <stdio.h>

Engines_TestComponent_i::Engines_TestComponent_i(CORBA::ORB_ptr orb,
						 PortableServer::POA_ptr poa,
						 PortableServer::ObjectId * contId, 
						 const char *instanceName, 
						 const char *interfaceName) :
  Engines_Component_i(orb, poa, contId, instanceName, interfaceName)
{
  MESSAGE("activate object")
  _thisObj = this ;
  _id = _poa->activate_object(_thisObj);
  //SCRUTE(this)
}

Engines_TestComponent_i::Engines_TestComponent_i()
{
}

Engines_TestComponent_i::~Engines_TestComponent_i()
{
}

char* Engines_TestComponent_i::Coucou(CORBA::Long L)
{
  char s[100];
  sprintf(s, "TestComponent_i : L = %ld", (long) L);

  return CORBA::string_dup(s);
}

extern "C"
{
  PortableServer::ObjectId * SalomeTestComponentEngine_factory(
				 CORBA::ORB_ptr orb,
				 PortableServer::POA_ptr poa, 
				 PortableServer::ObjectId * contId,
				 const char *instanceName, 
				 const char *interfaceName)
  {
    MESSAGE("PortableServer::ObjectId * TestComponent_factory()");
    SCRUTE(interfaceName);
    Engines_TestComponent_i * myTestComponent 
      = new Engines_TestComponent_i(orb, poa, contId, instanceName, interfaceName);
    return myTestComponent->getId() ;
  }
}
