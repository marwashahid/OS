#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include<stdio.h>
using namespace std;

// hours, minutes, seconds of timer
int hours = 0;
int minutes = 0;
int seconds = 0;

// function to display the timer
void displayClock()
{
    // system call to clear the screen
    system("clear");

    cout << setfill(' ') << setw(55) << "         Stopwatch        \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << "Press any key to stop" << endl;
}

// function to check if a key is pressed
bool kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

void timer()
{
    // infinite loop because timer will keep
    // counting. To kill the process press
    // Ctrl+C.

    while (!kbhit())
    {

        // display the timer
        displayClock();

        // sleep system call to sleep
        // for 1 second
        sleep(1);

        // increment seconds
        seconds++;

        // if seconds reaches 60
        if (seconds == 60) {

            // increment minutes
            minutes++;

            // if minutes reaches 60
            if (minutes == 60) {

                // increment hours
                hours++;
                minutes = 0;
            }
            seconds = 0;
        }
    }
}

// Driver Code
int main()
{
    // start timer from 00:00:00
    cout << "Press any key to start" << endl;
    
    timer();
    std::cin.get();
    std::cin.get();
    return 0;
}

