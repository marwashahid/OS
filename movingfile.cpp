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

using namespace std;
//MOVING FILE
int main()
{
    float n = 0.05;
    //displaymemory(n);
    int result = 1;
    char oldname[500];
    char newname[500];
    cout << "Enter the name of a file you want to move (include directory structure)" << endl;
    cin >> oldname;
    cout << "Enter the new location (include directory structure)" << endl;
    cin >> newname;

    result = rename(oldname, newname);
    if (result == 0)
        cout << "File successfully moved" << endl;
    else
        cout << "Error moving file" << endl;

std::cin.get();
std::cin.get();
return 0;
}
