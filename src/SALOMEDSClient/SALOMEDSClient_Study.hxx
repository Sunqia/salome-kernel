//  File   : SALOMEDSClient_Study.hxx
//  Author : Sergey RUIN
//  Module : SALOME

#ifndef __SALOMEDSClient_STUDY_H__
#define __SALOMEDSClient_STUDY_H__

#include <vector>
#include <string>

#include "SALOMEDSClient_definitions.hxx"
#include "SALOMEDSClient_SComponentIterator.hxx"
#include "SALOMEDSClient_StudyBuilder.hxx"
#include "SALOMEDSClient_SObject.hxx"
#include "SALOMEDSClient_SComponent.hxx"
#include "SALOMEDSClient_UseCaseBuilder.hxx"
#include "SALOMEDSClient_AttributeStudyProperties.hxx"
#include "SALOMEDSClient_ChildIterator.hxx"

class SALOMEDSClient_Study
{

public:
  virtual ~SALOMEDSClient_Study() {}

  virtual std::string GetPersistentReference() = 0;
  virtual std::string GetTransientReference() = 0;
  virtual bool IsEmpty() = 0;
  virtual _PTR(SComponent) FindComponent (const std::string& aComponentName) = 0;
  virtual _PTR(SComponent) FindComponentID(const std::string& aComponentID) = 0;
  virtual _PTR(SObject) FindObject(const std::string& anObjectName) = 0;
  virtual std::vector<_PTR(SObject)> FindObjectByName( const std::string& anObjectName, const std::string& aComponentName ) = 0;  
  virtual _PTR(SObject) FindObjectID(const std::string& anObjectID) = 0;
  virtual _PTR(SObject) CreateObjectID(const std::string& anObjectID) = 0;
  virtual _PTR(SObject) FindObjectIOR(const std::string& anObjectIOR) = 0;
  virtual _PTR(SObject) FindObjectByPath(const std::string& thePath) = 0;
  virtual std::string GetObjectPath(const _PTR(SObject)& theSO) = 0;
  virtual void SetContext(const std::string& thePath) = 0;
  virtual std::string GetContext() = 0;  
  virtual std::vector<std::string> GetObjectNames(const std::string& theContext) = 0;
  virtual std::vector<std::string> GetDirectoryNames(const std::string& theContext) = 0;
  virtual std::vector<std::string> GetFileNames(const std::string& theContext) = 0;
  virtual std::vector<std::string> GetComponentNames(const std::string& theContext) = 0;
  virtual _PTR(ChildIterator) NewChildIterator(const _PTR(SObject)& theSO) = 0;
  virtual _PTR(SComponentIterator) NewComponentIterator() = 0;
  virtual _PTR(StudyBuilder) NewBuilder() = 0;
  virtual std::string Name() = 0;
  virtual void  Name(const std::string& name) = 0;
  virtual bool IsSaved() = 0;
  virtual void  IsSaved(bool save) = 0;
  virtual bool IsModified() = 0;
  virtual std::string URL() = 0;
  virtual void  URL(const std::string& url) = 0;
  virtual int StudyId() = 0;
  virtual void  StudyId(int id) = 0;
  virtual std::vector<_PTR(SObject)> FindDependances(const _PTR(SObject)& theSO) = 0;
  virtual _PTR(AttributeStudyProperties) GetProperties() = 0;
  virtual std::string GetLastModificationDate() = 0;
  virtual std::vector<std::string> GetModificationsDate() = 0;
  virtual _PTR(UseCaseBuilder) GetUseCaseBuilder() = 0;
  virtual void Close() = 0;
  virtual void EnableUseCaseAutoFilling(bool isEnabled) = 0;
  virtual bool DumpStudy(const std::string& thePath, const std::string& theBaseName, bool isPublished) = 0; 
};


#endif