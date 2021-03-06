#include <iostream>
#include "dijkstra_heap.h"
#define INF 9999
using namespace std;
int graph[7][7]={
    {INF,INF,INF,INF,INF,INF,INF},
    {INF,0,2,4,INF,INF,INF},
    {INF,INF,0,1,7,INF,INF},
    {INF,INF,INF,0,INF,3,INF},
    {INF,INF,INF,INF,0,INF,1},
    {INF,INF,INF,INF,2,0,5},
    {INF,INF,INF,INF,INF,INF,0}
};

int noOfEdges=8;
int noOfNodes=6;
int main(){
	int NodeWeight[noOfNodes+1]={INF,INF,INF,INF,INF,INF,INF};//n+1
	int Visited[noOfNodes+1]={-1,-1,-1,-1,-1,-1,-1};//n+1
    Heap h(noOfEdges);
    int s=1;
    NodeWeight[s]=0;
    
    h.heap_insert(s,s,0);
    
    Node *n=NULL;
    
    while(noOfEdges){
        n=h.heap_delete();
        if(Visited[n->v]==-1){
        	cout<<"node from "<<n->u<<" to "<<n->v<<" cost "<<n->d<<endl;
        	Visited[n->v]=1;
        	for(int i=1;i<=noOfNodes;i++){
        		if(graph[n->v][i]!=0 && graph[n->v][i]!=INF && Visited[i]==-1){
                	if(NodeWeight[i]>n->d+graph[n->v][i]){
                    	NodeWeight[i]=n->d+graph[n->v][i];
                    	h.heap_insert(n->v,i,NodeWeight[i]);
          
                	}
            	}
        	}
        }
        delete n;
        n=NULL;
        noOfEdges--;
    }
    return 0;
}
