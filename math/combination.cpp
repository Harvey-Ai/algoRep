/* combination
 	 Created on: Oct 15, 2014
     Author: ufo008ahw
*/

#include "number.h"
#include <iostream>
using namespace std;

int Stirling1(int n, int m)
{
	int arr[n][m];
	for(int i = 0;i <= m;i++)
		arr[0][i] = 0;
	arr[0][0] = 1;

	for(int i = 1;i <= n;i++)
	{
		arr[i][0] = 0;
		for(int j = 1;j <= m;j++)
			arr[i][j] = (i - 1) * arr[i - 1][j] + arr[i - 1][j - 1];
	}
	return arr[n][m];
}

int Stirling2(int n, int m)
{
	int arr[n][m];
	for(int i = 0;i <= m;i++)
		arr[0][i] = 0;
	arr[0][0] = 1;

	for(int i = 1;i <= n;i++)
	{
		arr[i][0] = 0;
		for(int j = 1;j <= m;j++)
			arr[i][j] = j * arr[i - 1][j] + arr[i - 1][j - 1];
	}
	return arr[n][m];
}

int Catalan(int n)
{
	if (n == 0)	return 0;
	if (n == 1)	return 1;

	int h[n];
	h[0] = 0, h[1] = 1;

	for(int i = 2;i <= n;i++)
	{
		h[i] = 0;
		for(int j = 0;j < n;j++)
			h[i] += h[j] * h[i - j - 1];
	}
	return h[n];
}


int divide(int n, int m)
{
	int arr[n][m];
	for(int i = 1;i <= m;i++)
		arr[0][i] = 0;
	arr[0][0] = 1;

	for(int i = 1;i <= n;i++)
	{
		arr[i][0] = 0;
		for(Int j = 1;j <= m;j++)
		{
			if (j >= i)
				arr[i][j] = arr[i][j - i] + arr[i][j - 1];
			else
				arr[i][j] = arr[i][j - 1];
		}
	}
	return arr[n][m];
}
