/* Levi Hazelwood
The purpose of this project is to create a game of 3D tic tac toe vs a CPU */ 

#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<time.h>
using namespace std;

class Player
{
	public:
	
	char choice;
	char move;
	char playshape;
	
	
};

class DECIDE
{
	public: 
	
	char spot[28] = "123456789123456789123456789";
	
	
	int checkwin() 
	{
		int index; 
		int win;
		int counter;
		
		for (index=0; index < 25; index+=3)
		{
			if(spot[index]==spot[index+1] && spot[index+1]==spot[index+2])
			{
				return win = 1;
			}
		}
		for (index=0; index < 9; index++)
		{
			if(spot[index]==spot[index+3] && spot[index+3]==spot[index+6])
			{
				return win = 1;
			}
		}
		for (index = 0; index < 9; index++)
		{																						
			if (spot[index]==spot[index+9] && spot[index+9]==spot[index+18] && (spot[index] == 'x' || spot[index] == 'o') && (spot[index+9] == 'x' || spot[index+9] == 'o') && (spot[index+18] == 'x' || spot[index+18] == 'o'))
			{
				return win = 1;
			}
		}
		if (spot[0]==spot[4] && spot[4]== spot[8])
		{
			return win = 1;
		}
		else if (spot[2]==spot[4] && spot[4]== spot[6])
		{
			return win = 1;
		}
		else if (spot[9]==spot[13] && spot[13]== spot[17])
		{
			return win = 1;
		}
		else if (spot[11]==spot[13] && spot[13]== spot[15])
		{
			return win = 1;
		}
		else if (spot[18]==spot[22] && spot[22]== spot[26])
		{
			return win = 1;
		}
		else if (spot[20]==spot[22] && spot[22]== spot[24])
		{
			return win = 1;
		}
		for (index= 0; index < 27; index++ )
		{
			if (spot[index] == 'x' || spot[index] == 'o')
			{
				counter += 1;
				
				if(counter == 27)
				{
					return win = 2;
				}
			}
		}
		if(win != 1 || win != 2)
		{
			return win = -1;
		}
	}	
	
	void Board()
	{
		cout << "\t\t__" << spot[0] << "__|__" << spot[1] << "__|__" << spot[2] <<"__\n\t\t__" << spot[3] << "__|__" << spot[4] << "__|__" << spot[5] << "__\n\t\t  " << spot[6] << "  |  " <<  spot[7] << "  |  " <<  spot[8] << "  \n " << endl;
		cout << "\t\t		__" << spot[9] << "__|__" << spot[10] << "__|__" << spot[11] <<"__\n\t\t		__" << spot[12] << "__|__" << spot[13] << "__|__" << spot[14] << "__\n\t\t		  " << spot[15] << "  |  " <<  spot[16] << "  |  " <<  spot[17] << "  \n " << endl;
		cout << "\t\t				__" << spot[18] << "__|__" << spot[19] << "__|__" << spot[20] <<"__\n\t\t				__" << spot[21] << "__|__" << spot[22] << "__|__" << spot[23] << "__\n\t\t				  " << spot[24] << "  |  " <<  spot[25] << "  |  " <<  spot[26] << "  \n " << endl;
	}
};

int main()
{
	Player P1;
	Player CP;
	
	DECIDE decide;
	
	srand(time(NULL));
	int radnum = rand()%27+1;
	int i;
	int j;
	int choice; 
	int Pchoice;
	int Pboard;
	int win = -1;
	int radstart = rand()%2;
	cout << radstart,'\n';
	
	cout << "Welcome to 3D Tic Tac Toe, below are three boards. Each number corresponds to a designated position. You may also win by getting any row or column in the z axis." << endl;
	cout << "Each board is given a dedicated number 1-3 the board below shows the indicated number needed to access each board.";
	cout << "The starting player is random, prepare for the match...\n" << endl;
	cout << "(1)\t\t__1__|__2__|__3__\n\t\t__4__|__5__|__6__\n\t\t  7  |  8  |  9  \n " << endl;
	cout << "(2)\t\t		__1__|__2__|__3__\n\t\t		__4__|__5__|__6__\n\t\t		  7  |  8  |  9  \n " << endl;
	cout << "(3)\t\t				__1__|__2__|__3__\n\t\t				__4__|__5__|__6__\n\t\t				  7  |  8  |  9  \n " << endl;
	

	while(win == -1)
	{
		while (radstart == 1)
		{
			cout << "\n" << "Please choose a placement: ";
			cin >> Pchoice;

			cout << "\n" << "Please choose a board: ";
			cin >> Pboard;
			
			P1.choice = Pchoice + ((Pboard-1)*9);
			
			
			if (P1.choice > 0 && P1.choice <= 27)
			{
				P1.playshape = 'x';
				P1.move = P1.playshape; 
				decide.spot[P1.choice-1] = P1.move; 
			}
			else
			{
				while (decide.spot[P1.choice-1] == 'x' || decide.spot[P1.choice-1] == 'o')
				{
					cout << "\n" << "Please choose a placement: ";
					cin >> Pchoice;
					cout << "\n" << "Please choose a board: ";
					cin >> Pboard;
					P1.choice = Pchoice + ((Pboard-1)*9);
					P1.playshape = 'x';
					P1.move = P1.playshape; 
					decide.spot[P1.choice-1] = P1.move; 
					
					
				}
			}
			
			decide.Board();
			win = decide.checkwin();
			if (win == 1)
			{
				cout << "\nPlayer Winner!";
				radstart = 9;
			}
			else if (win == 2)
			{
				cout << "\nTie!";
				radstart = 9;
			}
			else if(win == -1)
			{
				radstart = 0;
			}
		
			
			
		
		}

		while (radstart == 0)
		{
			cout << "\nCPU Play\n";
			CP.choice = radnum;
				
			while(decide.spot[CP.choice-1] == 'x' || decide.spot[CP.choice-1] == 'o')
			{
				radnum = rand()%27+1;
				CP.choice = radnum;
			}
			
			CP.playshape = 'o';
			CP.move = CP.playshape; 
			decide.spot[CP.choice-1] = CP.move;
			
			decide.Board();
			win = decide.checkwin();
			if (win == 1)
			{
				cout << "\nCPU Winner!";
				radstart = 9;
			}
			else if (win == 2)
			{
				cout << "\nTie!";
				radstart = 9;
			}
			else if(win == -1)
			{
				radstart = 1;
			}
		}
		if (radstart == 9)
			return 0;
	}
return 0;
}

