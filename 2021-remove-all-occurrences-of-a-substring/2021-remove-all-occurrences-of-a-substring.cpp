class Solution {
    bool string_match(stack<char> st, string part, int n)
    {
        int i = n-1;
        while(i >= 0)
        {
            if(st.top() != part[i])
                return false;

            i--;
            st.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) 
    {
        int m = s.length(), n = part.length();
        stack<char> st;

        for(int i = 0; i < m; i++)
        {
            st.push(s[i]);
            if(st.size() >= n && string_match(st, part, n) == true)
            {
                for(int j = 0; j < n; j++)
                    st.pop();
            }
        }

        string ans(st.size(),' ');
        int k = st.size()-1;

        while(!st.empty())
        {
            ans[k--] = st.top();
            st.pop();
        }
        return ans;
    }
};