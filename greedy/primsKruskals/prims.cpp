#include <iostream>
#include "node.h"
#include "graph.h"
#include "heap.h"
#include "disjointSet.h"

#define VISITED 9999
#define HIPPED 999

using namespace std;

int main(){
  int noOfEdges=9;
  int noOfVertices=8;
  int totalCost=0;
  int startingVertex=1;
  int i=noOfVertices-1;
  Node *n=NULL;
  Graph g;
  Heap h(noOfEdges,noOfVertices);
  DisJointSet d(noOfVertices);
  while(i>0){//we carry on the loop upto |V|-1 times
    for(int j=1;j<=noOfVertices;j++){ 
      //find for adjacent vertices , which are yet not visited and not hipped yet
      if(g.AdjGraph[startingVertex][j]!=0 
      && g.AdjGraph[startingVertex][j]!=VISITED
      && g.AdjGraph[startingVertex][j]!=HIPPED ){
        h.insert(startingVertex,j,g.AdjGraph[startingVertex][j]);
        g.AdjGraph[startingVertex][j]=HIPPED;
        g.AdjGraph[j][startingVertex]=HIPPED;
        //make the value at the coordinates "HIPPED"
      }
    }
    
    n=h.heapDelete(); //min element each time
    if(d.unionSet(n->u,n->v)){// if it is not forming cycle
      totalCost+=n->e;// increment cost by the edge weight
      g.AdjGraph[n->u][n->v]=VISITED;
      g.AdjGraph[n->v][n->u]=VISITED;
      //make the value at the coordinates "VISITED"
      startingVertex=n->v; //make the next starting vertex
      i--;
      cout<<n->u<<" "<<n->v<<endl;
      //cout<<"startingVertex="<<startingVertex<<endl;
    }
    else{
      cout<<n->u<<" "<<n->v<<" forming cycle"<<endl;
    }
    delete n;
    n=NULL;
  } 
  cout<<"Total cost="<<totalCost<<endl;
  return 0;
}