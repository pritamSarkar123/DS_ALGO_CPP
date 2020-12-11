#include <iostream>
#include<stack>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

class point{
    int x;
    int y;
    public:
    point(int _x,int _y){
        x=_x;y=_y;
    }
    int getX() const{return x;}
    int getY() const{return y;}
};
class MyComparatorMaxHeap{
    public:
    int operator()(const point &p1,const point &p2){
        return p2.getX()>p1.getX();
    }
};
class MyComparatorMinHeap{
    public:
    int operator()(const point &p1,const point &p2){
        return p1.getX()>p2.getX();
    }
};

int main() {
    priority_queue<point,vector<point>,MyComparatorMinHeap> minH;
    priority_queue<point,vector<point>,MyComparatorMaxHeap> maxH;
    for(int i=0;i<5;i++){
        minH.push(point(i+1,(i+1)*2));
        maxH.push(point(i+1,(i+1)*2));
    }
    cout<<"1st min heap"<<endl;
    while(!minH.empty()){
        cout<<"( "<<minH.top().getX()<<" , "<<minH.top().getY()<<" )"<<" ";
        minH.pop();
    }cout<<endl;
    cout<<"2nd max heap"<<endl;
    while(!maxH.empty()){
        cout<<"( "<<maxH.top().getX()<<" , "<<maxH.top().getY()<<" )"<<" ";
        maxH.pop();
    }cout<<endl;
	return 0;
}
