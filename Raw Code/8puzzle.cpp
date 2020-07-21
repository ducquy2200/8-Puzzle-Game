/********************************************************************
 File: 8puzzle.cpp
 Purpose: This program creates a 3x3 board of boxes with numbers that will be moved around by the user until they are in numerical order.
 Name: Quy Duc Do
 Inputs: start, option
 Outputs: box[][], counter
 Functions:
 
	randomgen () - Randomly generate numbers in the array for the board.
        
	blankspace() - Indentify the position of the empty box (0)
 
	puzzle() - Print out the game board
 
	winpuzzle() - Print out the winning game board (arranged order)
	
	errormove() - Check to ensure the exchanged box is not out of bound of the array/board
 
	up () - Exchange the value of the empty box (0) with the one above it. Makes it appear if the blank moved upwards and update the board.
 
	down () - Exchange the value of the empty box (0) with the one below it. Makes it appear if the blank moved downwards and update the board.
 
	left () - Exchange the value of the empty box (0) with the one to the left of it. Makes it appear if the blank moved leftwards and update the board.
 
	right () - Exchange the value of the empty box (0) with the one to the right it. Makes it appear if the blank moved rightwards and update the board.
 
	falsemove() - Display the message of wrong command if a move other than up, down, left, and right (1 to 4) is chosen.
	
	winner() - Checker to see if the player has complepte the game or not.
	
 ********************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
//---------------------------------
int row, column, bridge;
int option;
int box[3][3];
int counter=0;
int x=0;
int changerow, changecolumn;
bool win;
string start;
//-------------------------------
void randomgen()
{
	srand (time(NULL));//generate new numbers everytime the program is used
	const int size1 =9;
    int sub1[size1];// contains the set of unique values

    for(int a=0; a<size1; a++)
        sub1[a] = a;//1 2 3 4...

    const int size2 = 9;
    int sub2[size2];// result storage

    // When a value is selected, remove it from the pool of values being selected from
    // swap size2 randomly selected elements from "left end" of sub1 to the "right end" of sub1
    // left/right split is at sub1[Split]
    int split = size1 - 1;

    for(int b=0; b<size2; b++)
    {
        int randnum = rand()%(1 + split);// random index into "left portion" of sub1
        int temp = sub1[randnum];// swap values
        sub1[randnum] = sub1[split];
        sub1[split] = temp;
        --split;

        // catch the unique value just swapped (or copy from sub1[split+1] to sub1[size1-1] later)
        sub2[b] = temp;
    }

	int c=0;
	for (int d=0; d<3; d++)
	{
		for (int e=0; e<3; e++)
		{
			box[d][e]=sub2[c];
			c++;
		}
	} //save values in the two dimentional array to print the board on the screen
}
//---------------------------------
void blankspace()
{
	for (int a=0; a<3; a++)
	{
		for (int b=0; b<3; b++)
		{
			if (box[a][b]==0)
			{
				row=a;
				column=b;
			}
		}
	}
}
//--------------------------------
void puzzle()
{
	cout <<"\t\t\t\t"<<setfill('-')<<setw(13)<<'-'<<setfill(' ')<<endl;
	cout <<"\t\t\t\t"<<"| "<<box[0][0]<<" | "<<box[0][1]<<" | "<<box[0][2]<<" | "<<endl;
	cout <<"\t\t\t\t"<<setfill('-')<<setw(13)<<'-'<<setfill(' ')<<endl;
	cout <<"\t\t\t\t"<<"| "<<box[1][0]<<" | "<<box[1][1]<<" | "<<box[1][2]<<" | "<<endl;
	cout <<"\t\t\t\t"<<setfill('-')<<setw(13)<<'-'<<setfill(' ')<<endl;
	cout <<"\t\t\t\t"<<"| "<<box[2][0]<<" | "<<box[2][1]<<" | "<<box[2][2]<<" | "<<endl;
	cout <<"\t\t\t\t"<<setfill('-')<<setw(13)<<'-'<<setfill(' ')<<endl;
}
//--------------------------------
void winpuzzle()
{
	cout <<'\t'<<'|'<<"\t\t\t"<<setfill('-')<<setw(13)<<'-'<<right<<setfill(' ')<<setw(27)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<"| "<<1<<" | "<<2<<" | "<<3<<" | "<<right<<setfill(' ')<<setw(26)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<setfill('-')<<setw(13)<<'-'<<right<<setfill(' ')<<setw(27)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<"| "<<4<<" | "<<5<<" | "<<6<<" | "<<right<<setfill(' ')<<setw(26)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<setfill('-')<<setw(13)<<'-'<<right<<setfill(' ')<<setw(27)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<"| "<<7<<" | "<<8<<" | "<<0<<" | "<<right<<setfill(' ')<<setw(26)<<'|'<<endl;
	cout <<'\t'<<'|'<<"\t\t\t"<<setfill('-')<<setw(13)<<'-'<<right<<setfill(' ')<<setw(27)<<'|'<<endl;
}
//-------------------------------
void errormove()
{
	if (changerow==-1)
	{
		changerow=0;
		cout <<"\t\t\t"<<"Wrong move! Please choose again!"<<endl;
		counter--;
	}
	if (changerow==3)
	{
		changerow=2;
		cout <<"\t\t\t"<<"Wrong move! Please choose again!"<<endl;
		counter--;
	}
	if (changecolumn==-1)
	{
		changecolumn=0;
		cout <<"\t\t\t"<<"Wrong move! Please choose again!"<<endl;
		counter--;
	}
	if (changecolumn==3)
	{
		changecolumn=2;
		cout <<"\t\t\t"<<"Wrong move! Please choose again!"<<endl;
		counter--;
	}
}
//-------------------------------
void up()
{
	system ("cls");
	blankspace();
	changerow = row+1;
	errormove();
	bridge=box[row][column];
	box[row][column]=box[changerow][column];
	box[changerow][column]=bridge;
	puzzle();
}
//-------------------------------
void down()
{
	system ("cls");
	blankspace();
	changerow = row-1;
	errormove();
	bridge=box[row][column];
	box[row][column]=box[changerow][column];
	box[changerow][column]=bridge;
	puzzle();
}
//-------------------------------
void right()
{
	system ("cls");
	blankspace();
	changecolumn=column-1;
	errormove();
	bridge=box[row][column];
	box[row][column]=box[row][changecolumn];
	box[row][changecolumn]=bridge;
	puzzle();
}
//-------------------------------
void left()
{
	system ("cls");
	blankspace();
	changecolumn=column+1;
	errormove();
	bridge=box[row][column];
	box[row][column]=box[row][changecolumn];
	box[row][changecolumn]=bridge;
	puzzle();
}
//-------------------------------
void falsemove()
{
	system ("cls");
	cout <<"\t\t\t"<<"Wrong command! Please choose again!"<<endl;
	puzzle();
	counter--;
}
//-------------------------------
void winner()
{
	if ((box[0][0]==1)&&(box[0][1]==2)&&(box[0][2]==3)&&(box[1][0]==4)&&(box[1][1]==5)&&(box[1][2]==6)&&(box[2][0]==7)&&(box[2][1]==8)&&(box[2][2]==0))
	{
		win == true;
	}
	else
	{
		win == false;
	}
}
//-------------------------------
int main ()
{
	cout <<setfill('-')<<setw(80)<<'-'<<endl;
	cout <<'\n';
	cout <<setfill(' ')<<setw(22)<<' '<<left<<setfill('-')<<setw(33)<<'o'<<setw(1)<<'o'<<endl;
	cout <<right<<setfill(' ')<<setw(56)<<"| WELCOME TO THE 8 PUZZLE SOLVER |"<<endl;
	cout <<setfill(' ')<<setw(22)<<' '<<left<<setfill('-')<<setw(33)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\n';
	cout <<'\t'<<left<<setfill('-')<<setw(63)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\t'<<left<<setfill(' ')<<setw(26)<<'|'<<setw(12)<<"INSTRUCTION"<<right<<setw(26)<<'|'<<endl;
	cout <<'\t'<<left<<setfill('-')<<setw(63)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\t'<<"| This game will generate a block puzzle based on your choise  |"<<endl;
	cout <<'\t'<<left<<setfill('-')<<setw(63)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\t'<<"| Move the blocks up, down, left, or right into the blank space|"<<endl;
	cout <<'\t'<<left<<setfill('-')<<setw(63)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\t'<<"| You can only win the game by solving the puzzle so that it   |"<<endl;
	cout <<'\t'<<"| will look exactly like the puzzle below                      |"<<endl;
	cout <<'\t'<<'|'<<right<<setfill(' ')<<setw(63)<<'|'<<endl;
	winpuzzle();
	randomgen();
	cout <<'\t'<<'|'<<right<<setfill(' ')<<setw(63)<<'|'<<endl;
	cout <<'\t'<<"|THANKS FOR PLAYING THIS GAME! DO YOUR BEST SOLVING THE PUZZLE!|"<<endl;
	cout <<'\t'<<left<<setfill('-')<<setw(63)<<'o'<<setw(1)<<'o'<<endl;
	cout <<'\n';
	cout <<setfill('-')<<setw(80)<<'-'<<endl;
	cout <<'\n';
	cout <<right<<setfill(' ')<<setw(48)<<"PRESS ENTER TO START";
	getline(cin,start,'\n');
	system ("cls");

	puzzle();
	cout <<"\t\t\t\t"<<"Moves made: "<<counter<<endl;
	cout <<"\n\n";

	while (1)
	{
		cout <<setfill(' ')<<setw(11)<<' '<<"Make your move (1 is up/2 is down/3 is right/4 is left): ";
		cin >>option;
		cout <<'\n';

		switch (option)
		{
		case 1:
			up();
			break;
		case 2:
			down();
			break;
		case 3:
			right();
			break;
		case 4:
			left();
			break;
		default:
			falsemove();
			break;
		}
		counter++;
		cout <<"\t\t\t\t"<<"Moves made: "<<counter<<endl;
		cout <<"\n\n";

		winner();
		if (win==true)
		{
			break;
			cout <<"\t\t\t"<<"Congratulation! You win the game!"<<endl;
			cout <<"\t\t\t\t"<<"Total moves: "<<counter<<endl;
		}
	}

	system ("pause");
	return 0;
}


