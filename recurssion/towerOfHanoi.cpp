#include<iostream>
using namespace std;
//(no of disks,from,using ,to)
void toh(int n,int a,int b,int c){
    if(n>0){
        toh(n-1,a,c,b);
        cout<<"("<<a<<","<<c<<")"<<endl;
        toh(n-1,b,a,c);
    }
}
int main(){
    int n;
    cin>>n;
    toh(n,1,2,3);
    return 0;
}