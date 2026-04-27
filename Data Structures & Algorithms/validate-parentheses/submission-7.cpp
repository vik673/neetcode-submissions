class Solution {
public:
    bool isValid(string s) {
       if(s[0] == '}' || s[0] == ']' || s[0] == ')')
         return false;
        int i=0;
        stack<char> st;
         while(i<s.size())
         {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(st.empty()) 
                   return false;
            else if((s[i] == '}' && st.top() != '{')
            || (s[i] == ']' && st.top() != '[')
            || (s[i] == ')' && st.top() != '('))
            {
                
               return false;
            }
            else
            {
                st.pop();
            }
            i++;
         }
         return st.empty();
    }
};
