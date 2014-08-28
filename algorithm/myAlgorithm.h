/*
 myAlgorithm
 Created on: Aug 27, 2014
     Author: ufo008ahw
*/


// bipartite graph
extern int maxMatch(vector< vector<int> > graph);

////////////////////////////////////////
// tree


////////////////////////////////////////
//general graph
/*
 * Input: graph, a adjacent matrix.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n^2).
 */
extern int MST(int n, int tree[]);
extern void dijkstra(int n, int path[]);
extern void floyd(int n);
