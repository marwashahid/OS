#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

// COPY FILE
int main()
{
    std::string sourceFile, targetFile;
    ifstream file;
    std::string str;
    cout << "Enter the Name of Source File: ";
    getline(cin, sourceFile);
    if (!std::ifstream(sourceFile))
    {
        std::cerr << "File not found.\n";
        return 1;
    }
    file.open(sourceFile, ios::binary | ios::ate);
    int file_size = file.tellg();
    file.seekg(0);

    cout << "\nEnter the Name of Target File: ";
    getline(cin, targetFile);
    ofstream w_file;
    w_file.open(targetFile);
    if (!w_file)
    {
        std::cerr << "Failed to open target file.\n";
        return 1;
    }

    int shmid;
    void* shared_memory;
    shmid = shmget((key_t)2345, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1)
    {
        std::cerr << "Failed to create shared memory.\n";
        return 1;
    }
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1)
    {
        std::cerr << "Failed to attach shared memory.\n";
        return 1;
    }
         void* read;
        memcpy(read, shared_memory, sizeof(int));
        int* size = new int;
        size = (int*)read;
        std::cin.ignore();
        *size = (*size * 1024 * 1024); // converting gb to kb
     if (file_size < *size)
    {
      if (!file)
        {
            std::cerr << "Failed to open source file.\n";
            return 1;
        }
        while (getline(file, str))
            w_file << str;

        w_file.close();
        file.close();
        *size = *size - file_size;
        memcpy(shared_memory, (void*)size, sizeof(*size));
         
        cin.ignore();
        cout << "\nFile copied successfully!\n";
  }
    
    else
    {
        // to format the file
        std::cerr << " NOT ENOUGH SPACE \n";
        return 1;
    }
    cout << endl;

    
   
    std::cin.get();
    return 0;
}

