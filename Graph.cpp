#include "Graph.hpp"
#include <map>
#include <queue>
#include <set>


//method to find the shortest path using A* search
void
Graph::shortestPath(vector<list<pair<string, int>>> adjList, map<string, int> vertexList,
	map<string, pair<double, double>> coordinates, string start, string end, int vertices)
{
	map<string, int> distance;

	/*set distance to a city from the adjacncey list to infinity
	 *in the distance map*/
	 for (unsigned int i = 0; i < adjList.size(); i++)
	 {

		 for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
		 {
			 distance[j->first] = 1000000;
		 }
	 }
		
	//first pair of city coordinates
	pair<double, double> firstPair = coordinates[start];

	//second pair of city coordinates
	pair<double, double> secondPair = coordinates[end];

	//a set containing the vertices that have been visited
	set <pair<string, int>> visited;

	/*set the distance of the starting point to 0
	 *and add it to visited set*/
	distance[start] = 0;
	visited.insert(make_pair(start, 0));

	//calculate h
	double h = (firstPair.first - secondPair.first)
			 + (firstPair.second - secondPair.second);

	while (!visited.empty())
	{
		//keeps track of the beginning pair in visited
		pair<string, int> min = *(visited.begin());

		string vertex = min.first;
		int path = min.second;
		//int currentTotal = 0;

		visited.erase(visited.begin());

		//gets the index number of the passed in vertex
		int i = vertexList[vertex];

		/*loop through each adjacent vertex of the
		*current vertex thats in the adjacency list*/	 
		for (auto adjacent : adjList[i])
		{
			string v = adjacent.first;

			//calculate f
			double f = path + (adjacent.second + h);

			//if the distance of this path is less then update the distance
			if (distance[adjacent.first ] > f)
			{
				string target = adjacent.first;
				//currentTotal += path;
				auto j = visited.find(make_pair(target, distance[target]));

				//remove the old pair with the old cost
				if (j != visited.end())
				{
					visited.erase(j);
				}
				//update the distance and insert it into the visited map
				distance[target] = path + adjacent.second;
				visited.insert(make_pair(target, distance[target]));
			}
		}

	}
	bool startFound = false;
	bool endFound = false;
	int totalDistance = 0;

	/*loop through each element in distance and find
	 *the matching cities and print the distance*/
	 for (auto i : distance)
	 {
		 if (i.first == start)
		 {
			 startFound = true;
		 }
		 if (i.first == end)
		 {
			 endFound = true;
			 totalDistance = i.second;
		 }
	 }

	 /*if the starting point and the ending point are found
	  *the print out the distance*/
	  if (startFound == true && endFound == true)
	  {
		  cout << "The fastest route from " << start << " to " << end
		  << " is " << totalDistance << " miles " << endl << endl;
	  }
}
