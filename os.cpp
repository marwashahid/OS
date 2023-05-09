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
#include<sys/wait.h>
#include <ctime>
#include<queue>
#include<semaphore.h>
#include<sys/shm.h>
#include <sys/ipc.h>

using namespace std;

struct cmd
{
const char* command;
int process;

};
int cores;
int hard_drive;
int *process_on_core;
long long int ram;
pthread_mutex_t mutex_hp;
pthread_mutex_t mutex_lp;
int process_size[16] = {60,1,1,1,1,3,7,2,4,2,7,2,2,3,1,1};
void* execute(void* comm)
{
   struct cmd *input = reinterpret_cast<struct cmd*>(comm);
   if ( process_size[input->process] > ram)
    {
     std::cerr << "Failed to execute command: " << input->command << ", Error: Not enough available RAM" << std::endl;
        return NULL;
    }
   pid_t pid = fork();
    if (pid == 0 )
    {
     int x = -1;
     int p = 16 / cores;
     for(int i=0; i < cores;i++) 
     {
      if (process_on_core[i] <= p)
        { 
         process_on_core[i]++;
         
         x = i;
         break;
      } 
     }
     if ( x== -1)
     {
           std::cerr << " SYSTEM CRASH..... PROCESSES OVERLOADED\n NOT ENOUGH CORES" <<std::endl;
       return NULL;
     }
      else
    {
      
     int ret= execlp("gnome-terminal", "gnome-terminal", "--",input->command, NULL);
     if (ret == -1) 
     {
        std::cerr << "Failed to execute command: " << input->command << ", Error: "  
        << strerror(errno) << std::endl;
     }
     else
     {
        ram = ram + process_size[input->process];
     }
   }
   }
  else if (pid < 0) {
  std::cerr << "Failed to execute command: " << input->command << ", Error: " << strerror(errno) << std::endl;
  return NULL;
}
  else
   {
     ram = ram - process_size[input->process];
     wait(NULL);
   }
  
   
}

void* func(void* arg)
{
    pthread_t tid[16];
    int n;
    system("/home/marwa/Desktop/os/s.sh");
    queue<int> highPriority;
    queue<int> lowPriority;
    int counter = 0;
        
    while(true)
  {
     
    
    cout << "Press 1 for TIC TAC TOE" << endl;
    cout << "Press 2 to make file" << endl;
    cout << "Press 3 to move file" << endl;
    cout << "Press 4 to copy file content" << endl;
    cout << "Press 5 to delete a file" << endl;
    cout << "Press 6 to read a file" << endl;
    cout << "Press 7 to play battleship game" << endl;
    cout << "Press 8 to play music" << endl;
    cout << "Press 9 to open calendar" << endl;
    cout << "Press 10 to open calculator" << endl;
    cout << "Press 11 to play pacman game" << endl;
    cout << "Press 12 to sort numbers" << endl;
    cout << "Press 13 to convert binary to decimal converter" << endl;
    cout << "Press 14 to open stopwatch" << endl;
    cout << "Press 15 to make directory" << endl;
    cout << "Press 16 to remove directory" << endl;
    cout << "Press 17 to shutdown" << endl;
    cin >> n;

    if ( n== 17)
    {
     
    system("pkill -TERM -f gnome-terminal");

         break;
    }
      
   if (n == 1 || n == 7 || n == 11)
   {
       
       pthread_mutex_lock(&mutex_hp);
       highPriority.push(n);
       pthread_mutex_unlock(&mutex_hp);
   }
   else
   {
        
        pthread_mutex_lock(&mutex_lp);
        lowPriority.push(n);
        pthread_mutex_unlock(&mutex_lp);
   }
   
            // Execute the commands in the high-priority queue first
    while (!highPriority.empty())
        {
            pthread_mutex_lock(&mutex_hp);
            n = highPriority.front();
            highPriority.pop();
            pthread_mutex_unlock(&mutex_hp);
            

            // Get the command to execute based on the value of n
            struct cmd *input = new struct cmd;
            switch (n)
            {
                case 1:
                    input->command = "./tictactoe";
                    input->process = n;
                    break;
                case 7:
                    input->command = "./battleship";
                    input->process = n;
                    break;
                case 11:
                    input->command = "./pacman";
                    input->process = n;
                    break;
               
            }

            // Execute the command
            pthread_create(&tid[counter], NULL, execute, (void*)input);
            counter++;
        }

            // Execute the commands in the low-priority queue next
        while (!lowPriority.empty())
        {
            pthread_mutex_lock(&mutex_lp);
            n = lowPriority.front();
            lowPriority.pop();
            pthread_mutex_unlock(&mutex_lp);
            
            // Get the command to execute based on the value of n
             struct cmd *input = new struct cmd;
            switch (n)
            {
                case 2:
                    void *shared_memory;
                 int shmid;
              shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);

             if (shmid == -1) {
               perror("shmget failed");
                exit(EXIT_FAILURE);
                }

           shared_memory = shmat(shmid, NULL, 0);

              if (shared_memory == (void *)-1) {
                    perror("shmat failed");
                  exit(EXIT_FAILURE);
                } 

/* Initialize hard_drive properly before calling memcpy */
          memcpy(shared_memory, (void *)&hard_drive, sizeof(hard_drive));
          shmdt(shared_memory);
                    input->command = "./makefile";
                    input->process = n;
                    break;
                case 3:
                    input->command = "./movefile";
                    input->process = n;
                    break;
                case 4:
                  
                   memcpy(shared_memory,(void *)&hard_drive,sizeof(hard_drive));
                    input->command = "./copyfile";
		    input->process = n;	
                    break;
                case 5:
             
                  memcpy(shared_memory,(void *)&hard_drive,sizeof(hard_drive));
                     input->command = "./deletefile";
		     input->process = n;
                    break;
                case 6:
                     input->command = "./readfile";
		     input->process = n;
                    break;
                case 8:
                     input->command = "./music";
		     input->process = n;
                    break;
                case 9:
                     input->command = "./calendar";
		     input->process = n;
                    break;
                case 10:
                    input->command = "./cal";
		    input->process = n;
                    break;
                case 12:
                    input->command = "./bubblesort";
		    input->process = n;
                    break;
                case 13:
                    input->command = "./converter";
		    input->process = n;
                    break;
                case 14:
                   input->command = "./stopwatch";
		   input->process = n;
                   break;
                case 15:
                   input->command = "./mdir";
		   input->process = n;
                   break;
                case 16:
                   input->command = "./rdir";
		   input->process = n;
                   break;

            }

            // Execute the command
            pthread_create(&tid[counter], NULL, execute, (void*)input);
            counter++;
        }

   
  } 

  for(int i=0; i < 11;i++)
  { 
     pthread_join(tid[i],NULL);
  }
    pthread_exit(NULL);
}
int main(int argc,char* argv[])
{

    if (argc != 4)
    {
      std::cout << " NOT ENOUGH ARGUMENTS " << std::endl;
      std::cout << "ERROR DETAIL: 3 arguments required"<<std::endl;
      return 1;
    }
    pthread_mutex_init(&mutex_hp, NULL);
pthread_mutex_init(&mutex_lp, NULL);

    ram = stoi(argv[1]);
    hard_drive = stoi(argv[2]);
    cores = stoi(argv[3]);
    process_on_core = new int[cores];
    ram = ram * 1024 * 1024;   //converting ram from gb to kb
    
    for (int i=0; i < cores;i++)
    {
       process_on_core[i] = 0;
    }
    int n;
    system("clear");
cout << "  _______   __     __   ______    \n";
cout << " /  _____| |  \\   /  | |  ____|  \n";
cout << "|  |  __   |   \\_/   | | |__     \n";
cout << "|  | |_ |  |         | |  __|    \n";
cout << "|  |__| |  |  |\\_/|  | | |____   \n";
cout << " \\______|  |__|   |_| |______|  \n\n";
cout << "      F     A     S     T        \n\n";
cout << "    PLEASE WAIT LOADING...      \n";
    sleep(5);
    system("clear");
    cout << "\n\n\n\n       ";
    cout << "\t\t\t Welcome back\t\t\t" << endl;
    sleep(2);
    system("clear");
  
        cout << "Press 1 to continue" << endl;
        cout << "Press any other to key end" << endl;
        cin >> n;
        if (n == 1)
        {
            pthread_t ptid;
            pthread_create(&ptid, NULL, &func, NULL);
            pthread_join(ptid, NULL);
        }
        

    pthread_exit(NULL);
}

