/*
 * bipartiteGraph.cpp
 * 	Created on: Aug 29, 2014
 * 	Author: ufo008ahw
*/

#include "myAlgorithm.h"

namespace maxMatch
{
	int nx, ny;
	vector<int> matchX, matchY;
	vector< vector<int> > biGraph;

	void initialize(vector< vector<int> > graph)
	{
		nx = graph.size();
		ny = graph[0].size();
		matchX.resize(nx);
		matchY.resize(ny);
		biGraph = graph;

		for(int i = 0;i < nx;i++)
			matchX[i] = -1;
		for(int i = 0;i < ny;i++)
			matchY[i] == -1;
	}
}

vector<int> yUsed;
// find augment path
int path(int xNode)
{
	for(int i = 0;i < maxMatch::ny;i++)
	{
		if (graph[xNode][i] && !yUsed[i])
		{
			yUsed[i] = 1;

			if (matchY[i] == -1 || path(matchY[i]))
			{
				matchX[xNode] = i;
				matchY[i] = xNode;
				return 1;
			}
		}
	}
}

int maxMatch(vector< vector<int> > graph);
{
	maxMatch::initialize(graph);
	yUsed.reisze(maxMatch::ny);

	int res = 0;
	for(int i = 0;i < nx;i++)
	{
		for(int j = 0;j < ny;j++)
			yUsed[j] = 0
		res += path(i);
	}

	return res;
}
