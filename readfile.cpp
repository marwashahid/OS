
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{

std::string filename;
std::string content, line;
cout << "Enter the name of the file to read: ";
           getline(std::cin,filename);

            // Open the file for reading
            ifstream inputFile(filename.c_str());

            if (inputFile.is_open()) {
                // Read the contents of the file
                while (getline(inputFile, line)) {
                    content += line + "\n";
                }

                // Display the contents of the file
                cout << "Contents of " << filename << ":" << endl;
                cout << content << endl;
            } else {
                // File not found
                cout << "File not found" << endl;
            }

            // Close the file
            inputFile.close();

cin.get();
return 0;

}
