class Solution {
public:
    string reverseParentheses(string s) 
    {
        string ans = "";
        stack<int> st;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                int start = st.top()+1;
                reverse(s.begin() + start, s.begin() + i);
                st.pop();
            }
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '(' && s[i] != ')')
                ans += s[i];
        }
        return ans;
    }
};