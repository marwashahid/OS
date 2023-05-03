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
//Delete a file
int main()
{
    float n = 0.05;
    //displaymemory(n);
    int status;
    char fileName[20];
    cout << "Enter the Name of File: " << endl;
    cin >> fileName;
    status = remove(fileName);
    if (status == 0)
        cout << "\nFile Deleted Successfully!" << endl;
    else
        cout << "\nErorr Occurred!" << endl;
    cout << endl;

std::cin.get();
std::cin.get();
return 0;
}

