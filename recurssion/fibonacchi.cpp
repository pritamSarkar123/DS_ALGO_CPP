#include<iostream>
using namespace std;
int *F; 
int fib(int n){
    if(n<=1){
        if(F[n]==-1) F[n]=n;
        return F[n];
    }
    else{
        if(F[n]==-1){
            if(F[n-1]==-1) F[n-1]=fib(n-1);
            if(F[n-2]==-1) F[n-2]=fib(n-2);
            F[n]=F[n-1]+F[n-2];
        }
        return F[n];
    }
}
void test(int n){
    for(int i=0;i<n;i++){
        cout<<F[i]<<endl;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    F=new int[n+1];
    for(int i=0;i<n+1;i++) F[i]=-1;
    cout<<fib(n)<<endl;
    delete []F;
    return 0;
}