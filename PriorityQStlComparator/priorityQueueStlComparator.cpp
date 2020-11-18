#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Pair{
    int x;
    int y;
    public:
        Pair(int x_,int y_){
            x=x_;y=y_;
        }
        int getX() const{return x;}
        int getY() const{return y;}
};

class MyComparator{
    public:
        // int operator() (const Pair &p1,const Pair &p2){ //greater for minHeap
        //     if(p1.getX()==p2.getX()){
        //         return p1.getY()>p2.getY();
        //     }
        //     return p1.getX()>p2.getX();
        // }
        int operator() (const Pair &p1,const Pair &p2){ //smaller for maxHeap
            if(p1.getX()==p2.getX()){
                return p1.getY()<p2.getY();
            }
            return p1.getX()<p2.getX();
        }
};

int main()
{
   priority_queue<Pair,vector<Pair>,MyComparator> pq;
   pq.push(Pair(5,6));
   pq.push(Pair(5,7));
   pq.push(Pair(6,7));
   pq.push(Pair(5,3));
   pq.push(Pair(1,9));
   
    while(!pq.empty()){
        cout<<pq.top().getX()<<" "<<pq.top().getY()<<"\n";
        pq.pop();
    }
   cout<<endl;
   return 0;
}