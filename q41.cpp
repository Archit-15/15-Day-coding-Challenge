#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int match(char a,char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;
}

int parenthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();++i){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        if(s[i] == '}' || s[i]==')' || s[i]==']'){
            char popped_ch;
            if(st.empty()){
                return 0;
            } 
            popped_ch = st.top();
            st.pop();
            if(!match(popped_ch,s[i])){
                return 0;
            }
        }
    }
    if(st.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    string s = "()[]{}";
    if(parenthesis(s)){
        cout<<"Parenthesis matched";
    }
    else{
        cout<<"Parenthesis not matched";
    }
    return 0;
}