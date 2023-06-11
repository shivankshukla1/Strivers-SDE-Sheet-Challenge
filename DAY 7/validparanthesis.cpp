bool isValidParenthesis(string s)
{
    stack<char> st;
    for (auto i : s) {
      if (i == '(' || i == '[' || i == '{'){
          st.push(i);
      }else if(i == ')'){
          if(st.size() && st.top() == '('){
              st.pop();
          } else {
            return 0;
          }
      } else if (i == '}') {
        if (st.size() && st.top() == '{') {
          st.pop();
        }else{
            return 0;
        }
      } else if (i == ']') {
        if (st.size() && st.top() == '[') {
          st.pop();
        }else{
            return 0;
        }
      }
    }
    return st.size() == 0;
}