//  Copyright (C) 2004  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
//  CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS 
// 
//  This library is free software; you can redistribute it and/or 
//  modify it under the terms of the GNU Lesser General Public 
//  License as published by the Free Software Foundation; either 
//  version 2.1 of the License. 
// 
//  This library is distributed in the hope that it will be useful, 
//  but WITHOUT ANY WARRANTY; without even the implied warranty of 
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
//  Lesser General Public License for more details. 
// 
//  You should have received a copy of the GNU Lesser General Public 
//  License along with this library; if not, write to the Free Software 
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA 
// 
//  See http://www.opencascade.org/SALOME/ or email : webmaster.salome@opencascade.org 
//
//  Author : Paul RASCLE (EDF)
//  Module : KERNEL
//  $Header$

#ifndef _LOCALTRACEBUFFERPOOL_HXX_
#define _LOCALTRACEBUFFERPOOL_HXX_

#define TRACE_BUFFER_SIZE 256  // number of entries in circular buffer
                               // must be power of 2
#define MAX_TRACE_LENGTH 256   // messages are truncated at this size

#include <pthread.h>
#include <semaphore.h>

#define ABORT_MESS  1   // for traceType field in struct LocalTrace_TraceInfo
#define NORMAL_MESS 0

struct LocalTrace_TraceInfo
{
  char trace[MAX_TRACE_LENGTH];
  pthread_t threadId;
  int traceType;                 // normal or abort
  int position;                  // to check sequence
};

class LocalTraceBufferPool
{
 public:
  static LocalTraceBufferPool* instance();
  int insert(int traceType, const char* msg);
  int retrieve(LocalTrace_TraceInfo& aTrace);
  unsigned long toCollect();
  ~LocalTraceBufferPool();

 protected:
  LocalTraceBufferPool();
  unsigned long lockedIncrement(unsigned long& pos);

 private:
  static LocalTraceBufferPool* _singleton;
  static pthread_mutex_t _singletonMutex;
  LocalTrace_TraceInfo _myBuffer[TRACE_BUFFER_SIZE];
  sem_t _freeBufferSemaphore;       // to wait until there is a free buffer
  sem_t _fullBufferSemaphore;       // to wait until there is a buffer to print
  pthread_mutex_t _incrementMutex;  // to lock position variables for increment
  unsigned long _position;
  unsigned long _insertPos;
  unsigned long _retrievePos;
  pthread_t _threadId;
};

#endif