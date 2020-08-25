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
  int i=noOfEdges;
  Node *n=NULL;

  cout<<"Current Min Heap Status :- "<<endl;
  h.showArray();
  cout<<"Current Set Status :- "<<endl;
  d.showSet();
  while(i>0){
    n=h.heapDelete();
    if(d.unionSet(n->u,n->v)){
      totalCost+=n->e;
    }
    i--;
    cout<<"Current Min Heap Status :- "<<endl;
    h.showArray();
    cout<<"Current Set Status :- "<<endl;
    d.showSet();
  }
  return 0;
}
