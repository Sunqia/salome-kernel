using namespace std;
#include "MPIObject_i.hxx"
#include "utilities.h"
#include <mpi.h>

MPIObject_i::MPIObject_i()
{
  _nbproc = 1;
  _numproc = 0;
  _tior=NULL;
}

MPIObject_i::MPIObject_i(int nbproc, int numproc)
{
  _nbproc = nbproc;
  _numproc = numproc;
  _tior=NULL;
}

MPIObject_i::~MPIObject_i()
{
  if(_tior) delete _tior;
}

Engines::IORTab* MPIObject_i::tior()
{
  Engines::IORTab* tior = new Engines::IORTab;
  tior->length(_tior->length());
  for(unsigned int ip=0;ip<tior->length();ip++)
    (*tior)[ip] = (*_tior)[ip];
  return tior; 
};

void MPIObject_i::tior(const Engines::IORTab& ior)
{
  _tior = new Engines::IORTab;
  _tior->length(ior.length());
  for(unsigned int ip=0;ip<ior.length();ip++)
    (*_tior)[ip] = ior[ip];
}

void MPIObject_i::BCastIOR(CORBA::ORB_ptr orb, Engines::MPIObject_var pobj, 
			   bool amiCont)
{
  int err, ip, n;
  char *ior;
  MPI_Status status; /* status de reception de message MPI */

  // Conversion IOR vers string
  CORBA::String_var sior(orb->object_to_string(pobj));

  if( _numproc == 0 ){

    //Allocation du tableau des IOR
    Engines::IORTab *iort = new Engines::IORTab;
    iort->length(_nbproc);

    (*iort)[0] = pobj;

    // Process 0 recupere les ior de l'object sur les autres process
    for(ip=1;ip<_nbproc;ip++){
      err = MPI_Recv(&n,1,MPI_INTEGER,ip,ip,MPI_COMM_WORLD,&status);
      if(err){
	MESSAGE("[" << _numproc << "] MPI_RECV error");
	exit(1);
      }
      // Allocation de la chaine de longueur n
      ior = (char*)calloc(n,sizeof(char));
      err = MPI_Recv(ior,n,MPI_CHARACTER,ip,2*ip,MPI_COMM_WORLD,&status);
      if(err){
	MESSAGE("[" << _numproc << "] MPI_RECV error");
	exit(1);
      }
      (*iort)[ip] = Engines::MPIObject::_narrow(orb->string_to_object(ior));
      free(ior);
    }
    // On donne le tableau des ior a l'objet Corba du process 0
    if( amiCont )
      tior(*iort);
    else
      pobj->tior(*iort);

  }
  else{
    // On envoie l'IOR au process 0
    n = strlen((char*)sior);
    err = MPI_Send(&n,1,MPI_INTEGER,0,_numproc,MPI_COMM_WORLD);
    if(err){
      MESSAGE("[" << _numproc << "] MPI_SEND error");
      exit(1);
    }
    err = MPI_Send((char*)sior,n,MPI_CHARACTER,0,2*_numproc,MPI_COMM_WORLD);
    if(err){
      MESSAGE("[" << _numproc << "] MPI_SEND error");
      exit(1);
    }
  }

}
