#include<iostream>
#include<fstream>
#include<iomanip>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
using namespace std;
class library_management_system {
	string Title;
	string author;
	int ISBN, Old_IS, Old_T, Old_A;
	int Number_of_copy, Old_NC;
	int count;
	string* A;
	string* T;
	int* IS;
	int* No;
	fstream Author;
	fstream title;
	fstream Isbn;
	fstream Number_Of_Copy;
public:
	library_management_system()
	{
		count = 0;
		Old_T = -1;
		Old_A = -1;
		Old_IS = -1;
		Old_NC = -1;
		Title = " ";
		author = " ";
		ISBN = -1;
		Number_of_copy = -1;
	}
	int Count()
	{
		count = 0;
		Author.open("Auhtor_name.txt", ios::in);
		while (Author >> author)
		{
			++count;
		}
		Author.close();
		return count;
	}
	void create()
	{
		cout << " Enter the title of book :";
		cin >> Title;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> Title;
			cout << " Not a valid input \n";
			cout << " Input must be string\n";
		}
		cout << " Enter the name of author :";
		cin >> author;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> author;
			cout << " Not a valid input \n";
			cout << " Input must be string \n";
		}
		cout << " Enter the ISBN number :";
		cin >> ISBN;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> ISBN;
			cout << " Not a valid input \n";
			cout << " Input must be integer \n";
		}
		cout << " Enter the number of copies :";
		cin >> Number_of_copy;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> Number_of_copy;
			cout << " Not a valid input \n";
			cout << " Input must be integer \n";
		}
		Author.open("Auhtor_name.txt", ios::app);
		title.open("Book_Title.txt", ios::app);
		Isbn.open("ISBN_Number.txt", ios::app);
		Number_Of_Copy.open("Number_of_copies.txt", ios::app);
		Author << author << endl;
		title << Title << endl;
		Isbn << ISBN << endl;
		Number_Of_Copy << Number_of_copy << endl;
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
	}
	void update(int n)
	{
		A = new string[n];
		T = new string[n];
		IS = new  int[n];
		No = new int[n];
		int choice;
		Old_T = -1;
		Old_A = -1;
		Old_IS = -1;
		Old_NC = -1;
		Author.open("Auhtor_name.txt", ios::in);
		title.open("Book_Title.txt", ios::in);
		Isbn.open("ISBN_Number.txt", ios::in);
		Number_Of_Copy.open("Number_of_copies.txt", ios::in);
		do {
			system("cls");
			cout << "\n              _________________________________________________\n";
			cout << "              |          Update Any Book                       |     \n";
			cout << "              |________________________________________________|\n\n";
			cout << " Press 1 for Auhtor name Updation \n";
			cout << " Press 2 for book Title Updation \n";
			cout << " Press 3 for ISBN number Updation \n";
			cout << " Press 4 for Number of copies Updation \n";
			cout << " Press 5 for Exit \n";
			cin >> choice;
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cin >> choice;
				cout << " Not a valid input \n";
				cout << " Input must be integer between(1 to 5)\n";
			}
			switch (choice) {
			case 1: {
				cout << "Enter the old ISBN number of book :";
				cin >> Old_A;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Old_A;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				cout << "Enter the Author  name :";
				cin >> author;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> author;
					cout << " Not a valid input \n";
					cout << " Input must be string\n";
				}
				break;
			}
			case 2: {
				cout << "Enter the old ISBN number of book :";
				cin >> Old_T;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Old_T;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				cout << "Enter the new title :";
				cin >> Title;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Title;
					cout << " Not a valid input \n";
					cout << " Input must be string \n";
				}
				break;
			}
			case 3: {
				cout << "Enter the old ISBN number :";
				cin >> Old_IS;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Old_IS;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				cout << "Enter the new ISBN number :";
				cin >> ISBN;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> ISBN;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				break;
			}
			case 4: {
				cout << "Enter the ISBN number of book :";
				cin >> Old_NC;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Old_NC;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				cout << "Enter the new Number of copies :";
				cin >> Number_of_copy;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cin >> Number_of_copy;
					cout << " Not a valid input \n";
					cout << " Input must be integer \n";
				}
				break;
			}
			case 5: {
				cout << "    Terminate Update function    \n";
				break;
			}
			}
		} while (choice != 5);
		bool exist = true;
		for (int i = 0; i < n; ++i)
		{
			Author >> A[i];
			title >> T[i];
			Isbn >> IS[i];
			Number_Of_Copy >> No[i];
			if (Old_A != -1 && Old_A == IS[i])
			{
				A[i] = author;
				exist = false;
			}
			else if (Old_IS != -1 && Old_IS == IS[i])
			{
				IS[i] = ISBN;
				exist = false;
			}
			else if (Old_T != -1 && Old_T == IS[i])
			{
				T[i] = Title;
				exist = false;
			}
			else if (Old_NC != -1 && Old_NC == IS[i])
			{
				No[i] = Number_of_copy;
				exist = false;
			}
		}
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
		Author.open("Auhtor_name.txt", ios::out);
		title.open("Book_Title.txt", ios::out);
		Isbn.open("ISBN_Number.txt", ios::out);
		Number_Of_Copy.open("Number_of_copies.txt", ios::out);
		for (int i = 0; i < n; ++i)
		{
			Author << A[i] << endl;
			title << T[i] << endl;
			Isbn << IS[i] << endl;
			Number_Of_Copy << No[i] << endl;
		}
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
		delete[] A;
		delete[] T;
		delete[]IS;
		delete[]No;
		if (exist)
		{
			cout << " This data dose not exist \n";
		}
		else {
			cout << " Updation done \n";
		}
	}
	void deletion(int n)
	{
		A = new string[n];
		T = new string[n];
		IS = new  int[n];
		No = new int[n];
		int choice;
		bool exist = true;
		Author.open("Auhtor_name.txt", ios::in);
		title.open("Book_Title.txt", ios::in);
		Isbn.open("ISBN_Number.txt", ios::in);
		Number_Of_Copy.open("Number_of_copies.txt", ios::in);
		for (int i = 0; i < n; ++i)
		{
			Author >> A[i];
			title >> T[i];
			Isbn >> IS[i];
			Number_Of_Copy >> No[i];
		}
		cout << "Enter the ISBN number of book :";
		cin >> ISBN;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> Old_NC;
			cout << " Not a valid input \n";
			cout << " Input must be integer \n";
		}
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
		Author.open("Auhtor_name.txt", ios::out);
		title.open("Book_Title.txt", ios::out);
		Isbn.open("ISBN_Number.txt", ios::out);
		Number_Of_Copy.open("Number_of_copies.txt", ios::out);
		for (int i = 0; i < n; ++i)
		{
			if (ISBN != IS[i])
			{
				Author << A[i] << endl;
				title << T[i] << endl;
				Isbn << IS[i] << endl;
				Number_Of_Copy << No[i] << endl;
			}
			else {
				exist = false;
			}
		}
		if (exist)
		{
			cout << " This data dose not exist \n";
		}
		else {
			cout << " Deletion done \n";
		}
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
		delete[] A;
		delete[] T;
		delete[]IS;
		delete[]No;
	}
	void display(int n)
	{
		system("cls");
		cout << "\n                        Library Managment System                   \n\n";
		if (n == 0)
		{
			cout << "Library is Empty   \n";
			return;
		}
		A = new string[n];
		T = new string[n];
		IS = new  int[n];
		No = new int[n];
		Author.open("Auhtor_name.txt", ios::in);
		title.open("Book_Title.txt", ios::in);
		Isbn.open("ISBN_Number.txt", ios::in);
		Number_Of_Copy.open("Number_of_copies.txt", ios::in);
		for (int i = 0; i < n; ++i)
		{
			Author >> A[i];
			title >> T[i];
			Isbn >> IS[i];
			Number_Of_Copy >> No[i];
		}
		Author.close();
		title.close();
		Isbn.close();
		Number_Of_Copy.close();
		cout << "____________________________________________________________________________\n";
		cout << "|  Sr  " << "| Title of book     " << "| Author_Name      " << "|  ISBN number      " << "| Copies  |" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << "|______|___________________|__________________|___________________|_________|\n";
			cout << "|  " << i + 1 << "   |" << setw(15) << T[i] << "    |" << setw(15) << A[i] << "   |" << setw(10) << IS[i] << "         |" << setw(6) << No[i] << "   |" << endl;
		}
		cout << "|______|___________________|__________________|___________________|_________|\n";
	}
};
int main()
{
	
	library_management_system obj;
	int choice;
	do {
		cout << "\n              _________________________________________________\n";
		cout << "              |          Welcome To Library Management         |     \n";
		cout << "              |________________________________________________|\n\n";
		cout << "Add a new book (press 1)\n";
		cout << "Update any book (press 2)\n";
		cout << "Delete any book (press 3)\n";
		cout << "Display all books (press 4)\n";
		cout << "Exit (press 5)\n";
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> choice;
			cout << " Not a valid input \n";
			cout << " Input must be integer between(1 to 5)\n";
		}
		switch (choice) {
		case 1:
		{
			system("cls");
			cout << "\n              _________________________________________________\n";
			cout << "              |          ADD A NEW BOOK                        |     \n";
			cout << "              |________________________________________________|\n\n";
			obj.create();
			break;
		}
		case 2:
		{
			obj.update(obj.Count());
			break;
		}
		case 3:
		{system("cls");
		cout << "\n              _________________________________________________\n";
		cout << "              |          Delete Any Book                       |     \n";
		cout << "              |________________________________________________|\n\n";
		obj.deletion(obj.Count());
		break;
		}
		case 4:
		{
			obj.display(obj.Count());
			break;
		}
		case 5:
		{


			cout << "                        Program Terminated                            \n";
			cout << "              ________________________________________________\n\n";
		}
		default: {
			cout << "   Invalid Input    \n";
		}
		}
	} while (choice != 5);

	
std::cin.get();
    std::cin.get();

return 0;
}
