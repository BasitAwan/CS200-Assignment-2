#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "mine.h"

using namespace std;

int randomnum();



int main()
{
	mine_index a;
	a.col = 1;
	a.row = 1;
	mine_index b;
	b.col = 3;
	b.row = 3;
	Miner jack;
	jack.up=1;
	jack.down=1;
	jack.left=1;
	jack.right=1;
	Mine lel;
	lel.printmine();
	lel.can_solve(jack, jack, a, a, b);
}



int randomnum()
{
	
	int rnumber = (rand()%2);
	return rnumber;
}

Mine::Mine()
{
	srand(time(0));
	size =5;
	maze= new bool *[5];
	for (int i = 0; i < 5; ++i)
	{
		maze[i]= new bool[5];
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			maze[i][j] = randomnum();
		}
	}

}
Mine::Mine(int x)
{
	srand(time(0));
	size = x;
	maze= new bool *[size];
	for (int i = 0; i < size; ++i)
	{
		maze[i]= new bool[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			maze[i][j] = randomnum();
		}
	}

}
Mine::Mine(bool **input , int x)
{
	size = x;
	maze= new bool *[5];
	for (int i = 0; i < size; ++i)
	{
		maze[i]= new bool[5];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			maze[i][j] = input[i][j];
		}
	}

}

void Mine::printmine()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

int Mine::can_solve(struct Miner &a ,struct Miner b,struct mine_index &lo, struct mine_index start, struct mine_index y)
{
	
	if(lo.row-1== y.row-1 &&lo.col-1==y.col-1)
	{
		cout << "The Mine can be explored by the miner"<< endl;
		return 1;
	}

	if(lo.row-1<size-1 && a.down==1 && b.down==1)//for down
	{
		if (maze[lo.row][lo.col-1]==1)
		{
			lo.row= lo.row +1;
			a.up=0;
			a.left=1;
			a.right=1;
			if (can_solve(a,b,lo,start,y))
			{
				return 1;
			}
			lo.row=lo.row-1;
			a.up=1;
		}
	}
	
	
	if(lo.row-1>0 && a.up==1 && b.up==1)//for down
	{

		if (maze[lo.row-2][lo.col-1]==1)
		{
			lo.row=lo.row-1;
			a.down=0;
			a.left=1;
			a.right=1;
			if (can_solve(a,b,lo,start,y))
			{
				return 1;
			}
			lo.row= lo.row +1;
			a.down=1;
		}
	}
	if(lo.col-1<size-1 && a.right==1 && b.right==1)//for down
	{
		if (maze[lo.row-1][lo.col]==1)
		{ 

			lo.col= lo.col +1;
			a.left=0;
			a.up=1;
			a.down=1;
			if (can_solve(a,b,lo,start,y))
			{
				return 1;
			}
			lo.col= lo.col -1;
			a.left=1;
	
		}
	}
	if(lo.col-1>0 && a.left==1 && b.left==1)//for down
	{
		if (maze[lo.row-1][lo.col-2]==1)
		{
			lo.col= lo.col -1;
			a.right=0;
			a.down=1;
			a.up=1;
			if (can_solve(a,b,lo,start,y))
			{
				return 1;
			}
			lo.col= lo.col +1;
			a.right=1;
		}
	}

	if(lo.col==start.col&& lo.row==start.row)
		{
			cout << "The mine can not be explored by the miner" << endl;
		}
	return 0;

}



