using namespace std;
#include <iostream.h>
#include "HDFOI.hxx"
#include <stdlib.h>


int main()
{
  HDFfile      *hdf_file;
  HDFgroup     *hdf_group;
  HDFdataset   *hdf_dataset1;
  int          fd;
  size_t       size;
  char *       buffer;
  off_t        pos;

  system("rm ascii_hdf.txt");

  try  {
   
    // a new HDFfile object
    hdf_file = new HDFfile("file_ascii.hdf");
    MESSAGE( ">> A HDFfile object is created" );
      
    hdf_file->OpenOnDisk(HDF_RDONLY);
    MESSAGE( ">> The HDF file is opened on Disk with HDF_RDONLY access mode" )
  
    hdf_group = new HDFgroup("ASCII GROUP",hdf_file); 
    MESSAGE(">> A new HDF group object ASCII GROUP" << " is created in memory")

    hdf_group->OpenOnDisk();
    MESSAGE( ">> The group ASCII GROUP is opened on disk" );
      
    // The dataset object 'ASCII DATASET'
    hdf_dataset1 = new HDFdataset("ASCII DATASET",hdf_group);
    MESSAGE( ">> The dataset object 'ASCII DATASET' is created in memory " );

    hdf_dataset1->OpenOnDisk();
    MESSAGE( ">> The dataset object 'ASCII DATASET' is opened on disk " );
      
    size = (size_t) hdf_dataset1->GetSize();
 
    // Open the target file
      
    if ( (fd = open("ascii_hdf.txt",O_RDWR|O_CREAT,00666)) <0) { 
      perror("open : test9");
      return -1;
    };

  //    if ( (pos = lseek(fd,(off_t) size-3,SEEK_SET)) <0) {
//        perror("lseek : test9");
//        return -1;
//      };

//      if ( write(fd,"END",3) <0) { 
//        perror("write : test9");
//        return -1;
//      };

#ifdef _POSIX_MAPPED_FILES
    // Map le fichier en m�moire
    //   if ((buffer = (char *)  mmap(0,size,PROT_WRITE,MAP_SHARED,fd,0)) == MAP_FAILED ) {
    // perror("mmap : test9");
    //return -1;
    //};
    buffer = new char[size];
#else
    // Sort de la compilation
#error Necessite l''utilisation de la primitive mmap      
#endif
      
    // Transfert les informations dans le fichier destination
    hdf_dataset1->ReadFromDisk(buffer);

    if ( write(fd,buffer,size) <0) { 
      perror("write : test9");
      return -1;
    };
          
    // Desalloue le mapping
//      if (munmap(buffer,size) < 0 ) {
//        perror("munmap : test9");
//        return -1;
//      };
      
    // Close the target file
    if (close(fd) <0) {
      perror("close : test9");
      return -1;
    }
      
    hdf_dataset1->CloseOnDisk();
    MESSAGE( ">> The dataset is closed on disk " );
 
    hdf_group->CloseOnDisk();
    MESSAGE( ">> The group is closed on file" );
      
    hdf_file->CloseOnDisk();
    MESSAGE( ">> The HDF file is closed on Disk" )
        
    // Memory clean
    delete hdf_dataset1;
    delete hdf_group;
    delete hdf_file;
    delete buffer;
    MESSAGE( ">> MEMORY CLEAN : all HDF objects have been deleted" );
 
  }
  catch (HDFexception) {
    return -1;
    MESSAGE( "!!! HDFexception !!! " )
  }  
  
  return 0;
}
