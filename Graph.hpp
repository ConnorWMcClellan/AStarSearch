#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

class Graph
{
private:

public:
	//method to find the shortest path using A* Search
	void shortestPath(vector<list<pair<string, int> > > adjList, map<string, int> vertexList,
		map<string, pair<double, double>> coordinates, string start, string end, int vertices);
};
#endif