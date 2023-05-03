#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename, line, content;
    char option;

    cout << "Welcome to Notepad" << endl;
    cout << "Please select an option:" << endl;
    cout << "R: Read a file" << endl;
    cout << "W: Write to a file" << endl;
    cout << "E: Edit a file" << endl;

    cin >> option;

    switch (option) {
        case 'R':
        case 'r':
          {
            cout << "Enter the name of the file to read: ";
            cin >> filename;

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
            break;
          }

        case 'W':
        case 'w':
        {
            cout << "Enter the name of the file to write to: ";
            cin >> filename;

            // Open the file for writing
            ofstream outputFile(filename.c_str());

            // Get the content to write to the file
            cout << "Enter the content to write to " << filename << ":" << endl;
            cin.ignore(); // ignore the newline character from previous input
            getline(cin, content);

            // Write the content to the file
            outputFile << content;

            // Close the file
            outputFile.close();

            cout << "File saved" << endl;
            break;
          }
        case 'E':
        case 'e':
        {
            cout << "Enter the name of the file to edit: ";
            cin >> filename;

            // Open the file for reading and writing
            fstream editFile(filename.c_str(), ios::in | ios::out);

            if (editFile.is_open()) {
                // Get the content to write to the file
                cout << "Enter the new content for " << filename << ":" << endl;
                cin.ignore(); // ignore the newline character from previous input
                getline(cin, content);

                // Overwrite the old content with the new content
                editFile.seekg(0, ios::end);
                editFile << content;

                // Close the file
                editFile.close();

                cout << "File saved" << endl;
            } else {
                // File not found
                cout << "File not found" << endl;
            }

            break;
         }
        default:
            cout << "Invalid option" << endl;
            break;
    }

    std::cin.get();
    std::cin.get();
    return 0;
}

