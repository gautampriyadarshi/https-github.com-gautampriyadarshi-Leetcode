#include<stack>
class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(s[i]);
            else
            {
                if(s[i] == ')' && ( st.empty() || st.top() != '('))
                    st.push(s[i]);
                else
                    st.pop();
            }
        }
        return st.size();
    }
};