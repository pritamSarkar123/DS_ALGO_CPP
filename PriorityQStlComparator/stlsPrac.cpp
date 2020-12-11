#include <iostream>
#include<stack>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

void dequeUse(){
    deque<int> dq;
    for(int i=0;i<5;i++){
	    dq.push_front(i+1);
	    dq.push_back((i+1)*2);
	}
	cout<<"front "<<dq.front()<<endl;
	cout<<"back "<<dq.back()<<endl;
	cout<<"size "<<dq.size()<<endl;
	while(!dq.empty()){
	    cout<<dq.front()<<" ";
	    cout<<dq.back()<<" ";
	    dq.pop_front();
	    dq.pop_back();
	}cout<<endl;
}
void queueUse(){
    queue<int> q;
    for(int i=0;i<5;i++){
	    q.push(i);
	}
	cout<<"front "<<q.front()<<endl;
	cout<<"size "<<q.size()<<endl;
	while(!q.empty()){
	    cout<<q.front()<<" ";
	    q.pop();
	}cout<<endl;
}
void stackUse(){
    stack<int> s;
	for(int i=0;i<5;i++){
	    s.push(i);
	}
	cout<<"top "<<s.top()<<endl;
	cout<<"size "<<s.size()<<endl;
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}cout<<endl;
}
int main() {
    stackUse();
    queueUse();
    dequeUse();
	return 0;
}
