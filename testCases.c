#include <stdio.h>
#include <stdlib.h>
#include <cbdd.h>

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
 
  it("testing size of graph", ^{
        expect_equal(7,graph->V) ;
  });

  int n1 = 0, n2 = 1;
  int t = LCA(graph, n1, n2);
  it("testing parent and child", ^{
        expect_equal(1, t) ;
  });

  n1 = 5, n2 = 5;
  t = LCA(graph, n1, n2);
  it("testing same node", ^{
        expect_equal(5,t) ;
  });

  n1 = -1, n2 = 10;
  t = LCA(graph, n1, n2);

  it("testing missing node", ^{
        expect_equal(-1,t) ;
  });

}
