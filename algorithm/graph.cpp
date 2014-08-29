/*
 * graph.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */

#include "myAlgorithm.h"

/*
 * Input: graph, a adjacent matrix.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n^2).
 */
static int minSpanTree_prime(vector<vector<int> > &graph, vector<int> &tree)
{
	assert(graph.size() == graph[0].size());
	int nodeNum = graph.size();

	vector<int> flag(nodeNum);
	vector<bool> cost(nodeNum);

	priority_queue<int,

	int startNode = 0;
	while(1)
	{
		for()

		for (i = 1; i < n; i++)
		{
			min = 1000000;
			v = 0;
			for (j = 0; j < n; j++)
		{
			if (!flag[j] && closet[j] < min)
			{
				v = j;
				min = closet[j];
			}
		}
		if (v)
		{
			tree[i] = v;
			flag[v] = 1;
			for (j = 0; j < n; j++)
				if (!flag[j] && graph[v][j] < closet[j])
					closet[j] = graph[v][j];
		}
	}
}

/*
 * Description: Gijkstra single source shortest path.
 * Input: 1. n: graph node number,
 *        2. path[]: shortest path
 * Output: path[]
 * Note: Time complexity: O(n^2), v is souce node.
 */
#define NMAX 100000
static void dijkstra(int n, int path[])
{
	int dis[NMAX], used[NMAX];
	int i, j, v, u, ldis;
	v = 0;
	for (i = 0; i < n; i++)
	{
		path[i] = -1;
		dis[i] = MAX;
		used[i] = 0;
	}
	dis[v] = 0;
	used[v] = 1;
	u = v;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (graph[u][j] != -1 && used[j] != 1 && dis[u] + graph[u][j] < dis[j])//最优子序列，这里可以变形)
			{
				dis[j] = dis[u] + graph[u][j];
				path[j] = u;
			}
		ldis = MAX;
		for (j = 0; j < n; j++)
			if (dis[j] < ldis && used[j] == 0)//&&dis[j]>0)
			{
				ldis = dis[j];
				u = j;
			}
		used[u] = 1;
	}
}

/**********************************************
 * Description: Floyd find all shortest path between any two nodes.
 *  Input: 1. n: graph node number,
 *         2. A[][]: shortest path value.
 *         3. path[][]: shortest path.
 * Output: path[][], A[][]
 * Note: Time complexity: O(n^3).
 **********************************************/
#define MAX 100
int path[MAX][MAX], A[MAX][MAX];
void floyd(int n)
{
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			A[i][j] = graph[i][j];
			if (i != j && A[i][j] != -1)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			if (i != k)
				for (j = 0; j < n; j++)
					if (j != k && j != i && A[i][k] != -1 && A[k][j] != -1 && A[i][k] + A[k][j] < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						path[i][j] = path[k][j];
					}
}
