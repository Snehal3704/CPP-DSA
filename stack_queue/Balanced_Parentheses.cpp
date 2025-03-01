#include<bits/stdc++.h>

using namespace std;

class Solution {
    stack <char> st;
public:
    bool isValid(string s) {
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else
            {
                if(st.empty()==false)
                {
                char topch = st.top();
                if(topch =='(' and s[i]== ')')
                st.pop();
                else if(topch =='{' and s[i]== '}')//
                st.pop();
                else if(topch =='[' and s[i]== ']')//
                st.pop();
                else
                return false;
                }
                else
                return false;
            }
        }
        return st.empty();

    }
};

int main()
{
    Solution solution;
    string s="()[{}()]";
    if(solution.isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    
    return 0;
}