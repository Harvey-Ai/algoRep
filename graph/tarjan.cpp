/*
 * tarjan.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: ufo008ahw
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> visit;
vector< vector<int> > graph;
stack<int> tarjanSt;
vector<int> inStack;
vector<int> dnf, low;
vector< vector<int> > res;
int dfsTime;

void dfs(int nodeI, int num)
{
	if (visit[nodeI])
		return;

	dnf[nodeI] = dfsTime++;
	low[nodeI] = dnf[nodeI];
	tarjanSt.push_back(nodeI);
	inStack[nodeI] = tarjanSt.size() - 1;

	for(int i = 0;i < num;i++)
		if (graph[nodeI][i])
		{
			if (!visit[i])
				dfs(i, num);

			low[nodeI] = low[i] < low[nodeI] ? low[i] : low[nodeI];
		}
	if (low[nodeI] == dnf[nodeI])
	{
		vector<int> newRes;
		while(tarjanSt.size() > inStack[nodeI])
		{
			newRes.push_back(tarjanSt.top());
			tarjanSt.pop();
		}
		res.push_back(newRes);
		inStack[nodeI] = -1;
	}
}

void tarjan(vector< vector<int> > &matrix)
{
	assert(matrix.size() == matrix[0].size());

	int num = matrix.size();

	graph.reisze(num);
	for(int i = 0;i < num;i++)
	{
		graph[i].resize(num);
		for(int j = 0;j < num;j++)
			graph[i][j] = matrix[i][j];
	}

	visit.resize(num);
	for(int i = 0;i < num;i++)
		visit[i] = 0;

	inStack.resize(num);
	for(int i = 0;i < num;i++)
		inStack[i] = -1;
	dnf.resize(num);
	low.resize(num);
	for(int i = 0;i < num;i++)
		if (!visit[i])
			dfs(i);

	return res;
}
