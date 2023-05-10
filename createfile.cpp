#include<iostream>
#include<string.h>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
string create = "touch ";
string fileName;

cout << "Enter the File Name:     ";
getline(cin, fileName);
ifstream file;
file.open(fileName);
if(!file.is_open())
{
create = create + fileName;
const char* createfile = create.c_str();
system(createfile);
cout << "File Created Successfully.\n" << endl;
}
else
{
cout << "File Already Exist.\n" << endl;
}

return 0;
}
