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

using namespace std;


sem_t sem_highPriority;
sem_t sem_lowPriority;
pthread_mutex_t mutex_hp;
pthread_mutex_t mutex_lp;

void* execute(void* command)
{
   pid_t pid = fork();
    if (pid == 0 )
    {
    char *cmd = reinterpret_cast<char*>(command);
     int ret= execlp("gnome-terminal", "gnome-terminal", "--",cmd, NULL);
     if (ret == -1) {
        std::cerr << "Failed to execute command: " << cmd << ", Error: " << strerror(errno) << std::endl;
}

  else
   {
     wait(NULL);
   }
   }
   
}

void* func(void* arg)
{
    pthread_t tid[11];
    int n;
    system("/home/marwa/Desktop/os/s.sh");
    queue<int> highPriority;
    queue<int> lowPriority;
    while(true)
  {
     
    
    cout << "Press 1 for TIC TAC TOE" << endl;
    cout << "Press 2 to make file" << endl;
    cout << "Press 3 to move file" << endl;
    cout << "Press 4 to copy file content" << endl;
    cout << "Press 5 to delete a file" << endl;
    cout << "Press 6 to open calendar" << endl;
    cout << "Press 7 to play battleship game" << endl;
    cout << "Press 8 to play music" << endl;
    cout << "Press 9 to open notepad" << endl;
    cout << "Press 10 to open calculator" << endl;
    cout << "Press 11 to play pacman game" << endl;
    cout << "Press 12 to sort numbers" << endl;
    cout << "Press 13 to convert binary to decimal" << endl;
    cout << "Press 14 to open stopwatch" << endl;
    cout << "Press 15 to exit the menu" << endl;
    cin >> n;

    if ( n== 15)
     break;
      
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
            pthread_detach(pthread_self());
            pthread_mutex_lock(&mutex_hp);
            n = highPriority.front();
            highPriority.pop();
            pthread_mutex_unlock(&mutex_hp);
            

            // Get the command to execute based on the value of n
            const char* command;
            switch (n)
            {
                case 1:
                    command = "./tictactoe";
                    break;
                case 7:
                    command = "./battleship";
                    break;
                case 11:
                    command = "./pacman";
                    break;
               
            }

            // Execute the command
            pthread_create(&tid[n-1], NULL, execute, (void*)command);
        }

            // Execute the commands in the low-priority queue next
        while (!lowPriority.empty())
        {
            pthread_detach(pthread_self());
            pthread_mutex_lock(&mutex_lp);
            n = lowPriority.front();
            lowPriority.pop();
            pthread_mutex_unlock(&mutex_lp);
            
            // Get the command to execute based on the value of n
            const char* command;
            switch (n)
            {
                case 2:
                    command = "./makefile";
                    break;
                case 3:
                    command = "./movefile";
                    break;
                case 4:
                    command = "./copyfile";
                    break;
                case 5:
                     command = "./deletefile";
                    break;
                case 6:
                     command = "./calendar";
                    break;
                case 8:
                     command = "./music";
                    break;
                case 9:
                     command = "./notepad";
                    break;
                case 10:
                    command = "./cal";
                    break;
                case 12:
                    command = "./bubblesort";
                    break;
                case 13:
                    command = "./converter";
                    break;
                case 14:
                   command = "./stopwatch";
                   break;
            }

            // Execute the command
            pthread_create(&tid[n-1], NULL, execute, (void*)command);
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
    int n;
    system("clear");
    cout << "\n\n\n\t\t   _   _        __   __" << endl;
    cout << "\t\t  | |_| | |_|  |  | |__  " << endl;
    cout << "\t\t  |     |  _|  |__|  __|" << endl;
    cout << "\n\n\n\t\t  PLEASE WAIT LOADING....." << endl;
    sleep(3);
    system("clear");
    cout << "\n\n\n\n       ";
    cout << "\t\t\t Welcome back\t\t\t" << endl;
    sleep(3);
    system("clear");
  
    
    while (n!=2)
    {
        cout << "Press 1 to continue" << endl;
        cout << "Press 2 to end" << endl;
        cin >> n;
        if (n == 1)
        {
            pthread_t* ptid = new pthread_t[n];
            pthread_create(&ptid[1], NULL, &func, NULL);
            pthread_join(ptid[1], NULL);
        }
        else if (n == 2)
        {
            break;
        }
    }
    pthread_exit(NULL);
}

