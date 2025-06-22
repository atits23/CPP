//inflix to postfix
#include<bits/stdc++.h>
using namespace std;

int prio(char op){
    if(op=='+'|| op=='-'){
        return 1;
    }
    else if(op=='*'|| op=='/'){
        return 2;
    }
    else if(op=='^'){
        return 3;
    }
    else{
        return -1;
    }

}


int main(){
    string s="a+b*(c^d-e)";
    stack<char> st;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z' ||s[i]>='a' && s[i]<='z'){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
                while(!st.empty() && prio(s[i])<=prio(st.top())){
                ans+=st.top();
                st.pop();
                }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<"The resustant string is:-"<<ans;
    return 0;
}
//postfix to prefix operator top 2 top1
//prefix to postfix top1 top2 operator
//postfix to infix if counters operator put (top2 operator top1) around 