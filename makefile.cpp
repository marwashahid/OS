#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <ctime>
#include<sys/shm.h>
#include <sys/ipc.h>

using namespace std;

int main()
{
   
    //take input from the user
    string filename;
    cout << "Enter the name of the file to be created: ";
    cin >> filename;

    fstream file;
    file.open(filename.c_str(), ios::out);


    if (!file)
    {
        cout << "Error in creating file!!!";
    }
    else
    {
        std::string str;
        int choice;
        std::cin.ignore();
        std::cout << "\nBegin from here.....\n";
        getline(std::cin,str);
        file << str;
        file.close();
        std::cout << "\nDo you want to save file?\n";
        std::cout <<"1.YES  2.NO\n";
        std::cin >> choice;
        if (choice == 1)
        {
            long long int file_size;
            file_size = sizeof(str);
            
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
    *size = *size - file_size;
    memcpy(shared_memory, (void*)size, sizeof(*size));
    std::cout << "File created successfully!\n";
}
else
{
    file.open(filename.c_str()); //to format the file
    file.close();
    std::cerr << " NOT ENOUGH SPACE \n";
    return 1;
}

        }
        else if (choice == 2)
        {
           
            std::cerr<<"closed without saving!\n";
        }
    }

    //wait for the user to press key to terminate program
    std::cin.get();
    return 0;
}

