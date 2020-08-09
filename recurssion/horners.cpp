#include<iostream>
using namespace std;
long double e(int x,int n){
    static long double s=1;
    if(n==0) return s;
    else{
        s=1+((long double)x/n)*s;
        return e(x,n-1);
    }
}
// long double e(int x,int n){
//     long double s=1.0;
//     while(n>0){
//         s=1+(x/n)*s;
//         n--;
//     }
//     return s;
// }
int main(){
    int x,n;
    cin>>x>>n;
    cout<<e(x,n);
    return 0;
}