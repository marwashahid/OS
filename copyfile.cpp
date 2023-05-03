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
//COPY FILE
int main()
{
    float n = 0.05;
   // displaymemory(n);
    char ch, sourceFile[20], targetFile[20];
    FILE* fs, * ft;
    cout << "Enter the Name of Source File: ";
    cin >> sourceFile;
    fs = fopen(sourceFile, "r");
    if (fs == NULL)
    {
        cout << "\nError Occurred!";
    }
    cout << "\nEnter the Name of Target File: ";
    cin >> targetFile;
    ft = fopen(targetFile, "w");
    if (ft == NULL)
    {
        cout << "\nError Occurred!";
    }
    ch = fgetc(fs);
    while (ch != EOF)
    {
        fputc(ch, ft);
        ch = fgetc(fs);
    }
    cout << "\nFile copied successfully.";
    fclose(fs);
    fclose(ft);
    cout << endl;

std::cin.get();
std::cin.get();
return 0;
}
