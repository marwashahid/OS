#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include<string.h>
#include <fstream>
#include<sys/shm.h>
#include<sys/ipc.h>

using namespace std;
//Delete a file

int main()
{
  int file_size = 200; 
            int shm_id;
            key_t key = ftok(".", 'R');
            shm_id = shmget(key,1024, IPC_CREAT | 0666);
            if (shm_id == -1)
            {
                std::cerr << "Failed to create shared memory.\n";
                return 1;
            }
            int *shared_memory = (int *)shmat(shm_id, NULL, 0);
            if (shared_memory == ( int*)-1)
            {
                std::cerr << "Failed to attach shared memory.\n";
                return 1;
            }
            
   *shared_memory = *shared_memory * 1024;
    int status;
    std::string fileName;
    cout << "Enter the Name of File: " << endl;
    getline(std::cin,fileName);
    std::string str;
    std::ifstream file;
   
    status = remove(fileName.c_str());
    if (status == 0)
    {
            file.open(fileName, ios::binary | ios::ate);
    int file_size = file.tellg();
    file.seekg(0);
          *shared_memory = *shared_memory- file_size;
          
        cout << "\nFile Deleted Successfully!" << endl;

   }
    else
        cout << "\nErorr Occurred!" << endl;
    cout << endl;

std::cin.get();
return 0;
}

