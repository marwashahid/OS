#include<iostream>
#include<unistd.h>

using namespace std;
void displaypacman(char map[32][28], int& i, int& j)
{
   map[32][28] = {};
   for (int i = 0; i < 32; i++)
   {
       for (int j = 0; j < 28; j++)
       {
           map[i][j] = '.';
       }
   }
   for (int i = 6; i < 26; i++)
   {
       map[i][4] = '|';
   }
   for (int i = 6; i < 26; i++)
   {
       map[i][24] = '|';
   }
   for (int j = 4; j < 25; j++)
   {
       map[3][j] = '_';
   }
   for (int j = 4; j < 25; j++)
   {
       map[28][j] = '_';
   }
   for (int i = 10; i < 16; i++)
   {
       map[i][8] = '|';
   }
   for (int j = 8; j < 18; j++)
   {
       map[16][j] = '_';
   }
   for (int j = 8; j < 18; j++)
   {
       map[20][j] = '_';
   }
   for (int i = 20; i < 26; i++)
   {
       map[i][18] = '|';
   }
   map[5][5] = 'P';
   map[7][9] = ',';
   map[12][15] = ',';
   map[19][23] = ',';
   map[25][30] = ',';
   map[8][18] = ',';
   cout << " ________________________________________________________" << endl;
   for (int i = 0; i < 32; i++)
   {
       // print the first character as part of the opener.
       cout << " " << "|" << map[i][0];
       for (int j = 1; j < 28; j++)
       {
           // only add spaces for subsequent characters.
           cout << " " << map[i][j];
       }
       cout << "|" << endl;
   }
   cout << " ________________________________________________________" << endl;
}
void movepacman(char map[32][28], int& i, int& j, char& b)
{
   i = 5;
   j = 5;
   while (b != 'e')
   {
       displaypacman(map, i, j);
       cin >> b;
       if (b == 72)
       {
           if (map[i - 1][j] != '_' && map[i - 1][j] != '|')
           {
               if (map[i - 1][j] == ' ' && map[i - 2][j] == '.')
               {
                   map[i - 2][j] = 'P';
                   map[i][j] = ' ';
                   i--;
                   system("clear");
                   displaypacman(map, i, j);
               }
           }
       }
       if (b == 80)
       {
           if (map[i + 1][j] != '_' && map[i + 1][j] != '|')
           {
               if (map[i + 1][j] == ' ' && map[i + 2][j] == '.')
               {
                   map[i + 2][j] = 'P';
                   map[i][j] = ' ';
                   i++;
                   system("clear");
                   displaypacman(map, i, j);
               }
           }
       }
       if (b == 75)
       {
           if (map[i][j - 1] != '_' && map[i][j - 1] != '|')
           {
               if (map[i][j - 1] == ' ' && map[i][j - 2] == '.')
               {
                   map[i][j - 2] = 'P';
                   map[i][j] = ' ';
                   j--;
                   system("clear");
                   displaypacman(map, i, j);
               }
           }
       }
       if (b == 77)
       {
           if (map[i][j + 1] != '_' && map[i][j + 1] != '|')
           {
               if (map[i][j + 1] == ' ' && map[i][j + 2] == '.')
               {
                   map[i][j + 2] = 'P';
                   map[i][j] = ' ';
                   j++;
                   system("clear");
                   displaypacman(map, i, j);
               }
           }
       }
   }
}
//GAME PACMAN
void pacman()
{
   int i = 5;
   int j = 5;
   char b;
   char map[32][28];
   int a;
   cout << "PRESS 1 TO PLAY GAME" << endl;
   cout << "PRESS 2 TO READ INSTRUCTIONS" << endl;
   cin >> a;
   system("clear");
   if (a == 1)
   {
       cout << "PACMAN GAME" << endl;
       //sleep(2);
       //system("clear");
       cout << "PLEASE WAIT WHILE GAME IS LOADING.....";
       for (int i = 0; i < 35; i++)
       {
           cout << '|';
           sleep(2);
       }
       cout << endl;
       sleep(2);
       system("clear");
       displaypacman(map, i, j);
       movepacman(map, i, j, b);
   }
   else if (a == 2)
   {
       cout << "Guide Pacman around the maze and eat all the little white dots whilst avoiding those nasty ghosts." << endl;
       cout << "If you eat a Power Pill, you can eat the ghosts! Occasionally, a fruit appears which gives you a bonus score when eaten.";
       sleep(2);
       system("clear");
   }
 
 
}

int main()
{

pacman();

std::cin.get();
std::cin.get();
return 0;
}
