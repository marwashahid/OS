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

    int shm_id;
    key_t key = ftok(".", 'R');
    shm_id = shmget(key,1024, IPC_CREAT | 0666);
    if (shm_id == -1)
    {
        std::cerr << "Failed to create shared memory.\n";
        return 1;
    }
    int *shared_memory = (int *)shmat(shm_id, NULL, 0);
    if (shared_memory == (int*)-1)
    {
        std::cerr << "Failed to attach shared memory.\n";
        return 1;
    }
        
  *shared_memory = *shared_memory * 1024;
     if (file_size < *shared_memory)
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
        *shared_memory = *shared_memory - file_size;
         
        shmdt(shared_memory);
        shmctl(shm_id, IPC_RMID, NULL);
        system("clear");
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

