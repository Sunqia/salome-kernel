//=============================================================================
// File      : PyInterp_base.h
// Created   : ven f�v  7 10:01:36 CET 2003
// Author    : Christian CAREMOLI, Paul RASCLE, EDF
// Project   : SALOME
// Copyright : EDF 2003
// $Header$
//=============================================================================

#ifndef _PYINTERP_BASE_H_
#define _PYINTERP_BASE_H_

using namespace std;
#include <iostream>
#include <Python.h>
#include <list>
#include <string>

#define TOP_HISTORY_PY "--- top of history ---"
#define BEGIN_HISTORY_PY "--- begin of history ---"

/*!
 * We have our own routines which are identical to the SIP routines
 * to not depend from SIP software evolutions
 */

extern "C" void salomeAcquireLock();
extern "C" void salomeReleaseLock();
extern "C" int salomeCondAcquireLock();
extern "C" void salomeCondReleaseLock(int rellock);

/*! this class can only be used with derivation : 
 *  2 pure virtual methods, initstate() & initcontext()
 */

class PyInterp_base
{
 public:
  static PyThreadState *_gtstate;
  static int _argc;
  static char* _argv[];
  static PyObject *builtinmodule;
  static PyObject *salome_shared_modules_module;

  PyInterp_base();
  ~PyInterp_base();
  void initialize();
  int run(const char *command); 
  char * getverr();
  char * getvout();  
  string getbanner(); 
  const char * getPrevious();
  const char * getNext();    
  void enter();
  void quit();
  void basicRun(const char *command);

 protected:
  PyThreadState * _tstate;
  PyObject      * _vout;
  PyObject      * _verr;
  PyObject      * _g;
  list <string> _history;
  list <string>::iterator _ith;
  bool _atFirst;

  int simpleRun(const char* command);
  int initRun();

  virtual void initState() = 0;
  virtual void initContext() =0;  
};

#endif