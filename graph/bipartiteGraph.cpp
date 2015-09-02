#include <iostream>
#include <vector>
#include "myGraph.h"


/*
 * Edmonds's matching
 * Input: graph, adjacent matrix.
 * Output: max match number.
 * Time complexity: O(n ^ E).
 */

int graph[N][N];
int matchX[N], matchY[N];
int visitedY[N];
int nx, ny;

bool findAug(int x);

int maxMatch(vector< vector<int> > graph)
{
	for(int i = 0;i < nx;i++)
		matchX[i] = -1;
	for(int i = 0;i < ny;i++)
		matchY[i] = -1;

    int res = 0;
    for(int i = 0;i < nx;i++)
    {
    	memset(visitedY, 0, sizeof(visitedY));
        if(findAug(i))
        	res++;
    }

    return res;
}

// use DFS to find augment path, capable for dense graph.
// ! BFS is capable for sparse graph.
bool findAug(int x)
{
    for(int i = 0;i < ny;i++)
        if (graph[x][i] && !visitedY[i])
        {
        	visitedY[i] = 1;
        	if (matchY[i] == -1 || findAug(matchY[i]))
        	{
                matchX[x] = i;
                matchY[i] = x;
                return true;
            }
        }
    return false;
}
