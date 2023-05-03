#include <iostream>
#include<fstream>
#include <stdlib.h>

int main()
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return 1;
    }
    std::string command = "canberra-gtk-play -f " + filename;
    system(command.c_str());

    std::cin.get();
    std::cin.get();
    return 0;
}

