/*
Runtime Terror A*        	Connor McClellan, Belle Erhardt,
						    Juan Sanchez, Kyle Dickhaus, Daniel Gonzalez 

October 29, 2021			Artificial Intelligence, Fall 2021, Dr. J

Description: A menu driven program using A* Search to find Shortest distance
			 between two cities in Missouri.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include "Graph.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	string fileName;
	string input;
	string s;
	string s1, s2 ,s3;
	string city;
	int cities = 0;
	int edges = 0;
	int cost;
	double x = 0;
	double y = 0;
	ifstream file;


	cout << "Enter File Name: ";
	cin >> fileName;

	file.open(fileName);
	vector <list<pair<string, int> > > adjList;
	map<string, int> cityList;
	int count = 0;

	/*while we have a line in the file add the value
	 *to its respected vector or map*/
	while (getline(file, input))
	{
		//allows you to parse the current line
		istringstream stream(input);

		/*if number of cities is 0 then add the first
		 *string to cities as an integer*/
		if (cities == 0)
		{
			cities = stoi(input);
			continue;
		}

		/*if number of edges is zero and the map of
		 *cities filled then take the current
		 *string and add it as an integer. Also,
		 *resize the adjacency list to the number
		 *of cities*/
		if (edges == 0 && count == cities)
		{
			edges = stoi(input);
			adjList.resize(cities + 1);
		}
		/*if the cities map is not filled and the
		 *number of cities is filled then add a
		 *pair containing the name of the city
		 *and an index number*/
		if (count < cities && cities != 0)
		{
			cityList.insert(make_pair(input, count));
			count++;
		}

		/*if the current string has the format of
		 *two strings and an integer then get the
		 *index number of both strings from the
		 *cities map. then take each index
		 *and add a pair containing the opposite
		 *city and the distance to travel there
		 *to the adjacency list*/
		if (stream >> s1 >> s2 >> cost)
		{
			int key = cityList[s1];
			int key2 = cityList[s2];
			adjList[key].push_back(make_pair(s2, cost));
			adjList[key2].push_back(make_pair(s1, cost));
		}
	}

	//read in the File containing data for the H Function
	cout << "Enter HFunction File: ";
	cin >> fileName;

	file.open(fileName);
	map<string, pair<double, double> > cityCoord;

	//while there is a line in the file add the corresponding
	//data to the cityCoord map
	while (getline(file, input))
	{
		istringstream stream(input);

		stream >> city >> y >> x;

		cityCoord.insert({ city, make_pair(x, y) });
	}

	
	string option;

	cout << "Choose an option from the menu!" << endl;
	cout << "1. Calculate shortest distance" << endl;
	cout << "2. End Program" << endl;
	cout << ">>>> ";
	cin >> option;

	while (option != "2")
	{
		string start;
		string end;
		Graph graph;

		//get the starting city
		cout << "For city names put '_' for spaces and put 'Saint' for 'St')" << endl;
		cout << "Starting Point: ";
		cin >> start;

		//get the ending city
		cout << "End Point: ";
		cin >> end;

		/*find the shortest path by passing the adjacency list,
		 *the map of cities, the map of city coordinates,
		 *the starting point, the ending point, and the
		 *number of cities to the function below*/
		graph.shortestPath(adjList, cityList, cityCoord, start, end, cities);

		cout << "Choose an option from the menu!" << endl;
		cout << "1. Calculate shortest distance" << endl;
		cout << "2. End Program" << endl;
		cout << ">>>> ";
		cin >> option;
	}

	cout << "Thank you for using Distance Calculator brought to you by Runtime Terror!" << endl;

	return 0;
}
