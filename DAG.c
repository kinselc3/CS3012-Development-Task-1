#include <stdio.h>
#include <stdlib.h>


#include "Graph.c"

int x;

int LCA(struct Graph* graph, int A, int B){
	//todo
	if(A < -1  || B < -1 || A < graph->V|| B < graph->V)
		return -1;
	int y = B;
	int x = A;
	int result = graph->V;
	int v; 
	struct AdjListNode* pCrawlA;
	struct AdjListNode* pCrawlB;
	
    for (v = 0; v < graph->V; ++v) 
    { 
        pCrawlA = graph->array[A].head; 
		pCrawlB = graph->array[B].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawlA || pCrawlB) 
        { 
			if(pCrawlA->dest < x)
				x = pCrawlA->dest;
			if(pCrawlB->dest < y)
				y = pCrawlB->dest;
			
			if(x == y)
			{
				result = x;
			}				
			
			pCrawlA = pCrawlA->next; 
			pCrawlB = pCrawlB->next; 
        }
	}		
	
	return result;
}