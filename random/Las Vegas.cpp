/*
 * Las Vegas.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: ufo008ahw
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
using namespace std;

int hUsed[8], vUsed[8];
int queenPos[8][2];
int queenNum;
int ok = 0;

bool check(int h, int v)
{
	if (hUsed[h] || vUsed[v])
		return 0;

	for(int i = 0;i < queenNum;i++)
	{
		if (abs(h - queenPos[i][0]) == abs(v - queenPos[i][1]))
			return 0;
	}
	return true;
}

void dfs(int h)
{
	if (h == 8)
	{
		ok = 1;
		return;
	}
	if (ok)
		return;

	if (hUsed[h])
		dfs(h + 1);
	else
	{
		for(int i = 0;i < 8;i++)
			if (check(h, i))
			{
				queenPos[queenNum][0] = h;
				queenPos[queenNum][1] = i;
				hUsed[h] = true;
				vUsed[i] = true;
				queenNum++;
				dfs(h + 1);
				if (ok)
					return;
				hUsed[h] = false;
				vUsed[i] = false;
				queenNum--;
			}
	}
}


void eightQueen(int preNum)
{
	assert(preNum <= 8);

	memset(hUsed, 0, sizeof(hUsed));
	memset(vUsed, 0, sizeof(vUsed));
	ok = 0;
	queenNum = 0;

	time_t seed = time(&seed);
	srand((int)seed);
	// first random put some queen
	for(int i = 0;i < preNum;i++)
	{
		int a = rand() % 8;
		int b = rand() % 8;

		if (check(a, b))
		{
			queenPos[queenNum][0] = a;
			queenPos[queenNum++][1] = b;
			hUsed[a] = 1;
			vUsed[b] = 1;
		}
		else
			i--;
	}

	dfs(0);
}

int lasVegas()
{
	const int preNum = 3;
	eightQueen(preNum);

	cout << endl;
	cout << "----------- Las Vegas test -----------" << endl;
	if (queenNum == 8)
	{
		cout << "Sucess to get an answer: ";
		for(int i = 0;i < 8;i ++)
			cout << "(" << queenPos[i][0] << " " << queenPos[i][1] << "), ";
		cout << "YES" << endl;
	}
	else
		cout << "Fail to generate an answer, YES" << endl;

	return 0;
}
