#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include<string.h>
#include <fstream>
#include<sys/shm.h>


using namespace std;
//Delete a file

int main()
{
  int shmid;
  void *shared_memory;
  shmid=shmget((key_t)2345, 1024, 0666);
  shared_memory=shmat(shmid,NULL,0);
  void *read = new int;
  memcpy(read,shared_memory,sizeof(int));
  int *size = new int;
  size =(int *)read;

    int status;
    std::string fileName;
    cout << "Enter the Name of File: " << endl;
    getline(std::cin,fileName);
    std::string str;
    std::ifstream file(fileName);
    while (!file.eof())
    {
      getline(file,str);
    }
    status = remove(fileName.c_str());
    if (status == 0)
    {
          long long int file_size = sizeof(str);
          *size = *size - file_size;
          memcpy(shared_memory,(void *)size,sizeof(*size));
        
        cout << "\nFile Deleted Successfully!" << endl;

   }
    else
        cout << "\nErorr Occurred!" << endl;
    cout << endl;

std::cin.get();
return 0;
}

