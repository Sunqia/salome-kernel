/*
 * BatchManager_LSF.cxx : 
 *
 * Auteur : Ivan DUTKA-MALEN - EDF R&D
 * Mail   : mailto:ivan.dutka-malen@der.edf.fr
 * Date   : Thu Nov  6 10:17:22 2003
 * Projet : Salome 2
 *
 */

extern "C" {
#include <lsf/lsf.h>
#include <lsf/lsbatch.h>
}
#include <iostream>
#include <fstream>
#include <sstream>
#include "Batch_BatchManager_LSF.hxx"

namespace Batch {

  BatchManager_LSF::BatchManager_LSF(const FactBatchManager * parent, const char * host) throw(InvalidArgumentException,ConnexionFailureException) : BatchManager(parent, host)
  {
    // On se connecte au serveur LSF
    _connect = lsb_init("Salome2 Batch library");
    if (_connect < 0) { // si erreur
      char * errmsg = lsb_sysmsg();
      string msg = "LSF Server on host \"";
      msg += _hostname;
      msg += "\" : ";
      msg += errmsg ? errmsg : "Reason unknown";
      throw ConnexionFailureException(msg.c_str());
    }
  }

  // Destructeur
  BatchManager_LSF::~BatchManager_LSF()
  {
    // Nothing to do
  }

  // Methode pour le controle des jobs : soumet un job au gestionnaire
  const JobId BatchManager_LSF::submitJob(const Job & job)
  {
    Job_LSF joblsf = job;
    struct submitReply reply;
    int ref = lsb_submit(joblsf.getSubmitStruct(),
			 &reply);
    if (ref < 0) { // si erreur
      char * msg = lsb_sysmsg();
      if (!msg) msg = "unknown";
      throw APIInternalFailureException(string("LSF submit error. Reason : ") + msg);
    }

    ostringstream oss;
    oss << ref;
    JobId id(this, oss.str());
    return id;
  }

  // Methode pour le controle des jobs : retire un job du gestionnaire
  void BatchManager_LSF::deleteJob(const JobId & jobid)
  {
    int ref;
    istringstream iss(jobid.getReference());
    iss >> ref;
    int rc = lsb_deletejob(ref, 0, 0);
    if (rc < 0) { // si erreur
      char * msg = lsb_sysmsg();
      if (!msg) msg = "unknown";
      throw APIInternalFailureException(string("LSF deljob error. Reason : ") + msg);
    }
  }
   
  // Methode pour le controle des jobs : suspend un job en file d'attente
  void BatchManager_LSF::holdJob(const JobId & jobid)
  {
   int ref;
    istringstream iss(jobid.getReference());
    iss >> ref;
    int rc = lsb_signaljob(ref, SIGSTOP);
    if (rc < 0) { // si erreur
      char * msg = lsb_sysmsg();
      if (!msg) msg = "unknown";
      throw APIInternalFailureException(string("LSF signaljob error. Reason : ") + msg);
    }
  }

  // Methode pour le controle des jobs : relache un job suspendu
  void BatchManager_LSF::releaseJob(const JobId & jobid)
  {
    int ref;
    istringstream iss(jobid.getReference());
    iss >> ref;
    int rc = lsb_signaljob(ref, SIGCONT);
    if (rc < 0) { // si erreur
      char * msg = lsb_sysmsg();
      if (!msg) msg = "unknown";
      throw APIInternalFailureException(string("LSF signaljob error. Reason : ") + msg);
    }
  }


  // Methode pour le controle des jobs : modifie un job en file d'attente
  void BatchManager_LSF::alterJob(const JobId & jobid, const Parametre & param, const Environnement & env)
  {
    int ref;
    istringstream iss(jobid.getReference());
    iss >> ref;

    Job_LSF joblsf = Job(param, env);
    struct submitReply reply;
    ref = lsb_modify(joblsf.getSubmitStruct(),
		     &reply,
		     ref);
    if (ref < 0) { // si erreur
      ostringstream msg_sst;
      char * msg = lsb_sysmsg();
      if (!msg) msg = "unknown";
      msg_sst << msg << endl;
//       msg_sst << "BadJobId   = " << (long) reply.badJobId   << endl
// 	      << "BadJobName = " << reply.badJobName << endl
// 	      << "BadReqIndx = " << reply.badReqIndx << endl;
      throw APIInternalFailureException(string("LSF modify error. Reason : ") + msg_sst.str());
    }
  }

  // Methode pour le controle des jobs : modifie un job en file d'attente
  void BatchManager_LSF::alterJob(const JobId & jobid, const Parametre & param)
  {
    alterJob(jobid, param, Environnement());
  }

  // Methode pour le controle des jobs : modifie un job en file d'attente
  void BatchManager_LSF::alterJob(const JobId & jobid, const Environnement & env)
  {
    alterJob(jobid, Parametre(), env);
  }



  // Methode pour le controle des jobs : renvoie l'etat du job
  JobInfo BatchManager_LSF::queryJob(const JobId & jobid)
  {
    int id;
    istringstream iss(jobid.getReference());
    iss >> id;

    JobInfo_LSF ji = JobInfo_LSF(id);

    return ji;
  }



  // Methode pour le controle des jobs : teste si un job est present en machine
  bool BatchManager_LSF::isRunning(const JobId & jobid)
  {
    int id;
    istringstream iss(jobid.getReference());
    iss >> id;

    JobInfo_LSF ji = JobInfo_LSF(id);

    return ji.isRunning();
  }



}