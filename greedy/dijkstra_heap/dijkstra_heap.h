using namespace std;
class Node{
    public:
        int u;
        int v;
        int d;
};
class Heap{
    private:
        int size;
        int length;
        Node **h;
    public:
        Heap(int s){
            size=s;
            h=new Node*[size+1];
            length=0;
            for(int i=0;i<=size;i++) h[i]=NULL;
        }
        void heap_insert(int u,int v,int d); 
        Node* heap_delete();
        ~Heap();
};
void Heap::heap_insert(int u,int v,int d){
    Node *t=new Node;
    t->u=u;t->v=v;t->d=d;
    length++;
    int i=length;
    while(i>1 && t->d < h[i/2]->d){
        h[i]=h[i/2];
        i/=2;
    }
    h[i]=t;
}
Node * Heap::heap_delete(){
    Node* returnNode=h[1];
    Node* t=NULL;
    h[1]=h[length];
    h[length]=NULL;
    length--;
    int i=1;int j=i*2;
    while(j<=length){
        if(j+1<=length && h[j+1]->d<h[j]->d) j++;
        if(h[j]->d<h[i]->d){
            t=h[j];
            h[j]=h[i];
            h[i]=t;
            i=j;j*=2;
        }
        else break;
    }
    return returnNode;
}
Heap::~Heap(){
	for(int i=1;i<=length;i++){
     	h[i]=NULL;
	}
    delete []h;
}
