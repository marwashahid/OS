///////////////////////////////////////BATTLESHIP GAME/////////////////////////////////////////////

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
const int r=15,c=15;
int turnE=0,turnP=0;
int Aenemy=0,Benemy=0,Cenemy=0,Senemy=0,Denemy=0,Aplayer=0,Bplayer=0,Cplayer=0,Splayer=0,Dplayer=0;



string names[]={"aircraft","battleship","cruiser","submarine","destroyer"}; //for naming convention needed only one C so changed Carrier to aircraft carrier and used its A
char Letter[]={'A','B','C','S','D'};
char shipBoard[15][15],matrix[15][15],enemyBoard[15][15],attackplayer[15][15],attackenemy[15][15];
int lengths[]={8,5,4,3,2};//ship length
void initialize(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
         shipBoard[i][j]='0';
         enemyBoard[i][j]='0';
         attackplayer[i][j]='0';
         attackenemy[i][j]='0';
        }
       
    }
}
/////////////////////////////////////////////ENEMY ATTACK//////////////////////////////////////////////
void easyattackenemyturn(int x,int y)
{
    turnE++;
    if(shipBoard[x][y]=='A')
    {
        attackenemy[x][y] ='X';
        Aenemy++;
    }
   else if(shipBoard[x][y] =='B')
    {
        attackenemy[x][y] ='X';
        Benemy++;
    }
    else if(shipBoard[x][y]=='C')
    {
        attackenemy[x][y]='X';
        Cenemy++;
    }
    else if(shipBoard[x][y]=='S')
    {
        attackenemy[x][y]='X';
         Senemy++;
    }
    else if(shipBoard[x][y]=='D')
    {
        attackenemy[x][y]='X';
         Denemy++;
    }
else {
    attackenemy[x][y]='+';
    cout<<"\nMissed shot";
}
    if(Aenemy== 16)
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Benemy==10)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cenemy==8)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Senemy==6)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Denemy==4)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    
}

void mediumattackenemyturn(int x,int y)
{
    turnE++;
    if(shipBoard[x][y]=='A')
    {
        attackenemy[x][y]='X';
        Aenemy++;
    }
   else if(shipBoard[x][y]=='B')
    {
        attackenemy[x][y]='X';
        Benemy++;
    }
    else if(shipBoard[x][y]=='C')
    {
        attackenemy[x][y]='X';
        Cenemy++;
    }
    else if(shipBoard[x][y]=='S')
    {
        attackenemy[x][y]='X';
         Senemy++;
    }
    else if(shipBoard[x][y]=='D')
    {
        attackenemy[x][y]='X';
         Denemy++;
    }
else {
    attackenemy[x][y]='+';
    cout<<"\nMissed shot";
}
    if(Aenemy== 24)
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Benemy==15)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cenemy==12)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Senemy==9)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Denemy==6)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    
}

void hardattackenemyturn(int x,int y)
{
    turnE++;
    if(shipBoard[x][y]=='A')
    {
        attackenemy[x][y]='X';
        Aenemy++;
    }
   else if(shipBoard[x][y]=='B')
    {
        attackenemy[x][y]='X';
        Benemy++;
    }
    else if(shipBoard[x][y]=='C')
    {
        attackenemy[x][y]='X';
        Cenemy++;
    }
    else if(shipBoard[x][y]=='S')
    {
        attackenemy[x][y]='X';
         Senemy++;
    }
    else if(shipBoard[x][y]=='D')
    {
        attackenemy[x][y]='X';
         Denemy++;
    }
else {
    attackenemy[x][y]='+';
    cout<<"\nMissed shot";
}
    if(Aenemy== 32)
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Benemy==20)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cenemy==16)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Senemy==12)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Denemy==8)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    
}
///////For computer attac use the enemy one.
////////////////PLAYER ATTACK///////////////////////////////////
void easyattackplayerturn(int x,int y)
{
    turnP++;
    if(enemyBoard[x][y]=='A')
    {
        attackplayer[x][y]='X';
        Aplayer++;
    }
   else if(enemyBoard[x][y]=='B')
    {
        attackplayer[x][y]='X';
        Bplayer++;
    }
    else if(enemyBoard[x][y]=='C')
    {
        attackplayer[x][y]='X';
        Cplayer++;
    }
    else if(enemyBoard[x][y]=='S')
    {
        attackplayer[x][y]='X';
         Splayer++;
    }
    else if(enemyBoard[x][y]=='D')
    {
        attackplayer[x][y]='X';
         Dplayer++;
    }
else {
    attackplayer[x][y]='+';
    cout<<"\nMissed shot";
}
    if(Aplayer== 16)
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Bplayer==10)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cplayer==8)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Splayer==6)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Dplayer==4)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    

}
void mediumattackplayerturn(int x,int y)
{
    turnP++;
    if(enemyBoard[x][y]=='A')
    {
        attackplayer[x][y]='X';
        Aplayer++;
    }
   else if(enemyBoard[x][y]=='B')
    {
        attackplayer[x][y]='X';
        Bplayer++;
    }
    else if(enemyBoard[x][y]=='C')
    {
        attackplayer[x][y]='X';
        Cplayer++;
    }
    else if(enemyBoard[x][y]=='S')
    {
        attackplayer[x][y]='X';
         Splayer++;
    }
    else if(enemyBoard[x][y]=='D')
    {
        attackplayer[x][y]='X';
         Dplayer++;
    }
else {
    attackplayer[x][y]='+';
     cout<<"\nMissed shot";
}
    if(Aplayer== 24)
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Bplayer==15)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cplayer==12)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Splayer==9)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Dplayer==6)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    
}
void hardattackplayerturn(int x,int y)
{
    turnP++;
    if(enemyBoard[x][y]=='A')
    {
        attackplayer[x][y]='X';
        Aplayer++;
    }
   else if(enemyBoard[x][y]=='B')
    {
        attackplayer[x][y]='X';
        Bplayer++;
    }
    else if(enemyBoard[x][y]=='C')
    {
        attackplayer[x][y]='X';
        Cplayer++;
    }
    else if(enemyBoard[x][y]=='S')
    {
        attackplayer[x][y]='X';
         Splayer++;
    }
    else if(enemyBoard[x][y]=='D')
    {
        attackplayer[x][y]='X';
         Dplayer++;
    }
else {
    attackplayer[x][y]='+';
    cout<<"\nMissed shot";
}
cout<<"\n\n";

    if(Aplayer==32 )
    {
        cout<<"\nYou've destroyed all the aircraft carrier ships of enemy !!";
    }
    if(Bplayer==20)
    {
        cout<<"\nYou've destroyed all the Battleship ships of enemy !!";
    }
    if(Cplayer==16)
    {
        cout<<"\nYou,ve destroyed all the Cruiser ships of enemy!!";
    }
    if(Splayer==12)
    {
        cout<<"\nYou've destroyed all the submarine ships of the enemy!!";
    }
    if(Dplayer==8)
    {
        cout<<"\nYou've destroyed all the Destroyer ships of the enemy!!";
    }
    

}
////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////DISPLAY FUNCTIONS/////////////////////////


void displayattackEnemy(int row,int col)  //Enemy attack board display that will show in comparison with the ships player has assigned for enemy to find
{
    cout<<"\nENEMY ATTACK BOARD";
    cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
         cout<<attackenemy[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


void displayattackPlayer(int row,int col)  //player attack board display that will show in comparison with the ships enemy has assigned for player to find

{

cout<<"\nPLAYER ATTACK BOARD";
    cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
         cout<<attackplayer[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void displayB(int row,int col)  //ships placing boared player
{
    cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
         cout<<shipBoard[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void displayE(int row,int col)  //ships placing boared enemy
{
    cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
         cout<<enemyBoard[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
///////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////SHIPS PLACING FUNCTIONS//////////////////////////////
int getCol(int shipNumber,int col)
{
    int last_col=col;
    int x;
    cout<<"\nEnter the row where the front of the ship should be from 0- "<<last_col<<" = ";
    cin>>x;
    //check if user has entered a valid row on the place boared.
    while(x<0||x>last_col-1)
    {
      //messages that value entered is not correct
      cout<<"\nPlease enter a valid starting row position.";
      cout<<"\nYou are placing the "<<names[shipNumber];
      cout<<"\nIts length is = "<<lengths[shipNumber];
      cout<<"\nEnter the row where the front of the ship should be from 0- "<<last_col<<" = ";
    cin>>x;

    }
    return x;
}
int getColComp(int shipNumber,int col)
{
    int last_col=col;
    int x;
    x=rand()%c+1;
    //check if user has entered a valid column on the place boared.
    while(x<0||x>last_col-1)
    {
         x=rand()%c+1;
    }
    return x;
}
int getRow(int shipNumber,int row)
{
    int last_row=row;
    int y;
    cout<<"\nEnter the col where the front of the ship should be from 1- "<<last_row<<" = ";
    cin>>y;
    //check if user has entered a valid column on the place boared.
    while(y<0||y>last_row)
    {
      //messages that value entered is not correct
      cout<<"\nPlease enter a valid starting col position.";
      cout<<"\nYou are placing the "<<names[shipNumber];
      cout<<"\nIts length is = "<<lengths[shipNumber];
      cout<<"\nEnter the col where the front of the ship should be from 1- "<<last_row<<" = ";
    cin>>y;

    }
    return y;
}
int getRowComp(int shipNumber,int row)
{
    int last_row=row;
    int y;
    y=rand()%r+1;
    //check if user has entered a valid column on the place boared.
    while(y<0||y>last_row-1)
    {
         y=rand()%r+1;
    }
    return y;
}
int getDir()
{
    int dir;
    //choose ships direction - 1 for vertical, 2 if the ship is to lie horizontal
    cout << "What direction would you like the ship to face?\n";
    cout << "1. Vertical\n";
    cout << "2. Horizontal\n";
    //user input for ship direction
    cin >> dir;
    //check if user input a valid direction
    while (dir != 1 && dir != 2)
    {
        //clear();
        //playerBoard(shipBoard,rows);
        //tell user selected direction was not valid
        cout << "Please enter a valid direction:\n\n";
        cout << "What direction would you like the ship to face?\n";
        cout << "1.) Vertical\n";
        cout << "2.) Horizontal\n";
        cin >> dir;
    }
    return dir;
}
bool onboard(int rows,int cols,int row,int col) ///this function will return true if row and column(entered by user) given will be on boared
{
    if(rows<0||rows>=row)
    {
        return false;
    }
    if(cols<0||cols>=col)
    {
        return false;
    }
    return true;
}
bool occupied(char shipBoard[][c],int row,int col,int x,int y)
{
    if(!onboard(x,y,row,col))  ///Treat out of bounds as occupied
    {
        return true;
    }
    if(shipBoard[x][y]!='0')  /// Already a character there
    {
        return true;
    }
    return false; // not occupied

}
bool isShipsOverlap(char shipBoard[][c],int row,int col, int startX, int startY, int dir, int length)
{
    if (dir == 1)
    {    //    vertical - Iterate through the rows
        for (int x = startX; x < startX + length; x++)
        {    //    test if occupied or out of bounds
            if (occupied(shipBoard,row,col, x, startY))
                return true;    //    Occupied or out of bounds
        }
    }
    else
    {    // horizontal - Iterate through the columns
        for (int y = startY; y < startY + length; y++)
        {    //    test if occupied or out of bounds
            if (occupied(shipBoard,row,col,startX, y))
                return true;    //    Occupied or out of bounds
        }
    }
    return false;            // Not occupied
}
void placeOneShip(char shipBoard[][c],int row,int col, int startX, int startY, int dir, int length, char letter)
{
    if (dir == 1)
    {    //    vertical position - Iterate through the columns
        for (int x = startX; x < startX + length; x++)
        {    //ship will be positioned with letters marking the ship's orientation
            shipBoard[x][startY] = letter;
        }
    }
    else
    {    //    horizontal position- Iterate through the rows
        for (int y = startY; y < startY + length; y++)
        {    //ship will be positioned with letters marking the ship's orientation
            shipBoard[startX][y] = letter;
        }
    }
}

//Placing ships now one by one
void placePlayerShips(char shipBoard[][c],int row,int col,int m)
{
    int count=0;
    int timeP=0;
    if(m==1)
    {
        timeP=2;
    }
    else if (m == 2)
    {
        timeP=3;
    }
    else if(m == 3)
    {
        timeP=4;
    }
    
    
    //variables for board
    //x and y coordinates for gameplay
    int x;
    int y;
    //direction for vertical or horizontal placement
    int dir;
    //ship number for the loop
    int shipNumber = 0 ;
    
    //booleans to determine if user placement is done and whether or not ships overlap
    bool done = false;
    bool isOverlap =false;
    //while user placement of ships are not done

   while(count<timeP)
   {
    while (done!=true)
    {
        
        displayB(row,col);
        
        cout << "\nYou are placing the " << names[shipNumber] << ".\n";
        cout << "Its length is " << lengths[shipNumber] << ".\n\n";
        
        x = getCol(shipNumber,col);
        y = getRow(shipNumber,row);
        y--;
        int startX = x;
        int startY = y;
        //playerBoard(shipBoard,rows);
        dir = getDir();
        
        if (dir == 2)
        {
            //then the ship shouldn't have vertical orientation - in the original battleship there wasn't placement for diagonals
            dir -= 2;
        }
        isOverlap = isShipsOverlap(shipBoard,row,col, startX, startY, dir, lengths[shipNumber]);

        if (isOverlap == false)
        {
            placeOneShip(shipBoard,row,col, startX, startY, dir, lengths[shipNumber], Letter[shipNumber]);
            cout<<"\n";
            displayB(row,col);
            if (shipNumber < 4)
            {    //increment ship number to next ship to be placed
                shipNumber++;
            }
            else
            {    //now the user is done with ship placement
                done = true;
            }
        }
        //if there was overlap
        else
        {    //user has not entered valid coordinates for the orientation of the ship based on horizontal/vertical alignment or coordinates, or ship overlap
            cout<< " you made an inaccurate assignment of the front of the ship."
                << "\nPlease enter valid coordinates for the ship...\n";

         
        }
    }
    done = false;
    shipNumber = 0;
    count++;
   }
}
void placeEnemyShips(char enemyBoard[][c],int row,int col,int m,int n)
{
    int timeE=0;
    int countE=0;
    //variables for board
    //x and y coordinates for gameplay
    int x;
    int y;
    //direction for vertical or horizontal placement
    int dir;
    //ship number for the loop
    int shipNumber = 0 ;
    
    //booleans to determine if user placement is done and whether or not ships overlap
    bool done = false;
    bool isOverlap =false;
    //while user placement of ships are not done
        int startX ;
        int startY ;

if(n==2)////////////////computer
{

    if(m==1)
    {
        timeE=2;
    }
    else if (m==2)
    {
        timeE=3;
    }
    else if(m== 3)
    {
        timeE=4;
    }
 
  
    
    
    while(countE<timeE)
    {

    while (done!=true)
    {
        
        displayE(row,col);
        
        //cout << "\nYou are placing the " << names[shipNumber] << ".\n";
        //cout << "Its length is " << lengths[shipNumber] << ".\n\n";
        
        x = getColComp(shipNumber,col);
        y = getRowComp(shipNumber,row);
        y--;
         startX = x;
         startY = y;
        //playerBoard(shipBoard,rows);
        dir = rand()%2+1;
        
        if (dir == 2)
        {
            //then the ship shouldn't have vertical orientation - in the original battleship there wasn't placement for diagonals
            dir -= 2;
        }
        isOverlap = isShipsOverlap(enemyBoard,row,col,startX, startY, dir, lengths[shipNumber]);

        if (isOverlap == false)
        {
            placeOneShip(enemyBoard,row,col, startX, startY, dir, lengths[shipNumber], Letter[shipNumber]);
            cout<<"\n\n";
            //displayE(row,col);
            if (shipNumber <= 4)
            {    //increment ship number to next ship to be placed
                shipNumber++;
            }
            else
            {    //now the user is done with ship placement
                done = true;
            }
        }
        //if there was overlap
        else
        {
          done=false;
        }
    }
    done = false;
    shipNumber = 0 ;
    countE++;
    }
    cout<<"\nComputer's done arranging the ships.";
}


/////////////player human
else if(n==1)
{
    if(m==1)
    {
        timeE=2;
    }
    else if (m==2)
    {
        timeE=3;
    }
    else if(m==3)
    {
        timeE=4;
    }

  
    while(countE<timeE)
    {

    while (done!=true)
    {
        
        displayE(row,col);
        
        cout << "\nYou are placing the " << names[shipNumber] << ".\n";
        cout << "Its length is " << lengths[shipNumber] << ".\n\n";
        
        x = getCol(shipNumber,col);
        y = getRow(shipNumber,row);
        y--;
         startX = x;
         startY = y;
        //playerBoard(shipBoard,rows);
        dir = getDir();
        
        if (dir == 2)
        {
            //then the ship shouldn't have vertical orientation - in the original battleship there wasn't placement for diagonals
            dir -= 2;
        }
        isOverlap = isShipsOverlap(enemyBoard,row,col, startX, startY, dir, lengths[shipNumber]);

        if (isOverlap == false)
        {
            placeOneShip(enemyBoard,row, col,startX, startY, dir, lengths[shipNumber], Letter[shipNumber]);
             cout<<"\n\n";
            displayE(row,col);
            if (shipNumber < 4)
            {    //increment ship number to next ship to be placed
                shipNumber++;
            }
            else
            {    //now the user is done with ship placement
                done = true;
            }
        }
        //if there was overlap
        else
        {    //user has not entered valid coordinates for the orientation of the ship based on horizontal/vertical alignment or coordinates, or ship overlap
            cout<< " you made an inaccurate assignment of the front of the ship."<< "\nPlease enter valid coordinates for the ship...\n";

           
        }
    }
    done = false;
    shipNumber = 0 ;
    countE++;
    }
}
}
///////////////////////////////////////////////////////////////

///////////////////////FUNCTION TO DIFFER LEVELS////////////////////////////

void level(int n,int m)
{
    ofstream outfile("wining data");
   if(!outfile.is_open())
{
    cout<<"\nFile not opened.";
}
    int x,y;
    bool gameover=false;
    int row,col;
    if(n==1) //EASY
    {
        initialize(8,8);
        cout<<"\nYou've chosen the Easy level!!!";
        col=8;
        row=8;
        if(m==1)
        {
            cout<<"\nCongratulations You've chosen to play The Easy Level with Two players.\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.\n";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nPlayer 2's turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);

           //now that all the ships has been placed time to system cls
             system("CLS");
           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-8 = ";
               cin>>x>>y;
               while(!(x>=0&&x<8&&y>=0&&y<8))
               {
                  cout<<"\nEnter cordinates between 0-8 = ";
                  cin>>x>>y;
               }
               easyattackplayerturn(x,y);
               displayattackPlayer(8,8);
               cout<<"\n\nPlayer 2's turn = ";
               cout<<"\nEnter the value of row and column between 0-8 = ";
               cin>>x>>y;
               while(!(x>=0&&x<8&&y>=0&&y<8))
               {
                  cout<<"\nEnter cordinates between 0-8 = ";
                  cin>>x>>y;
               }
               easyattackenemyturn(x,y);
               displayattackEnemy(8,8);
            cout<<"\n";

            if(Aplayer==16 && Bplayer==10 && Cplayer==8 && Splayer == 6 && Dplayer == 4)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
               outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==16 && Benemy==10 && Cenemy==8 && Senemy == 6 && Denemy == 4)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!! ";
               outfile<<"CONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!!";
               outfile<<"\n Player 2 after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover=true;
               break;
            }


           }
        }
        if(m==2)
        {
            cout<<"\nCongratulations You've chosen to play The Easy Level with computer .\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nComputer,s turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);

           //now that all the ships has been placed time to system cls
        system("CLS");
           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-8 = ";
               cin>>x>>y;
               while(!(x>=0&&x<8&&y>=0&&y<8))
               {
                  cout<<"\nEnter cordinates between 0-8 = ";
                  cin>>x>>y;
               }
               easyattackplayerturn(x,y);
               displayattackPlayer(8,8);
               
               cout<<"\nComputer's turn  ";
               x=rand()%8+1;
               y=rand()%8+1;
               while(!(x>=0&&x<8&&y>=0&&y<8))
               {
                  x=rand()%8+1;
                  y=rand()%8+1;
               }
               easyattackenemyturn(x,y);
               displayattackEnemy(8,8);
            cout<<"\n";

            if(Aplayer==16 && Bplayer==10 && Cplayer==8 && Splayer == 6 && Dplayer == 4)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==16 && Benemy==10 && Cenemy==8 && Senemy == 6 && Denemy == 4)
            {
                cout<<"\n\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!! ";
                outfile<<"\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!!";
               outfile<<"\n COMPUTER won after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover=true;
               break;
            }

           
        }
      

    }
    }
    if(n==2) //MEDIUM
    {   initialize(12,12);
        cout<<"\nYou've chosen the Medium level!!!";
        row=12;
        col=12;
       if(m==1)
        {
           cout<<"\nCongratulations You've chosen to play The Medium Level with Two players.\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nPlayer 2's turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);
          //now that all the ships has been placed time to system cls
           system("CLS");
           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-12 = ";
               cin>>x>>y;
               while(!(x>=0&&x<12&&y>=0&&y<12))
               {
                  cout<<"\nEnter cordinates between 0-12 = ";
                  cin>>x>>y;
               }
               mediumattackplayerturn(x,y);
               displayattackPlayer(12,12);
               cout<<"\n\nPlayer 2's turn = ";
               cout<<"\nEnter the value of row and column between 0-12 = ";
               cin>>x>>y;
               while(!(x>=0&&x<12&&y>=0&&y<12))
               {
                  cout<<"\nEnter cordinates between 0-12 = ";
                  cin>>x>>y;
               }
               mediumattackenemyturn(x,y);
               displayattackEnemy(12,12);
            cout<<"\n";

            if(Aplayer==24 && Bplayer==15 && Cplayer==12 && Splayer == 9 && Dplayer == 6)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==24 && Benemy==15 && Cenemy==12 && Senemy == 9 && Denemy == 6)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!!";
               outfile<<"\n Player 2 after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover=true;
               break;
            }

           
        }
        }
        if(m==2)
        {
           cout<<"\nCongratulations You've chosen to play The Medium Level with computer .\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nComputer,s turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);
             system("CLS");
           ////now that all the ships has been placed time to system cls 

           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-12 = ";
               cin>>x>>y;
               while(!(x>=0&&x<12&&y>=0&&y<12))
               {
                  cout<<"\nEnter cordinates between 0-12 = ";
                  cin>>x>>y;
               }
               mediumattackplayerturn(x,y);
               displayattackPlayer(12,12);
               
               cout<<"\nComputer's turn  ";
               x=rand()%12+1;
               y=rand()%12+1;
               while(!(x>=0&&x<12&&y>=0&&y<12))
               {
                  x=rand()%12+1;
                  y=rand()%12+1;
               }
               mediumattackenemyturn(x,y);
               displayattackEnemy(12,12);
            cout<<"\n";

            if(Aplayer==24&& Bplayer==15 && Cplayer==12 && Splayer == 9 && Dplayer == 6)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==24 && Benemy==15 && Cenemy==12 && Senemy == 9 && Denemy == 6)
            {
                cout<<"\n\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!! ";
         outfile<<"\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!!";
               outfile<<"\n COMPUTER won after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover=true;
               break;
            }

        }
    }
    }
    if(n==3)///HARD
    {
        initialize(15,15);
        cout<<"\nYou've chosen the Hard level!!!";
        row=15;
        col=15;
       if(m==1)
        {
           cout<<"\nCongratulations You've chosen to play The Hard Level with Two players.\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nPlayer 2's turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);
            system("CLS");
           //now that all the ships has been placed time to system cls

           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-15 = ";
               cin>>x>>y;
               while(!(x>=0&&x<15&&y>=0&&y<15))
               {
                  cout<<"\nEnter cordinates between 0-15 = ";
                  cin>>x>>y;
               }
               hardattackplayerturn(x,y);
               displayattackPlayer(15,15);
               cout<<"\n\nPlayer 2's turn = ";
               cout<<"\nEnter the value of row and column between 0-15 = ";
               cin>>x>>y;
               while(!(x>=0&&x<15&&y>=0&&y<15))
               {
                  cout<<"\nEnter cordinates between 0-15 = ";
                  cin>>x>>y;
               }
               hardattackenemyturn(x,y);
               displayattackEnemy(15,15);
            cout<<"\n";

            if(Aplayer==32 && Bplayer==20 && Cplayer==16 && Splayer == 12 && Dplayer == 8)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==32 && Benemy==20 && Cenemy==16 && Senemy == 12 && Denemy == 8)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 2 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 1!!!!";
               outfile<<"\n Player 2 after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover= true;
               break;
            }
           
        }
        }
        if(m==2)
        {
            cout<<"\nCongratulations You've chosen to play The Hard Level with computer .\nPLayer 1 = Player.\nPlayer 2 = Enemy.";
           cout<<"\nPlayer 1's turn to arrange ships.";
           placePlayerShips(shipBoard,row,col,n);
           cout<<"\n\n";
           cout<<"\nComputer,s turn to arrange ships.";
           placeEnemyShips(enemyBoard,row,col,n,m);

           //now that all the ships has been placed time to system cls
               system("CLS");
           cout<<" \n\n NOW THAT ALL THE SHIPS HAVE BEEN ARRANGED \nITS TIME TO START THE GAME. THE FIRST TURN IS OF PLAYER 1 . ";
           cout<<"\n";
           while(gameover!=true)
           {
               cout<<"\nPlayer 1's turn ";
               cout<<"\nEnter the value of row and column between 0-15 = ";
               cin>>x>>y;
               while(!(x>=0&&x<15&&y>=0&&y<15))
               {
                  cout<<"\nEnter cordinates between 0-15 = ";
                  cin>>x>>y;
               }
               hardattackplayerturn(x,y);
               displayattackPlayer(15,15);
               
               cout<<"\nComputer's turn  ";
               x=rand()%15+1;
               y=rand()%15+1;
               while(!(x>=0&&x<15&&y>=0&&y<15))
               {
                  x=rand()%15+1;
                  y=rand()%15+1;
               }
               hardattackenemyturn(x,y);
               displayattackEnemy(15,15);
            cout<<"\n";

            if(Aplayer==32 && Bplayer==20 && Cplayer==16 && Splayer == 12 && Dplayer == 8)
            {
                cout<<"\n\nCONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!! ";
                outfile<<"CONGRATULATIONS PLAYER 1 HAS WON THE GAME BY DROWNING ALL THE SHIPS OF PLAYER 2!!!!";
               outfile<<"\n Player 1 after  "<<turnP<<" attempts";
               outfile<<"\nThe current attempts of player 2 are "<<turnE;
               gameover=true;
               break;
            }
            if(Aenemy==32 && Benemy==20 && Cenemy==16 && Senemy == 12 && Denemy == 8)
            {
                cout<<"\n\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!! ";
               outfile<<"\n SORRY TRY AGAIN NEXT TIME COMPUTER HAS DROWNED ALL YOUR SHIPS!!!";
               outfile<<"\n COMPUTER won after  "<<turnE<<" attempts";
               outfile<<"\nThe current attempts of player 1 are "<<turnP;
               gameover=true;
               break;
            }

           
        }
}
    }
}


void battle_game()
{     
  float n = 1;
    //displaymemory(n);
int nn,mm;
cout<<"\n===================WELCOME TO BATTLESHIP==============";
cout<<"\n\n===================MAIN MENU=====================";
cout<<"\n\n======================GAME SELECTION=====================";
cout<<"\n\n1-PLAYER VS PLAYER";
cout<<"\n2-PLAYER VS COMPUTER";
cout<<"\nYour choice = ";
cin>>mm;
cout<<"\n\nTHE GAME LEVELS ARE :";
cout<<"\n1-EASY";
cout<<"\n2-MEDIUM";
cout<<"\n3-HARD";
cout<<"\nEnter your preferred choice = ";
cin>>nn;
level(nn,mm);

}

int main()
{

battle_game();



return 0;
}

