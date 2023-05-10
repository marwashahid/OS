#include<iostream>
#include<string.h>
#include<fstream>
#include"semphore.h"
using namespace std;


int main()
{


std::string filename,content;
cout << "Enter the name of the file to edit: ";
            getline(cin,filename);
            // Open the file for reading and writing
            fstream editFile(filename.c_str(), ios::app);

            if (editFile.is_open()) {
                // Get the content to write to the file
                cout << "Enter the new content for " << filename << ":" << endl;
                 
                getline(cin, content);

                // Overwrite the old content with the new content
                
                editFile << "\n";
                editFile << content;
                
                // Close the file
                editFile.close();

                cout << "File saved" << endl;
               
            } 
else {
                // File not found
                cout << "File not found" << endl;
 }


return 0;
}
