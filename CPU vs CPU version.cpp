//Ryan Finley and Levi Hazelwood

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;


class Tile
{
private:

int location;
bool unoccupied;

public:
void set(int);
char state;

bool LeviChoose(void);
bool RyanChoose(void);

};
class Board
{
public:
Tile tile1;
Tile tile2;
Tile tile3;
Tile tile4;
Tile tile5;
Tile tile6;
Tile tile7;
Tile tile8;
Tile tile9;
Board();
void showBoard(void);
bool tileChoose(bool, int);
bool gameCheck(bool);
};
class Board3d: public Board
{

public:
Tile tileB1;
Tile tileB2;
Tile tileB3;
Tile tileB4;
Tile tileB5;
Tile tileB6;
Tile tileB7;
Tile tileB8;
Tile tileB9;
Tile tileC1;
Tile tileC2;
Tile tileC3;
Tile tileC4;
Tile tileC5;
Tile tileC6;
Tile tileC7;
Tile tileC8;
Tile tileC9;
Board3d();
void showBoard(void);
bool tileChoose(bool, int);
bool gameCheck(bool);

};



int levinum;
int ryannum;

int main()
{
int i = 0;
srand(time(NULL));
for(i=0; i<10; i++)
{	
Board3d board;

//bool PlayerTurn=1;
bool PlayerTurn=(rand()%2);
bool gameOver=0;
int selection;
bool endTurn;



while(gameOver==0)
{

do
{
if(PlayerTurn)
{
selection=(rand()%27)+1;
endTurn=board.tileChoose(PlayerTurn, selection);
if (endTurn)
{
gameOver=board.gameCheck(PlayerTurn);
PlayerTurn=0;
}

}
else
{
selection=(rand()%27)+1;
endTurn=board.tileChoose(PlayerTurn, selection);
if(endTurn)
{
gameOver=board.gameCheck(PlayerTurn);
PlayerTurn=1;
}
}


}while(endTurn==0);


}

board.showBoard();

if(i == 9)
{
	cout<< "\nFinal Scores: \nLevi's Score: " << levinum << "\nRyan's Score: " << ryannum;
	
	if(levinum>ryannum)
	{
	cout<<endl<<"Levi Wins!";
	return 1;
	}
	else if(ryannum>levinum)
	{
	cout<<endl<<"Ryan Wins!";
	return 1;
	}
	else if(levinum==ryannum)
	{
	cout<<endl<<"Levi and Ryan Tied!";
	}
}
}
return 0;
}

void Tile::set(int num)
{
location=num;
unoccupied=1;
state=' ';
}
bool Tile::LeviChoose()
{
if(unoccupied)
{
state='X';
unoccupied=0;
return 1;
}
else
{
return 0;
}

}
bool Tile::RyanChoose()
{
if(unoccupied)
{
state='O';
unoccupied=0;
return 1;
}
else
{
return 0;
}

}

Board::Board()
{
tile1.set(1);
tile2.set(2);
tile3.set(3);
tile4.set(4);
tile5.set(5);
tile6.set(6);
tile7.set(7);
tile8.set(8);
tile9.set(9);
}
void Board::showBoard()
{
cout<<endl<<"|-------|-------|-------|"<<endl;
cout<<"| ("<<tile1.state<<") | ("<<tile2.state<<") | ("<<tile3.state<<") |"<<endl<<"| 1 | 2 | 3 |"<<endl;
cout<<"|-------|-------|-------|"<<endl;
cout<<"| ("<<tile4.state<<") | ("<<tile5.state<<") | ("<<tile6.state<<") |"<<endl<<"| 4 | 5 | 6 |"<<endl;
cout<<"|-------|-------|-------|"<<endl;
cout<<"| ("<<tile7.state<<") | ("<<tile8.state<<") | ("<<tile9.state<<") |"<<endl<<"| 7 | 8 | 9 |"<<endl;
cout<<"|-------|-------|-------|"<<endl;

}
bool Board::tileChoose(bool PlayerTurn, int selection)
{

if(PlayerTurn)
{
switch(selection)
{
case 1:
{
return tile1.LeviChoose();
break;
}
case 2:
{
return tile2.LeviChoose();
break;
}
case 3:
{
return tile3.LeviChoose();
break;
}
case 4:
{
return tile4.LeviChoose();
break;
}
case 5:
{
return tile5.LeviChoose();
break;
}
case 6:
{
return tile6.LeviChoose();
break;
}
case 7:
{
return tile7.LeviChoose();
break;
}
case 8:
{
return tile8.LeviChoose();
break;
}
case 9:
{
return tile9.LeviChoose();
break;
}
default:
{
return 0;
}

}
}
else
{
switch(selection)
{
case 1:
{
return tile1.RyanChoose();
break;
}
case 2:
{
return tile2.RyanChoose();
break;
}
case 3:
{
return tile3.RyanChoose();
break;
}
case 4:
{
return tile4.RyanChoose();
break;
}
case 5:
{
return tile5.RyanChoose();
break;
}
case 6:
{
return tile6.RyanChoose();
break;
}
case 7:
{
return tile7.RyanChoose();
break;
}
case 8:
{
return tile8.RyanChoose();
break;
}
case 9:
{
return tile9.RyanChoose();
break;
}
default:
{
return 0;
}

}

}


}
bool Board::gameCheck(bool PlayerTurn)
{
int endGame=0;
char empty=' ';
if (tile1.state==tile2.state&&tile1.state==tile3.state&&tile1.state!=empty)
{
endGame=1;

}
else if (tile1.state==tile4.state&&tile1.state==tile7.state&&tile1.state!=empty)
{
endGame=1;

}
else if (tile1.state==tile5.state&&tile1.state==tile9.state&&tile1.state!=empty)
{
endGame=1;

}
else if (tile2.state==tile5.state&&tile2.state==tile8.state&&tile2.state!=empty)
{
endGame=1;

}
else if (tile3.state==tile5.state&&tile3.state==tile7.state&&tile3.state!=empty)
{
endGame=1;

}
else if (tile3.state==tile6.state&&tile3.state==tile9.state&&tile3.state!=empty)
{
endGame=1;

}
else if (tile4.state==tile5.state&&tile4.state==tile6.state&&tile4.state!=empty)
{
endGame=1;

}
else if (tile7.state==tile8.state&&tile7.state==tile9.state&&tile7.state!=empty)
{
endGame=1;

}
else if (tile1.state!=empty&&tile2.state!=empty&&tile3.state!=empty&&tile4.state!=empty&&tile5.state!=empty&&tile6.state!=empty&&tile7.state!=empty&&tile8.state!=empty&&tile9.state!=empty&&endGame!=1)
{
endGame=2;
}
else
{
endGame=0;
}

if (endGame==1)
{
cout<<endl<<"GAME OVER";
if(PlayerTurn)
{
cout<<endl<<"Levi Wins!";
return 1;
}
else
{
cout<<endl<<"Ryan Wins!";
return 1;
}

}
else if (endGame==2)
{
cout<<endl<<"GAME OVER"<<endl<<"Levi and Ryan Tied!";
}
else
{
return 0;
}
}
Board3d::Board3d()
{
Board();

tileB1.set(10);
tileB2.set(11);
tileB3.set(12);
tileB4.set(13);
tileB5.set(14);
tileB6.set(15);
tileB7.set(16);
tileB8.set(17);
tileB9.set(18);

tileC1.set(19);
tileC2.set(20);
tileC3.set(21);
tileC4.set(22);
tileC5.set(23);
tileC6.set(24);
tileC7.set(25);
tileC8.set(26);
tileC9.set(27);
}
void Board3d::showBoard()
{
cout<<endl<<"|-------|-------|-------|"<<endl;
cout<<"|  ("<<tile1.state<<")  |  ("<<tile2.state<<")  |  ("<<tile3.state<<")  |"<<endl<<"|   1   |   2   |   3   |"<<endl;
cout<<"|-------|-------|-------|"<<endl;
cout<<"|  ("<<tile4.state<<")  |  ("<<tile5.state<<")  |  ("<<tile6.state<<")  |"<<endl<<"|   4   |   5   |   6   |"<<endl;
cout<<"|-------|-------|-------|"<<endl;
cout<<"|  ("<<tile7.state<<")  |  ("<<tile8.state<<")  |  ("<<tile9.state<<")  |"<<endl<<"|   7   |   8   |   9   |"<<endl;
cout<<"|-------|-------|-------|"<<endl;

cout<<endl<<"\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t|  ("<<tileB1.state<<")  |  ("<<tileB2.state<<")  |  ("<<tileB3.state<<")  |"<<endl<<"\t\t|  10   |  11   |  12   |"<<endl;
cout<<"\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t|  ("<<tileB4.state<<")  |  ("<<tileB5.state<<")  |  ("<<tileB6.state<<")  |"<<endl<<"\t\t|  13   |  14   |  15   |"<<endl;
cout<<"\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t|  ("<<tileB7.state<<")  |  ("<<tileB8.state<<")  |  ("<<tileB9.state<<")  |"<<endl<<"\t\t|  16   |  17   |  18   |"<<endl;
cout<<"\t\t|-------|-------|-------|"<<endl;

cout<<endl<<"\t\t\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t\t\t|  ("<<tileC1.state<<")  |  ("<<tileC2.state<<")  |  ("<<tileC3.state<<")  |"<<endl<<"\t\t\t\t|  19   |  20   |  21   |"<<endl;
cout<<"\t\t\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t\t\t|  ("<<tileC4.state<<")  |  ("<<tileC5.state<<")  |  ("<<tileC6.state<<")  |"<<endl<<"\t\t\t\t|  22   |  23   |  24   |"<<endl;
cout<<"\t\t\t\t|-------|-------|-------|"<<endl;
cout<<"\t\t\t\t|  ("<<tileC7.state<<")  |  ("<<tileC8.state<<")  |  ("<<tileC9.state<<")  |"<<endl<<"\t\t\t\t|  25   |  26   |  27   |"<<endl;
cout<<"\t\t\t\t|-------|-------|-------|"<<endl;

}
bool Board3d::tileChoose(bool PlayerTurn, int selection)
{

if(PlayerTurn)
{
switch(selection)
{
case 1:
{
return tile1.LeviChoose();
break;
}
case 2:
{
return tile2.LeviChoose();
break;
}
case 3:
{
return tile3.LeviChoose();
break;
}
case 4:
{
return tile4.LeviChoose();
break;
}
case 5:
{
return tile5.LeviChoose();
break;
}
case 6:
{
return tile6.LeviChoose();
break;
}
case 7:
{
return tile7.LeviChoose();
break;
}
case 8:
{
return tile8.LeviChoose();
break;
}
case 9:
{
return tile9.LeviChoose();
break;
}
case 10:
{
return tileB1.LeviChoose();
break;
}
case 11:
{
return tileB2.LeviChoose();
break;
}
case 12:
{
return tileB3.LeviChoose();
break;
}
case 13:
{
return tileB4.LeviChoose();
break;
}
case 14:
{
return tileB5.LeviChoose();
break;
}
case 15:
{
return tileB6.LeviChoose();
break;
}
case 16:
{
return tileB7.LeviChoose();
break;
}
case 17:
{
return tileB8.LeviChoose();
break;
}
case 18:
{
return tileB9.LeviChoose();
break;
}
case 19:
{
return tileC1.LeviChoose();
break;
}
case 20:
{
return tileC2.LeviChoose();
break;
}
case 21:
{
return tileC3.LeviChoose();
break;
}
case 22:
{
return tileC4.LeviChoose();
break;
}
case 23:
{
return tileC5.LeviChoose();
break;
}
case 24:
{
return tileC6.LeviChoose();
break;
}
case 25:
{
return tileC7.LeviChoose();
break;
}
case 26:
{
return tileC8.LeviChoose();
break;
}
case 27:
{
return tileC9.LeviChoose();
break;
}
default:
{
return 0;
}

}
}
else
{
switch(selection)
{
case 1:
{
return tile1.RyanChoose();
break;
}
case 2:
{
return tile2.RyanChoose();
break;
}
case 3:
{
return tile3.RyanChoose();
break;
}
case 4:
{
return tile4.RyanChoose();
break;
}
case 5:
{
return tile5.RyanChoose();
break;
}
case 6:
{
return tile6.RyanChoose();
break;
}
case 7:
{
return tile7.RyanChoose();
break;
}
case 8:
{
return tile8.RyanChoose();
break;
}
case 9:
{
return tile9.RyanChoose();
break;
}
case 10:
{
return tileB1.RyanChoose();
break;
}
case 11:
{
return tileB2.RyanChoose();
break;
}
case 12:
{
return tileB3.RyanChoose();
break;
}
case 13:
{
return tileB4.RyanChoose();
break;
}
case 14:
{
return tileB5.RyanChoose();
break;
}
case 15:
{
return tileB6.RyanChoose();
break;
}
case 16:
{
return tileB7.RyanChoose();
break;
}
case 17:
{
return tileB8.RyanChoose();
break;
}
case 18:
{
return tileB9.RyanChoose();
break;
}
case 19:
{
return tileC1.RyanChoose();
break;
}
case 20:
{
return tileC2.RyanChoose();
break;
}
case 21:
{
return tileC3.RyanChoose();
break;
}
case 22:
{
return tileC4.RyanChoose();
break;
}
case 23:
{
return tileC5.RyanChoose();
break;
}
case 24:
{
return tileC6.RyanChoose();
break;
}
case 25:
{
return tileC7.RyanChoose();
break;
}
case 26:
{
return tileC8.RyanChoose();
break;
}
case 27:
{
return tileC9.RyanChoose();
break;
}
default:
{
return 0;
}

}

}


}
bool Board3d::gameCheck(bool PlayerTurn)
{
int i = 0;
int endGame=0;
char empty=' ';
char player='X';
int LeviScore=0;
int RyanScore=0;
//BOARD A POSSIBILITIES
if (tile1.state==tile2.state&&tile1.state==tile3.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile1.state==tile4.state&&tile1.state==tile7.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile1.state==tile5.state&&tile1.state==tile9.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile2.state==tile5.state&&tile2.state==tile8.state&&tile2.state!=empty)
{
if(tile2.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile3.state==tile5.state&&tile3.state==tile7.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile3.state==tile6.state&&tile3.state==tile9.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile4.state==tile5.state&&tile4.state==tile6.state&&tile4.state!=empty)
{
if(tile4.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile7.state==tile8.state&&tile7.state==tile9.state&&tile7.state!=empty)
{
if(tile7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
//BOARD B POSSIBILITIES
if (tileB1.state==tileB2.state&&tileB1.state==tileB3.state&&tileB1.state!=empty)
{
if(tileB1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB1.state==tileB4.state&&tileB1.state==tileB7.state&&tileB1.state!=empty)
{
if(tileB1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB1.state==tileB5.state&&tileB1.state==tileB9.state&&tileB1.state!=empty)
{
if(tileB1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB2.state==tileB5.state&&tileB2.state==tileB8.state&&tileB2.state!=empty)
{
if(tileB2.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB3.state==tileB5.state&&tileB3.state==tileB7.state&&tileB3.state!=empty)
{
if(tileB3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tileB3.state==tileB6.state&&tileB3.state==tileB9.state&&tileB3.state!=empty)
{
if(tileB3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB4.state==tileB5.state&&tileB4.state==tileB6.state&&tileB4.state!=empty)
{
if(tileB4.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileB7.state==tileB8.state&&tileB7.state==tileB9.state&&tileB7.state!=empty)
{
if(tileB7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
//BOARD C POSSIBILITIES
if (tileC1.state==tileC2.state&&tileC1.state==tileC3.state&&tileC1.state!=empty)
{
if(tileC1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC1.state==tileC4.state&&tileC1.state==tileC7.state&&tileC1.state!=empty)
{
if(tileC1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC1.state==tileC5.state&&tileC1.state==tileC9.state&&tileC1.state!=empty)
{
if(tileC1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC2.state==tileC5.state&&tileC2.state==tileC8.state&&tileC2.state!=empty)
{
if(tileC2.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC3.state==tileC5.state&&tileC3.state==tileC7.state&&tileC3.state!=empty)
{
if(tileC3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tileC3.state==tileC6.state&&tileC3.state==tileC9.state&&tileC3.state!=empty)
{
if(tileC3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC4.state==tileC5.state&&tileC4.state==tileC6.state&&tileC4.state!=empty)
{
if(tileC4.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tileC7.state==tileC8.state&&tileC7.state==tileC9.state&&tileC7.state!=empty)
{
if(tileC7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
//MULTI BOARD POSSIBILITIES
if (tile1.state==tileB1.state&&tile1.state==tileC1.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile1.state==tileB2.state&&tile1.state==tileC3.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile1.state==tileB4.state&&tile1.state==tileC7.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile1.state==tileB5.state&&tile1.state==tileC9.state&&tile1.state!=empty)
{
if(tile1.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile2.state==tileB2.state&&tile2.state==tileC2.state&&tile2.state!=empty)
{
if(tile2.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile2.state==tileB5.state&&tile2.state==tileC8.state&&tile2.state!=empty)
{
if(tile2.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile3.state==tileB3.state&&tile3.state==tileC3.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile3.state==tileB2.state&&tile3.state==tileC1.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile3.state==tileB6.state&&tile3.state==tileC9.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile3.state==tileB5.state&&tile3.state==tileC7.state&&tile3.state!=empty)
{
if(tile3.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile4.state==tileB4.state&&tile4.state==tileC4.state&&tile4.state!=empty)
{
if(tile4.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile4.state==tileB5.state&&tile4.state==tileC6.state&&tile4.state!=empty)
{
if(tile4.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile5.state==tileB5.state&&tile5.state==tileC5.state&&tile5.state!=empty)
{
if(tile5.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile6.state==tileB6.state&&tile6.state==tileC6.state&&tile6.state!=empty)
{
if(tile6.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile6.state==tileB5.state&&tile6.state==tileC4.state&&tile6.state!=empty)
{
if(tile6.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
};

}
if (tile7.state==tileB7.state&&tile7.state==tileC7.state&&tile7.state!=empty)
{
if(tile7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile7.state==tileB4.state&&tile7.state==tileC1.state&&tile7.state!=empty)
{
if(tile7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile7.state==tileB8.state&&tile7.state==tileC9.state&&tile7.state!=empty)
{
if(tile7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile7.state==tileB5.state&&tile7.state==tileC3.state&&tile7.state!=empty)
{
if(tile7.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile8.state==tileB8.state&&tile8.state==tileC8.state&&tile8.state!=empty)
{
if(tile8.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile8.state==tileB5.state&&tile8.state==tileC2.state&&tile8.state!=empty)
{
if(tile8.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile9.state==tileB9.state&&tile9.state==tileC9.state&&tile9.state!=empty)
{
if(tile9.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile9.state==tileB6.state&&tile9.state==tileC3.state&&tile9.state!=empty)
{
if(tile9.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile9.state==tileB8.state&&tile9.state==tileC7.state&&tile9.state!=empty)
{
if(tile9.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
if (tile9.state==tileB5.state&&tile9.state==tileC1.state&&tile9.state!=empty)
{
if(tile9.state==player)
{
LeviScore++;
}
else
{
RyanScore++;
}

}
//GAME OVER
if (tile1.state!=empty&&tile2.state!=empty&&tile3.state!=empty&&tile4.state!=empty&&tile5.state!=empty&&tile6.state!=empty&&tile7.state!=empty&&tile8.state!=empty&&tile9.state!=empty&&tileB1.state!=empty&&tileB2.state!=empty&&tileB3.state!=empty&&tileB4.state!=empty&&tileB5.state!=empty&&tileB6.state!=empty&&tileB7.state!=empty&&tileB8.state!=empty&&tileB9.state!=empty&&tileC1.state!=empty&&tileC2.state!=empty&&tileC3.state!=empty&&tileC4.state!=empty&&tileC5.state!=empty&&tileC6.state!=empty&&tileC7.state!=empty&&tileC8.state!=empty&&tileC9.state!=empty)
{
endGame=1;
}
else
{
endGame=0;
}

if (endGame==1)
{
cout<<endl<<"GAME OVER";
cout<<endl<<"Levi's Score: "<<LeviScore<<endl<<"Ryan's Score: "<<RyanScore;
levinum = levinum + LeviScore;
ryannum = ryannum + RyanScore;

if(LeviScore>RyanScore)
{
cout<<endl<<"Levi Wins!";
return 1;
}
else if(RyanScore>LeviScore)
{
cout<<endl<<"Ryan Wins!";
return 1;
}
else if(LeviScore==RyanScore)
{
cout<<endl<<"Levi and Ryan Tied!";
return 1;



}

}
else
{
return 0;
}
}
