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
int main()
{
    float n = 0.25;
    //displaymemory(n);

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
        cout << "File created successfully.";
    }

std::cin.get();
std::cin.get();
return 0;
}

