#include "DsetAndHeap.h"
int main() {
  //---------------Kruskals--------------//
  int noOfEdges=9;
  int noOfVertices=8;
  int totalCost=0;
  Heap h(noOfEdges,noOfVertices);
  h.create_array();
  h.heapify();
  DisJointSet d(noOfVertices);
  int i=noOfVertices-1;
  Node *n=NULL;

  // cout<<"Current Min Heap Status :- "<<endl;
  // h.showArray();
  // cout<<"Current Set Status :- "<<endl;
  // d.showSet();
  while(i>0){
    n=h.heapDelete();
    if(d.unionSet(n->u,n->v)){
      totalCost+=n->e;
      cout<<n->u<<" "<<n->v<<endl;
      i--;
    }
    // cout<<"Current Min Heap Status :- "<<endl;
    // h.showArray();
    // cout<<"Current Set Status :- "<<endl;
    // d.showSet();
    else{
      cout<<n->u<<" "<<n->v<<" forming cycle"<<endl;
    }
  }
  cout<<"Total cost="<<totalCost<<endl;
  return 0;
}
