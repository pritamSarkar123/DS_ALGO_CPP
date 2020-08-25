#include <iostream>
#include <cstdlib>
using namespace std;
class Graph{
  public:
    int AdjGraph[9][9]={
      {0,0,0,0,0,0,0,0,0},
      {0,0,1,7,0,0,0,0,0},
      {0,1,0,0,5,6,0,0,0},
      {0,7,0,0,2,0,0,0,0},
      {0,0,5,2,0,0,0,0,0},
      {0,0,6,0,0,0,3,9,0},
      {0,0,0,0,0,3,0,0,8},
      {0,0,0,0,0,9,0,0,4},
      {0,0,0,0,0,0,8,4,0}
    };
};
class Node{
  public:
  int u;
  int v;
  int e;
};
class Heap{
  private:
    int nextIndex;
    int length;
    int lengthInitial;
    int vertices;
    Node **a;
  public:
    Heap(int noOfEdges,int noOfVertices){
      nextIndex=1;
      length=noOfEdges;
      lengthInitial=length;
      vertices=noOfVertices;
      a=new Node*[length+1];
      for(int i=0;i<=length;i++) a[i]=NULL;
    }
    void create_array();
    void heapify();
    void insert(int u,int v,int e);
    void showArray();
    Node * heapDelete();
    ~Heap();
};
class DisJointSet{
  private:
    int length;
    int *mainSet;
  public:
    DisJointSet(int noOfVertices){// act as makeset
      length=noOfVertices;
      mainSet=new int[length+1];
      mainSet[0]=0;
      for(int i=1;i<=length;i++) mainSet[i]=-1;
    }
    int findSet(int u);//retuens the set identityElement
    int unionSet(int u,int v);//O(m alpha(n)) m-no of unions n-no of vertices
    void showSet();
    ~DisJointSet(){
      delete []mainSet;
    }
};
void Heap::create_array(){
  Graph g;
  Node *n=NULL;
  a[0]=NULL;
  int k=1;
  for(int i=1;i<=vertices;i++){
    for(int j=i+1;j<=vertices;j++){
      if(g.AdjGraph[i][j]){
        n=new Node;
        n->u=i;n->v=j;n->e=g.AdjGraph[i][j];
        a[k++]=n;
      }
    }
  }
}
void Heap::heapify(){
  int k,j;Node *t=NULL;
  nextIndex=length+1;
  for(int i=length;i>=1;i--){
    k=i;j=i*2;
    while(j<=length){
      if(j+1<=length && a[j+1]->e<a[j]->e) j=j+1;
      if(a[j]->e<a[k]->e){
        t=a[j];
        a[j]=a[k];
        a[k]=t;
        //--------
        k=j;j=j*2;
      }
      else break;
    }
  }
}
void Heap::insert(int u,int v,int e){
      Node *temp=new Node;
      temp->e=e;temp->u=u;temp->v=v;
      int i=nextIndex;
      while(i>1 && temp->e<a[i/2]->e){
        a[i]=a[i/2];
        i/=2;
      }
      a[i]=temp;
      nextIndex++;
    }
Node * Heap::heapDelete(){
  Node *returnNode=a[1];
  Node *t=NULL;
  a[1]=a[nextIndex-1];
  int i=1;int j=i*2;
  while(j<nextIndex-1){
    if(j+1<nextIndex-1 && a[j+1]->e<a[j]->e) j=j+1;
      if(a[j]->e<a[i]->e){
        t=a[j];
        a[j]=a[i];
        a[i]=t;
      //--------
        i=j;j=j*2;
      }
      else break;
  }
  length--;
  nextIndex--;
  return returnNode;
}
void Heap::showArray(){
  for(int i=1;i<nextIndex;i++){
    cout<<"( u="<<a[i]->u<<" v="<<a[i]->v<<" weight="<<a[i]->e<<" )";
  }
  cout<<endl;
}
Heap::~Heap(){
  Node *t=NULL;
  for(int i=0;i<nextIndex;i++){
    t=a[i];
    delete t;
    a[i]=NULL;t=NULL;
  }
  delete []a;
}
int DisJointSet::findSet(int u){
  while(mainSet[u]>0) u=mainSet[u];
  return u;  
}
int DisJointSet::unionSet(int u,int v){ 
  int setId1=findSet(u);
  int setId2=findSet(v);
  if(setId1!=setId2){
    if(abs(mainSet[setId1])>abs(mainSet[setId2])){
      mainSet[setId1]+=mainSet[setId2];
      mainSet[setId2]=setId1;
      mainSet[v]=setId1;// partial path comprehension
    }
    else{
      mainSet[setId2]+=mainSet[setId1];
      mainSet[setId1]=setId2;
      mainSet[u]=setId2;// partial path comprehension
    }
    return 1;
  }
  return 0;
}
void DisJointSet::showSet(){
  cout<<"[ ";
  for(int i=1;i<=length;i++){
    cout<<mainSet[i]<<" ";
  }
  cout<<"]"<<endl;
}