using namespace std;
#include <iostream.h>
#include "HDFOI.hxx"
#include <stdlib.h>


int main()
{
  HDFfile *hdf_file;
  HDFgroup *hdf_group;
  HDFdataset *hdf_dataset;
  HDFdataset *hdf_dataset2;
  HDFattribute *hdf_attribute;
  hdf_size size[1];
  hdf_float64 coordinates[3] = {5.,-6.9,4.2};
  hdf_int32 unit[3] = {0,0,0};
  char message[HDF_NAME_MAX_LEN+1] = "MESSAGE";
  hdf_int32 attribute = 3;
  HDFexplorer *explorer;
  HDFinternalObject *object;

  system("rm file_test3.hdf");

  try
    {
      // a new HDFfile object
      hdf_file = new HDFfile("file_test3.hdf");
      MESSAGE( ">> A HDFfile object is created" );
      
      hdf_file->CreateOnDisk();
      MESSAGE( ">> The HDF file is created on Disk " );

      // Inside the HDF file 

      // A new HDF group object
      hdf_group = new HDFgroup("MESH",hdf_file);
      MESSAGE( ">> A HDFgroup object 'MESH' is created" );

      hdf_group->CreateOnDisk();
      MESSAGE( ">> The HDF group is created on Disk " );

      // Inside the HDF group  
      
      // A new HDF dataset object
      // size of each dimension, only one in the example
      size[0] = 3;
      hdf_dataset = new HDFdataset("COORDINATES",hdf_group,HDF_FLOAT64,size,1);
      MESSAGE( ">> A HDFdataset object 'COORDINATES' is created" );

      hdf_dataset->CreateOnDisk();
      MESSAGE( ">> The HDF dataset is created on Disk " );

      // a HDFattribute object inside the dataset
      hdf_attribute = new HDFattribute("ATTRIBUTE",hdf_dataset,HDF_INT32);
      MESSAGE( ">> A HDF attribute  object is created for the dataset " );

      hdf_dataset->WriteOnDisk(coordinates);
      MESSAGE( ">> The HDF dataset is written on Disk " );

      hdf_attribute->CreateOnDisk();
      MESSAGE( ">> The HDF attribute is created on Disk " );

      hdf_attribute->WriteOnDisk(&attribute); 
      MESSAGE( ">> The HDF attribute is written on Disk " );
      
      hdf_attribute->CloseOnDisk();
      MESSAGE( ">> The HDF attribute closed on Disk " );  

      hdf_dataset->CloseOnDisk();
      MESSAGE( ">> The HDF dataset is closed on Disk " );

      // A new dataset is created
      size[0] = 3;
      hdf_dataset2 = new HDFdataset("UNIT",hdf_group,HDF_INT32,size,1);
      MESSAGE( ">> A second HDFdataset object 'UNIT' is created" );

      hdf_dataset2->CreateOnDisk();
      MESSAGE( ">> The HDF dataset is created on Disk " );

      hdf_dataset2->WriteOnDisk(unit);
      MESSAGE( ">> The HDF dataset is written on Disk " );

      hdf_dataset2->CloseOnDisk();
      MESSAGE( ">> The HDF dataset is closed on Disk " );

      // The HDF group is built, it can be closed
      hdf_group->CloseOnDisk();
      MESSAGE( ">> The HDF group is closed on Disk " );

      // The HDF file is built, it can be closed
      hdf_file->CloseOnDisk();
      MESSAGE( ">> The HDF file is closed on disk" );

      // Explorer
      explorer = new HDFexplorer(hdf_file);
      MESSAGE( ">> A HDF explorer object is created" );

      MESSAGE( ">> File Exploration " );
      for (explorer->Init();explorer->More();explorer->Next())
	{
	  object = explorer->Value();
	  MESSAGE( "--> Name of the object : " << object->GetName() );
	  switch (object->GetObjectType())
	    {
	    case HDF_FILE :
	      MESSAGE( "--> Type of the object : HDF_FILE : " );
	      break;

	    case HDF_GROUP :
	      MESSAGE( "--> Type of the object : HDF_GROUP : " );
	      break;

	    case HDF_DATASET :
	      MESSAGE( "--> Type of the object : HDF_DATASET : " );
	      break;

	    default :
	      MESSAGE( "--> PANIC !!! : " ); 
	    }
	}
      
      MESSAGE( ">> Group exploration" );
      explorer->Reset(hdf_group); 
      for (explorer->Init();explorer->More();explorer->Next())
	{
	  object = explorer->Value();
	  MESSAGE( "--> Name of the object : " << object->GetName() );
	  switch (object->GetObjectType())
	    {
	    case HDF_FILE :
	      MESSAGE( "--> Type of the object : HDF_FILE : " );
	      break;

	    case HDF_GROUP :
	      MESSAGE( "--> Type of the object : HDF_GROUP : " );
	      break;

	    case HDF_DATASET :
	      MESSAGE( "--> Type of the object : HDF_DATASET : " );
	      break;

	    default :
	      MESSAGE( "--> !!! PANIC !!! : " );
	    }
	}      
      
      // memory clean
      MESSAGE( ">> MEMORY CLEAN " );
      delete explorer;
      MESSAGE( ">> The HDF eplorer object is deleted" );
      delete hdf_attribute;
      MESSAGE( ">> The HDF attribute object is deleted" );     
      delete hdf_dataset;
      MESSAGE( ">> The first HDF dataset object is deleted" );
      delete hdf_dataset2;
      MESSAGE( ">> The second HDF dataset object is deleted" );
      delete hdf_group;
      MESSAGE( ">> The HDF group object is deleted" ); 
      delete hdf_file;
      MESSAGE( ">> The HDF file object is deleted" );
    }
  catch (HDFexception)
    {
      MESSAGE( "!!!! HDFexception" )
    }

  return 0;
}