using namespace std;

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
    void create_array(int isDirected);
    void heapify();
    void insert(int u,int v,int e);
    void showArray();
    Node * heapDelete();
    ~Heap();
};
void Heap::create_array(int isDirected){
  if(!isDirected){
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
  else{
    Graph g;
    Node *n=NULL;
    a[0]=NULL;
    int k=1;
    for(int i=1;i<=vertices;i++){
      for(int j=1;j<=vertices;j++){
        if(g.AdjGraph[i][j]){
          n=new Node;
          n->u=i;n->v=j;n->e=g.AdjGraph[i][j];
          a[k++]=n;
        }
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
