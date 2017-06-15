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

bool checkCycleThroughNode(int** graph, int size, bool* visited, int father, int node)
{
	bool value = false;
	if (node < size)
	{
		visited[node] = true;

		cout<<"Checking father: "<<father<<" and son: "<<node<<endl;
		for (int i = 0; i < size; ++i)
		{
			if (i != node && i != father)
			{
				//cout<<"Checking father: "<<father<<" with: "<<i<<endl;
				if (graph[node][i] != -1)
				{
					if (visited[i])
					{
						return true;
					}else{
						value |= checkCycleThroughNode(graph, size, visited, node, i);
					}
				}
			}
		}
	}
	return value;
}

bool hasCycle(int** graph, int size, Edge* edge)
{
	bool visitedNodes[size];
	initVisitedArray(visitedNodes, size);
  graph[edge->source][edge->destination] = edge->weight;
  graph[edge->destination][edge->source] = edge->weight;

	bool hasCycleWithNode = checkCycleThroughNode(graph, size, visitedNodes, 0, 0);

	if(hasCycleWithNode)
	{
		cout<<"Had cycle"<<endl;
		graph[edge->source][edge->destination] = -1;
		graph[edge->destination][edge->source] = -1;
	}

	return hasCycleWithNode;
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
		while(i < edges.size())
    {
			if(!hasCycle(kruskalGraph, size, edges[i++]))
      {
      }
			//++addedEdges;
    }
    return kruskalGraph;
}

int main ()
{
    test();
    return 0;
}
