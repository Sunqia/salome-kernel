using namespace std;
extern "C"
{
#include "hdfi.h"
#include <string.h>
}
#include "HDFdataset.hxx"
#include "HDFcontainerObject.hxx"
#include "HDFexception.hxx"

#include <iostream.h>

HDFdataset::HDFdataset(char *name, HDFcontainerObject *father,hdf_type type, 
		       hdf_size dim[], int dimsize)
  : HDFinternalObject(name)
{
  int i;

  _father = father;
  _fid = _father->GetId();
  _father->AddSon(this);
  _type = type;
  _ndim = dimsize;
  _dim = new hdf_size[dimsize];
  _size = 1;
  for (i=0;i<dimsize;i++)
    {
      _dim[i] = dim[i];
      _size = _size * _dim[i];
    }
}

HDFdataset::HDFdataset(char *name,HDFcontainerObject *father)
  : HDFinternalObject(name)
{
  _father = father;
  _fid = _father->GetId();
  _father->AddSon(this);
  _type = HDF_NONE;
  _ndim = -1;
  _dim = 0;
  _size = -1;
}

HDFdataset::~HDFdataset()
{
  delete [] _dim;
}

void HDFdataset::CreateOnDisk()
{
  if ((_id = HDFdatasetCreate(_fid,_name,_type,_dim,_ndim)) < 0)
    throw HDFexception("Can't create dataset");
}

void HDFdataset::OpenOnDisk()
{
  if ((_id = HDFdatasetOpen(_fid,_name)) < 0)
    throw HDFexception("Can't open dataset");
}

void HDFdataset::CloseOnDisk()
{
  hdf_err ret;

  if ((ret = HDFdatasetClose(_id)) < 0)
    throw HDFexception("Can't close dataset");
  _id = -1;
}

void HDFdataset::WriteOnDisk(void *values)
{
  hdf_err ret;

  if ((ret = HDFdatasetWrite(_id,values)) < 0)
    throw HDFexception("Can't write dataset");
 
}

void HDFdataset::ReadFromDisk(void *values)
{
  hdf_err ret;

  if ((ret = HDFdatasetRead(_id,values)) < 0)
      throw HDFexception("Can't read dataset");
}

HDFcontainerObject *HDFdataset::GetFather()
{
  return _father;
}

hdf_type HDFdataset::GetType()
{
  if (_type == HDF_NONE)
    if ((_type = HDFdatasetGetType(_id)) == HDF_NONE)
      throw HDFexception("Can't determine the type of data in the dataset");
  
  return _type;
}

int HDFdataset::nDim()
{
  if (_ndim == -1)
    if ((_ndim = HDFdatasetGetnDim(_id)) < 0)
      throw HDFexception("Can't determine the dataset dimensions number");

  return _ndim;
}

void HDFdataset::GetDim(hdf_size dim[])
{
  int i;
  int ndim;
  hdf_err ret;

  if (_dim == 0)
    {
      if (_ndim == -1)
	ndim = HDFdatasetGetnDim(_id);
      else
	ndim = _ndim;
      _dim = new hdf_size[ndim];
      if ((ret == HDFdatasetGetDim(_id,_dim)) < 0)
	throw HDFexception("Can't determine the size dimensions of the dataset ");
    }

  for (i=0;i<_ndim;i++)
    dim[i] = _dim[i];
}

int HDFdataset::GetSize()
{
  int size_type;

  if (_size == -1)
    {
      if ((_size = HDFdatasetGetSize(_id)) < 0)
	throw HDFexception("Can't determine the size of the dataset");
      
      if (_type == HDF_NONE)
	if ((_type = HDFdatasetGetType(_id)) == HDF_NONE)
	  throw HDFexception("Can't determine the size of the dataset");
      
      switch (_type)
	{
	case HDF_INT32 : 
	  size_type = 4;
	  break;
	  
	case HDF_INT64 :
	case HDF_FLOAT64 :
	  size_type = 8;
	  break;
	  
	default :
	  size_type = 1;
	}
      _size = _size / size_type;
    }

  return _size;
}

hdf_object_type HDFdataset::GetObjectType()
{
  return HDF_DATASET;
}