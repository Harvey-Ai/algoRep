#include <iostream>
#include <vector>
#include "myGraph.h"

namespace maxMatchNS
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
            matchY[i] = -1;
    }
}

vector<int> yUsed;
// find augment path
int path(int xNode)
{
    for(int i = 0;i < maxMatchNS::ny;i++)
    {
        if (maxMatchNS::biGraph[xNode][i] && !yUsed[i])
        {
            yUsed[i] = 1;

            if (maxMatchNS::matchY[i] == -1 || path(maxMatchNS::matchY[i]))
            {
                maxMatchNS::matchX[xNode] = i;
                maxMatchNS::matchY[i] = xNode;
                return 1;
            }
        }
    }
    return 0;
}


/*
 * Edmonds's matching
 * Input: graph, adjacent matrix.
 * Output: max match number.
 * Time complexity: O(n ^ E).
 */
int maxMatch(vector< vector<int> > graph)
{
    maxMatchNS::initialize(graph);
    yUsed.resize(maxMatchNS::ny);

    int res = 0;
    for(int i = 0;i < maxMatchNS::nx;i++)
    {
        for(int j = 0;j < maxMatchNS::ny;j++)
            yUsed[j] = 0;
        res += path(i);
    }

    return res;
}
