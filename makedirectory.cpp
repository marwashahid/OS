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
void Directory();

int main()
{
string create = "mkdir ";
string dirName;
cout << "Enter Directory Name:     ";
getline(cin, dirName);
ifstream Directory;
Directory.open(dirName);
if(!Directory.is_open())
{
create = create + dirName;
const char* createdir = create.c_str();
system(createdir);
cout << "Directory Created Successfully.\n" << endl;
}
else
{
cout << "Directory Already Exist.\n" << endl;
}

cin.get();
return 0;
}








