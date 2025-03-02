#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
      string postToInfix(string s) {
          stack<string> st;
          
          for(int i = 0 ; i< s.size() ; i++){
              
              if((s[i] >= 'A' and s[i] <= 'Z')
              or (s[i] >= 'a' and s[i] <= 'z') 
              or (s[i] >= '0' and s[i] <= '9')){
               //converting ther s[i] charecter into string 
              string temp = "";
              temp += s[i];
              st.push(temp);
  
              }
              
              else{
                  
                 string t1 = st.top();
                  st.pop();
                 string t2 = st.top();
                  st.pop();
                  string con = "("+ t1 + s[i] + t2 +")";
                  st.push(con);
                  
              }
          }
          return st.top();
      }
  };


  int main() {
    Solution sol;
    string postfix = "AB+C*D-";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << sol.postToInfix(postfix) << endl;
    return 0;
}  