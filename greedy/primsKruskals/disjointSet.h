#include <cstdlib>
using namespace std;

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