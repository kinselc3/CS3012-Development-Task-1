#include <stdio.h>
#include <stdlib.h>
//#include <cbdd.h>

#include "DAG.c"


int main()
{

  int V = 7; 
  struct Graph* graph = createGraph(V); 
  
  addEdge(graph,6,3);
  addEdge(graph,6,5);
  addEdge(graph,3,2);
  addEdge(graph,5,4);
  addEdge(graph,2,1);
  addEdge(graph,4,1);
  addEdge(graph,1,0);
  
 
  // print the adjacency list representation of the above graph 
  printGraph(graph); 
 
 
}
