#include<iostream>
using namespace std;
long double e(int x,int n){
    static long double p=1,f=1;
    long double r;
    if(n==0) return 1;
    else{
        r=e(x,n-1);
        p*=x;f*=n;
        return r+(long double)p/f;
    }
}
int main(){
    int x,n;
    cin>>x>>n;
    cout<<e(x,n);
    return 0;
}