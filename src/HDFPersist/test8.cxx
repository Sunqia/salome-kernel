using namespace std;
#include <iostream.h>
#include "HDFOI.hxx"
#include <stdlib.h>


int main()
{
  HDFfile *hdf_file;
  HDFgroup *hdf_group;
  HDFdataset *hdf_dataset;
  hdf_size size[1];
  char message[HDF_NAME_MAX_LEN+1] = "MESSAGE";
  hdf_int32 attribute = 3;

  system("rm file_ascii.hdf");

  try
    {
      // a new HDFfile object
      hdf_file = new HDFfile("file_ascii.hdf");
      MESSAGE( ">> A HDFfile object is created" );
      
      hdf_file->CreateOnDisk();
      MESSAGE( ">> The HDF file is created on Disk " );

      // Inside the HDF file 

      // A new HDF group object
      hdf_group = new HDFgroup("ASCII GROUP",hdf_file);
      MESSAGE( ">> A HDFgroup object 'ASCII' is created" );

      hdf_group->CreateOnDisk();
      MESSAGE( ">> The HDF group is created on Disk " );

      // Transfert d'un fichier ASCII dans un groupe HDF
      HDFConvert::FromAscii("ascii.txt",*hdf_group,"ASCII DATASET");
      MESSAGE( ">> The Ascii file is transfered " );
 
      // The HDF group is built, it can be closed
      hdf_group->CloseOnDisk();
      MESSAGE( ">> The HDF group is closed on Disk " );

      // The HDF file is built, it can be closed
      hdf_file->CloseOnDisk();
      MESSAGE( ">> The HDF file is closed on disk" );

 
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