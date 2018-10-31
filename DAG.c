#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.c"

int x;
/*
int LCA(struct Graph* graph, int A, int B){
	//todo
	if(A < -1  || B < -1 || A > graph->V|| B > graph->V)
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
        //printf("\n Adjacency list of vertex %d\n head ", v); 
		
        while (pCrawlA) 
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
*/
/*
int lowestAdjNode(struct AdjListNode* pCrawl,int i){
	printf("here\n");
	if(pCrawl->next == NULL)
		return i;
	if(pCrawl->next->dest <i){
		i = pCrawl->next->dest;
		lowestAdjNode(pCrawl->next,i);
	}
	return i;
}

int LCA(struct Graph* graph, int A, int B){
	if(A < -1  || B < -1 || A > graph->V|| B > graph->V)
		return -1;
	
	struct AdjListNode *pCrawlA= graph->array[A].head;
	struct AdjListNode *pCrawlB= graph->array[B].head;
	lowestAdjNode(pCrawlA,A);
	lowestAdjNode(pCrawlB,B);
	if(A == B)
	{
		return A;
	}
	return - 1;
}
bool contains(struct AdjListNode*pCrawl,int B){
	if(pCrawl->dest == B)
		return true;
	if(pCrawl->next==NULL)
		return false;
	else
		contains(pCrawl->next,B);
}
bool contains(struct Graph* graph, int A, int B){
	if(A > graph->V)
		return false;
	struct AdjListNode *pCrawl= graph->array[A].head;
	if(pCrawl->dest ==B)
		return true;
	if(pCrawl->next != null)
		contains();
}
*/

bool contains(struct AdjListNode* pCrawl, int A){
        //struct AdjListNode* pCrawl = graph->array[A].head; 
        //printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            if(pCrawl->dest == A)
					return true;
            pCrawl = pCrawl->next; 
        } 
		return false;
}

int LCA(struct Graph* graph,int A, int B){
	
	for(int i = 0 ; i < graph->V;i++){
		struct AdjListNode *pCrawl = graph->array[i].head;
		if(contains(pCrawl,A)==true)
			for(int j = 0 ; j < graph->V;j++){
				pCrawl = graph->array[j].head;
				if(contains(pCrawl,B)==true)
					return i;
			}
		if(contains(pCrawl,B)==true)
			for(int j = 0 ; j < graph->V;j++){
				pCrawl = graph->array[j].head;
				if(contains(pCrawl,A)==true)
					return i;	
			}
	}		
	return -1;
}

