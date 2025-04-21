#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    stack<char> parentheses;
    for(char& i : s){
        if(i == '(') parentheses.push('(');
        else{
            if(parentheses.empty()) return false;
            if(parentheses.top() == '(') parentheses.pop();
        }
    }
    if(parentheses.empty()) return true;
    else return false;

}