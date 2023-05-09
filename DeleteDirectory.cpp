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
#include<iostream>

using namespace std;
int main()
{
string remove = "rmdir ";
string dirName;
cout << "Enter Directory Name:     ";
getline(cin, dirName);
ifstream Directory;
Directory.open(dirName);
if(!Directory.is_open())
{
cout << "Directory Not Exist.\n" << endl;
}
else
{
remove = remove + dirName;
const char* rmDirectory = remove.c_str();
system(rmDirectory);
cout << "Directory Deleted Successfully.\n" << endl;
}

cin.get();
return 0;
}

