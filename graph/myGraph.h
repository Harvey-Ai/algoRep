/*
 myGraph
 Created on: Aug 27, 2014
     Author: ufo008ahw
*/


#include <vector>
using namespace std;

///////////////////////////////////////
// bipartite graph
/*
 * Edmonds's matching
 * Input: graph, adjacent matrix.
 * Output: max match number.
 * Time complexity: O(n ^ E).
 */
int maxMatch(vector< vector<int> > graph);

////////////////////////////////////////
// tree

/* MST
 * Input: graph, adjacent matrix.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n * n).
 */
template<class T>
T minSpanTree_prime(vector<vector<T> > &graph, vector<int> &tree);

/* MST_2
 * Input: graph: adjacent List, costList: adjacent List.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n * logE).
 */
template<class T>
T minSpanTree_prime2(vector<vector<int> > &graph, vector<vector<T> > &costList, vector<int> &tree);

////////////////////////////////////////
//general graph

/* Gijkstra single source shortest path
 * Input: graph, adjacent matrix. source, int.
 * Output: path, store father
 * Time complexity: O(n^2).
 */
template<class T>
T dijkstra(int source, vector< vector<T> > &graph, vector<int> path);

/* dijkstra2
 * Input: graph: adjacent List, costList: adjacent List.
 * Ouput: path, path[i] store the father node. return the connected part number.
 * Complexity: O(n * logE).
 */
template<class T>
T dijkstra2(int source, vector<vector<int> > &graph, vector<vector<T> > &costList,vector<int> &path);

/*
 * Floyd
 * Input: graph, adjacent matrix.
 * Output: cost[][], path[][].
 * Time complexity: O(n^3).
 */
template <class T>
void floyd(vector< vector<T> > &graph, vector<vector<T> >cost, vector<vector<int> >path);
