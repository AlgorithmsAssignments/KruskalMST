#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

bool nodeHasBeenVisited(bool* visitedNodes, int currentNodeIndex)
{
	return visitedNodes[currentNodeIndex];
}

void initVisitedArray(bool* visited, int size)
{
	for(int i = 0; i < size; ++i)
	{
		visited[i] = false;
	}
}

bool hasCycle(int** graph, int size, Edge* edge)
{
	//graph[fromNode][toNode] = cost
	int currentNode = -1;
	int cost = -1;
	bool visitedNodes[size];
	initVisitedArray(visitedNodes, size);
  graph[edge->source][edge->destination] = edge->weight;
	for(int i = 0; i < size; ++i)
	{
		visitedNodes[i] = true;
		for(int k = 0; k < size; ++k)
		{
			cost = graph[i][k];
			if(cost != -1)
			{
        cout<<"Checking for cycle from "<<edge->source<<" to: "<<edge->destination<<endl;
				if(nodeHasBeenVisited(visitedNodes, k))
				{
          graph[edge->source][edge->destination] = -1;
					return true;
				}
			}
		}
	}
    return false;
}

int** initGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    int** kruskalGraph = initGraph(size);
    int addedEdges = 0;

    unsigned int i = 0;
    cout<<"Running"<<endl;
    while(addedEdges < size - 1)
    {
      if(i >= edges.size())
      {
        break;
      }
      if(hasCycle(kruskalGraph, size, edges[i++]))
      {
        ++addedEdges;
      }
    }
    return kruskalGraph;
}

int main ()
{
    test();
    return 0;
}
