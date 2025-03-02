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

void infixToPostfix(string s){

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
      while(!st.empty() and check_precidence(s[i]) <= check_precidence(st.top())){
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

  cout << "Prefix expression: " << ans << endl;

}

int main(){
string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}