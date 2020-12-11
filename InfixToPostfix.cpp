#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
bool operand(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
	unordered_map<char,int> in_stack;
	unordered_map<char,int> out_stack;
	in_stack['+']=2;
	in_stack['-']=2;
	in_stack['*']=4;
	in_stack['/']=4;
	in_stack['%']=4;
	in_stack['^']=5;
	in_stack['!']=5;
	in_stack['(']=0;
	out_stack['+']=1;
	out_stack['-']=1;
	out_stack['*']=3;
	out_stack['/']=3;
	out_stack['%']=3;
	out_stack['^']=6;
	out_stack['!']=6;
	out_stack['(']=7;
	out_stack[')']=0;
	string str="(a-b)*(c+d)";
	string postfix="";
	stack<char> s;
	int i=0;
    while(i<str.length()){
        if(operand(str[i])){
            postfix+=str[i];
        }else{
            if(s.empty()) s.push(str[i]);
            else if(in_stack[s.top()]<out_stack[str[i]]) s.push(str[i]);
            else{
                while(!s.empty() && in_stack[s.top()]>=out_stack[str[i]]){
                if(s.top()!='(')
                    postfix+=s.top();
                cout<<postfix<<endl;
                s.pop();
                }if(str[i]!=')') s.push(str[i]);
            }
        }
        i++;
        // cout<<postfix<<endl;
    }while(!s.empty()){
        postfix+=s.top();s.pop();
    }
    cout<<postfix<<endl;
	return 0;
}
