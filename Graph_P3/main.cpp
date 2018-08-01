#include "Header.h"
#include <iostream>
#include <vector>
#include <limits>
int a = std::numeric_limits<int>::max();
using namespace std;

void Graphs_P3::insertVertex(int vertex)
{
	theGraph[vertex][vertex] = 0;
}

void Graphs_P3::insertEdge(int from, int to, int weight)
{
	theGraph[from][to] = weight;
}

bool Graphs_P3::isEdge(int from, int to)
{
	if (theGraph[from][to] != -1) return true;
	else return false;
}

int Graphs_P3::getWeight(int from, int to)
{
	return theGraph[from][to];
}

vector<int> Graphs_P3::getAdjacent(int vertex) {
	int j;
	vector<int> myarr;

	for (j = 0; j < 50; j++)
		if (theGraph[vertex][j] != 0)  myarr.push_back(j);
	cout << "test, test, test";
	return myarr;
}

void Graphs_P3::printDijkstra(int source)
{
	int cost[MAXNUMVERTICES][MAXNUMVERTICES], distance[MAXNUMVERTICES], pred[MAXNUMVERTICES];
	int visited[MAXNUMVERTICES], count, mindistance, nextnode, i, j;

	for (i = 0; i<50; i++)
		for (j = 0; j<50; j++)
			if (theGraph[i][j] != 0)
				cost[i][j] = theGraph[i][j];
			else
				cost[i][j] = a;
	for (i = 0; i<50; i++)
	{
		distance[i] = cost[source][i];
		pred[i] = source;
		visited[i] = 0;
	}

	distance[source] = 0;
	visited[source] = 1;
	count = 1;

	while (count<50 - 1)
	{
		mindistance = a;

		//nextnode gives the node at minimum distance
		for (i = 0; i<50; i++)
			if (distance[i]<mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}

		//check if a better path exists through nextnode            
		visited[nextnode] = 1;
		for (i = 0; i<50; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i]<distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	for (i = 0; i<50; i++)
		if (i != source)
		{
			printf("\nDistance of node%d=%d", i, distance[i]);
			printf("\nPath=%d", i);

			j = i;
			do
			{
				j = pred[j];
				printf("<-%d", j);
			} while (j != source);
		}
}

void Graphs_P3::printGraph()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cout << theGraph[i][j] <<" "<<endl;
		}
	}
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