#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <climits> 
#include <cstdlib>
#include <string>    
using namespace std;
#define V 50

class Graphs_P3
{
private:
	int myGraph[V][V] = { { 0 } };
	bool myInit = 0;
public:
	void insertVertex(int vertex); //inserts new vertex in graph
	void insertEdge(int from, int to, int weight);  //inserts new edge in graph
	bool isEdge(int from, int to);  //returns true if there is an edge between the vertices from and to
	int getWeight(int from, int to);  //returns the weight of the edge between the vertices from and to    
	vector<int> getAdjacent(int vertex);  //return an array of integers representing vertices adjacent to vertex
	void printDijkstra(int source);   //prints result of running Dijkstra algorithm with source vertex
	void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
	int minimumDist(int dist[], bool Dset[]);
	string printPath(int idx, int PreNode[], int source);

}
;
void Graphs_P3::insertVertex(int vertex)
{
	//printf("%d",vertex);
	if (myInit == 0) {
		for (int i=0; i < V; i++)
			for (int j=0; j < V; j++)
				myGraph[i][j] = 0;
		myInit = 1;
	}
	myGraph[vertex][vertex] = -1;
}
void Graphs_P3::insertEdge(int from, int to, int weight)
{
	myGraph[from][to] = weight;
}
bool Graphs_P3::isEdge(int from, int to)
{
	bool myEdge = 0;
	if (myGraph[from][to] != 0 && myGraph[from][to] != -1)  myEdge = 1;
	return myEdge;
}
int Graphs_P3::getWeight(int from, int to)
{
	return myGraph[from][to];
}
vector<int> Graphs_P3::getAdjacent(int vertex)
{
	int j;
	int vidx = 0;
	vector<int> myarr;

	for (j = 0; j<V; j++)
		if (myGraph[vertex][j] != 0 && myGraph[vertex][j] != -1)  myarr.push_back(j);
	return myarr;
}


void Graphs_P3::printGraph() {
	for (int i = 0; i<V; i++) {
		if (myGraph[i][i] == -1) {
			cout << i << " ";
			for (int j = 0; j<V; j++)
				if (myGraph[i][j] > 0) cout << j << " ";
			cout << "\n";
		}
	}
}

int Graphs_P3::minimumDist(int dist[], bool Dset[])   /*A method to find the vertex with minimum distance which is not yet included in Dset*/
{
	int min = INT_MAX, index;                 /*initialize min with the maximum possible value as infinity does not exist */
	for (int v = 0; v<V; v++)
	{
		if (Dset[v] == false && dist[v] <= min)
		{
			min = dist[v];
			index = v;
		}
	}
	return index;
}
void Graphs_P3::printDijkstra(int source)   /*Method to implement shortest path algorithm*/
{
	int dist[V];
	bool Dset[V];
	int preNode[V];
	for (int i = 0; i<V; i++)                    /*Initialize distance of all the vertex to INFINITY and Dset as false*/
	{
		dist[i] = INT_MAX;
		Dset[i] = false;
		preNode[i] = -1;
	}
	dist[source] = 0;                                   /*Initialize the distance of the source vertec to zero*/
	for (int c = 0; c<V; c++)
	{
		int u = minimumDist(dist, Dset);              /*u is any vertex that is not yet included in Dset and has minimum distance*/
		Dset[u] = true;                              /*If the vertex with minimum distance found include it to Dset*/
		for (int v = 0; v<V; v++)
			/*Update dist[v] if not in Dset and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
		{
			if (!Dset[v] && myGraph[u][v] && dist[u] != INT_MAX && dist[u] + myGraph[u][v]<dist[v])
			{
				dist[v] = dist[u] + myGraph[u][v];
				preNode[v] = u;
			}
		}
	}
	cout << "V D P" << endl;;
	//	cout<<" "<<source<<"\n";
	for (int i = 0; i<V; i++)                       /*will print the vertex with their distance from the source to the console */
	{

		if (dist[i] != INT_MAX && dist[i] == 0 && i != source && myGraph[i][i] != 0)  cout << i;
		if (dist[i] != INT_MAX && dist[i] != 0 && i != source && myGraph[i][i] != 0) cout << i << " " << dist[i] << " " << printPath(i, preNode, source);

	}
}

string Graphs_P3::printPath(int idx, int preNode[], int source) {

	string myResult;
	int i = idx;
	// myResult = std::to_string(preNode[i]);


	myResult = to_string(preNode[i]) + "-" + std::to_string(idx);

	while (preNode[i] != source) {
		i = preNode[i];
		myResult = to_string(preNode[i]) + "-" + myResult;



	}
	//  myResult = to_string(source) + myResult;
	return myResult;
}

int main()
{
	//DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
	int noOfLines, operation, vertex, to, fro, weight, source, j;
	vector<int> arr;
	int arrSize;
	Graphs_P3 g;
	cin >> noOfLines;
	for (int i = 0; i<noOfLines; i++)
	{
		cin >> operation;
		switch (operation)
		{
		case 1:
			cin >> vertex;
			g.insertVertex(vertex);
			break;
		case 2:
			cin >> fro;
			cin >> to;
			cin >> weight;
			g.insertEdge(fro, to, weight);
			break;
		case 3:
			cin >> fro;
			cin >> to;
			cout << g.isEdge(fro, to) << "\n";
			break;
		case 4:
			cin >> fro;
			cin >> to;
			cout << g.getWeight(fro, to) << "\n";
			break;
		case 5:
			cin >> vertex;
			arr = g.getAdjacent(vertex);
			arrSize = arr.size();
			j = 0;
			while (j<arrSize)
			{
				cout << arr[j] << " ";
				j++;
			}
			cout << "\n";
			break;
		case 6:
			cin >> source;
			g.printDijkstra(source);
			cout << "\n";
			break;
		case 7:
			g.printGraph();
			cout << "\n";
			break;
		}
	}
}