// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
    string A=" stone";
    string B=" longest";
    int **Table=new int*[A.length()];
    for(int i=0;i<A.length();i++){
      Table[i]=new int[B.length()];
      for(int j=0;j<B.length();j++){
        Table[i][j]=0;
      }
    }
    for(int i=1;i<A.length();i++){
        for(int j=1;j<B.length();j++){
          if(A[i]==B[j]){
            Table[i][j]=1+Table[i-1][j-1];
          }
          else{
            Table[i][j]=Table[i-1][j]>Table[i][j-1]?Table[i-1][j]:Table[i][j-1];
          }
        }
    }
    for(int i=0;i<A.length();i++){
        for(int j=0;j<B.length();j++){
            cout<<Table[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=A.length()-1;int j=B.length()-1;
    stack <int>s;

    while(Table[i][j]){
      if(Table[i][j-1]!=Table[i][j] && Table[i-1][j]!=Table[i][j]){
        s.push(j);i--;j--;
      }
      else if(Table[i][j-1]==Table[i][j]){
        j--;
      }
      else if(Table[i-1][j]==Table[i][j]){
        i--;
      }
    }
    while(!s.empty()){
      cout<<B[s.top()];
      s.pop();
    }
    cout<<endl;
    for(int i=0;i<A.length();i++){
      delete []Table[i];
    }
    delete []Table;
    return 0;
}
