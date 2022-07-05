// striver SDE sheet challange valid-parenthesis
// author Vishwas Paikra
#include<bits/stdc++.h>
bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(char c : expression) {
        if(c == '{' || c == '(' || c == '[')
            st.push(c);
        else if(!st.empty() && ((st.top() == '{' && c == '}') || 
                (st.top() == '(' && c == ')') ||
                (st.top() == '[' && c == ']')))
            st.pop();
        else return false;
    }
    return st.size() == 0;
}
