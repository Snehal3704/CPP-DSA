#include<bits/stdc++.h>

using namespace std;

int check_precidence(char c){

  if(c == '^'){
    return 3;
  }

  else if(c == '*' or c== '/'){
    return 2;
  }

  else if (c == '-' or c=='+'){
    return 1;
  }

  else return -1;

}

void infixToPrefix(string s){
    
  reverse(s.begin(),s.end());

  // Step 2: Swap '(' with ')' and vice versa
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') s[i] = ')';
    else if (s[i] == ')') s[i] = '(';
    }
  int n = s.size();

  int i = 0;
  string ans ;
  stack<char> st;

  while( i < n ){

    if((s[i] >= 'A' and s[i] <= 'Z')
    or (s[i] >= 'a' and s[i] <= 'z') 
    or (s[i] >= '0' and s[i] <= '9')){

      ans =ans + s[i];
    }

    else if (s[i] == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.

    else if(s[i] == ')'){
      while(st.top() != '('){
        ans += st.top();
        st.pop();
      }

      st.pop();// poping '('
    }
    //current charecter is operator
    else{
      while(!st.empty() and check_precidence(s[i]) < check_precidence(st.top())){
        ans+=st.top();
        st.pop();
      }
      st.push(s[i]);
    }
    i++;

  }
  
  // Pop all the remaining elements from the stack
  while (!st.empty()) {
  ans += st.top();
  st.pop();
  }

  reverse(ans.begin(),ans.end());
  cout << "Prefix expression: " << ans << endl;

}

int main(){
    string exp = "(A+B)*C-D+F";
  cout << "Infix expression: " << exp << endl;
  infixToPrefix(exp);
  return 0;
}