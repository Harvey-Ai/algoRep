/*
 * graph.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: ufo008ahw
 */

#include <iostream>
#include <queue>
#include <vector>
#include "myGraph.h"
using namespace std;

/* MST
 * Input: graph, adjacent matrix.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n * n).
 */
template<class T>
T minSpanTree_prime(vector<vector<T> > &graph, vector<int> &tree)
{
	assert(graph.size() == graph[0].size());

	int nodeNum = graph.size();
	tree.resize(nodeNum);

	vector<int> flag(nodeNum, 0);
	flag[0] = 1;
	vector<T> cost(nodeNum, 0);
	for(int i = 0;i < nodeNum;i++)
		cost[i] = graph[0][i];

	tree[0] = -1;
	T costSum = 0;
	for(int i = 1;i < nodeNum;i++)
	{
		int index = -1;
		T minCost = -1;

		for(int j = 0;j < nodeNum;j++)
			if (!flag[j] && cost[j] >= 0 && (cost[j] < minCost || minCost < 0))
			{
				index = j;
				minCost = cost[j];
			}

		if (index == -1)
			return -1;

		costSum += minCost;
		flag[index] = 1;

		for(int j = 0;j < nodeNum;j++)
			if (!flag[j] && (cost[j] > graph[index][j] || cost[j] < 0))
			{
				tree[j] = index;
				cost[j] = graph[index][j];
			}
	}
	return costSum;
}


/* MST_2
 * Input: graph: adjacent List, costList: adjacent List.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n * logE).
 */
template <class T>
struct mstNodeType
{
	T cost;
	int index, preIndex;
	mstNodeType(int ind, int preInd, T c)
	{
		cost = c;
		index = ind;
		preIndex = preInd;
	}

	bool operator()(mstNodeType &otherNode)
	{
		return cost < otherNode.cost;
	}
};

template<class T>
T minSpanTree_prime(vector<vector<int> > &graph, vector<vector<T> > &costList, vector<int> &tree)
{
	int nodeNum = graph.size();
	tree.resize(nodeNum);

	vector<int> flag(nodeNum, 0);
	flag[0] = 1;

	priority_queue< mstNodeType<T>, vector<mstNodeType<T> >, mstNodeType<T> > minCostQ;

	tree[0] = -1;
	T costSum = 0;
	for(int i = 1;i < graph[0].size();i++)
		minCostQ.push(mstNodeType<T>(graph[0][i], 0, costList[0][i]));

	for(int i = 1;i < nodeNum;i++)
	{
		mstNodeType<T> minCostNode = minCostQ.top();
		minCostQ.pop();

		while(!minCostQ.empty() && flag[minCostNode.index])
		{
			minCostNode = minCostQ.top();
			minCostQ.pop();
		}

		int minIndex = minCostNode.index;
		if (flag[minIndex])
			return -1;

		costSum += minCostNode.cost;
		flag[minIndex] = 1;
		tree[minIndex] = minCostNode.preIndex;

		for(int j = 0;j < graph[minIndex].size();j++)
		{
			if (!flag[graph[minIndex][j]])
				minCostQ.push(mstNodeType<T>(graph[minIndex][i], minIndex, costList[minIndex][i]));
		}
	}
	return costSum;
}

//////////////////////////////

/* Gijkstra single source shortest path
 * Input: graph, adjacent matrix. source, int.
 * Output: path, store father
 * Time complexity: O(n^2).
 */

template<class T>
T dijkstra(int source, vector< vector<T> > &graph, vector<int> path)
{
	assert(graph.size() == graph[0].size());

	int nodeNum = graph.size();
	path.resize(nodeNum);
	for(int i = 0;i < nodeNum;i++)
		path[i] = -1;

	vector<int> flag(nodeNum, 0);
	flag[source] = 1;
	vector<T> cost(nodeNum, 0);
	for(int i = 0;i < nodeNum;i++)
		cost[i] = graph[source][i];

	T maxCost = 0;
	path[source] = -1;
	for(int i = 1;i < nodeNum;i++)
	{
		int minIndex = -1;
		T minCost = -1;

		for(int j = 0;j < nodeNum;j++)
			if (!flag[j] && cost[j] >= 0 && (cost[j] < minCost || minCost < 0))
			{
				minIndex = j;
				minCost = cost[j];
			}

		if (minIndex == -1)
			return -1;
		flag[minIndex] = 1;
		maxCost = minCost;

		for(int j = 0;j < nodeNum;j++)
			if (!flag[j] && (cost[j] > graph[minIndex][j] + minCost || cost[j] < 0))
			{
				cost[j] = graph[minIndex][j] + minCost;
				path[j] = minIndex;
			}
	}
	return maxCost;
}


/* dijkstra2
 * Input: graph: adjacent List, costList: adjacent List.
 * Ouput: path, path[i] store the father node. return the connected part number.
 * Complexity: O(n * logE).
 */
template <class T>
struct dijkNodeType
{
	T cost;
	int index, preIndex;
	dijkNodeType(int ind, int preInd, T c)
	{
		cost = c;
		index = ind;
		preIndex = preInd;
	}

	bool operator()(dijkNodeType &otherNode)
	{
		return cost < otherNode.cost;
	}
};

template<class T>
T dijkstra2(int source, vector<vector<int> > &graph, vector<vector<T> > &costList,vector<int> &path)
{
	int nodeNum = graph.size();
	path.resize(nodeNum);

	vector<int> flag(nodeNum, 0);
	flag[source] = 1;

	priority_queue< dijkNodeType<T>, vector<dijkNodeType<T> >, dijkNodeType<T> > minCostQ;
	path[source] = -1;
	T maxCost = 0;
	for(int i = 1;i < graph[0].size();i++)
		minCostQ.push(dijkNodeType<T>(graph[source][i], source, costList[source][i]));

	for(int i = 1;i < nodeNum;i++)
	{
		dijkNodeType<T> minCostNode = minCostQ.top();
		minCostQ.pop();

		while(!minCostQ.empty() && flag[minCostNode.index])
		{
			minCostNode = minCostQ.top();
			minCostQ.pop();
		}

		int minIndex = minCostNode.index;
		if (flag[minIndex])
			return -1;

		maxCost = minCostNode.cost;
		flag[minIndex] = 1;
		path[minIndex] = minCostNode.preIndex;

		for(int j = 0;j < graph[minIndex].size();j++)
		{
			if (!flag[graph[minIndex][j]])
				minCostQ.push(dijkNodeType<T>(graph[minIndex][i], minIndex, minCostNode.cost + costList[minIndex][i]));
		}
	}
	return maxCost;
}

//////////////////////////////////
/*
 * Floyd
 * Input: graph, adjacent matrix.
 * Output: cost[][], path[][].
 * Time complexity: O(n^3).
 */
template <class T>
void floyd(vector< vector<T> > &graph, vector<vector<T> >cost, vector<vector<int> >path)
{
	assert(graph.size() == graph[0].size());
	int nodeNum = graph.size();

	for(int i = 0;i < nodeNum;i++)
		for(int j = 0;j < nodeNum;j++)
		{
			cost[i][j] = graph[i][j];
			if (i != j && cost[i][j] != -1)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}

	for(int k = 0;k < nodeNum;k++)
		for(int i = 0;i < nodeNum;i++)
			if(i != k)
				for(int j = 0;j < nodeNum;j++)
					if (j != k && j != i && cost[i][k] >= 0 && cost[k][j] >= 0
							&& cost[i][k] + cost[k][j] < cost[i][j])
					{
						cost[i][j] = cost[i][k] + cost[k][j];
						path[i][j] = path[k][j];
					}
}
