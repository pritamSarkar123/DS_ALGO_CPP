#include<iostream>
#define INF 9999
using namespace std;
//graph is at:-
//https://www.youtube.com/watch?v=XB4MIexjvY0
int graph[7][7]={
    {INF,INF,INF,INF,INF,INF,INF},
    {INF,0,2,4,INF,INF,INF},
    {INF,INF,0,1,7,INF,INF},
    {INF,INF,INF,0,INF,3,INF},
    {INF,INF,INF,INF,0,INF,1},
    {INF,INF,INF,INF,2,0,5},
    {INF,INF,INF,INF,INF,INF,0}
};
int NodeWeight[7]={INF,INF,INF,INF,INF,INF,INF};//n+1
int Visited[7]={-1,-1,-1,-1,-1,-1,-1};//n+1
int noOfNodes=6;
void Dijkstra(int s){
    int startNode=s;
    int shortestPath[noOfNodes+1]={0};
    int costs[noOfNodes+1]={0};
    NodeWeight[s]=0;
    int k=1;
    int minVal,minNode;
    while(k<noOfNodes){
        Visited[s]=1;
        minVal=INF;minNode=0;
        for(int i=1;i<=noOfNodes;i++){
            if(graph[s][i]!=INF && graph[s][i]!=0 && Visited[i]==-1){//if not visited yet, not self loop, not unreachable
                if(NodeWeight[i]>graph[s][i]+NodeWeight[s]){//relaxation
                    NodeWeight[i]=graph[s][i]+NodeWeight[s];
                }
                if(NodeWeight[i]<=minVal){
                    minVal=NodeWeight[i];
                    minNode=i;
                }
            }
        }
        cout<<"From "<<s<<" to "<<minNode<<" cost = "<<NodeWeight[minNode]<<endl;
        shortestPath[s]=minNode;
        costs[minNode]=NodeWeight[minNode];
        s=minNode;
        k++;
    }
    //----------------------------------
    cout<<"Shortest Path:-"<<endl;
    int i=startNode;
    k=noOfNodes;
    cout<<"Start";
    while(k){
        cout<<"->"<<i;
        i=shortestPath[i];
        k--;
    }
    cout<<"->End"<<endl;
    //-----------------------------------
    cout<<"Costs form starting vertex"<<startNode<<endl;
    k=1;
    while(k<=noOfNodes){
        cout<<startNode<<" to "<<k<<" total cost= "<<costs[k]<<endl;
        k++;
    }
}
int main(){
    int s;
    cout<<"Enter starting vertex"<<endl;
    cin>>s;
    Dijkstra(s);
    return 0;
}