#include<iostream>
using namespace std;
/*
    to reduce complexity
    even power(2n):- pow(m,2n)==pow(m*m,n)
    odd power(2n+1):-pow(m,2n+1)==m*pow(m*m,n)
    time complexity << O(n)
*/
long power(int m,int n){
    if(n==0) return 1;
    if(n%2==0) return power(m*m,n/2);
    else return m*power(m*m,n/2);
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<power(m,n)<<endl;
    return 0;
}

