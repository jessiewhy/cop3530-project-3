#ifndef Header
#define Header
#include <vector>
#include <iostream>
#include <climits>
#define V 50
using namespace std;

class Graphs_P3
{
private:
	//Graph data structure here or create another class to implement it
	int theGraph[V][V];
	bool myInit = 0;
public:
	Graphs_P3() {};
	bool isVertex(int from, int to);    //checks if vertex exists or not
	void insertVertex(int vertex); //inserts new vertex in graph
	void insertEdge(int from, int to, int weight);  //inserts new edge in graph
	bool isEdge(int from, int to);  //returns true if there is an edge between the vertices from and to
	int getWeight(int from, int to);  //returns the weight of the edge between the vertices from and to
	vector<int> getAdjacent(int vertex);  //return a vector of integers representing vertices adjacent to vertex
	void printDijkstra(int source);  //prints result of running Dijkstra's algorithm with source vertex
	void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
	~Graphs_P3() {
		for (int i = 0; i<V; ++i)
		{
			delete[] theGraph[i];
		}
		delete[] theGraph;
	}
};


#endif
