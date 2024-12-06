class Solution {
public:
    string makeGood(string s) 
    {
        if(s.size() == 1)
            return s;

        stack<char> st;
        string ans = "";

        for (char c : s) 
        {
            if (!st.empty() && abs(c - st.top()) == 32) 
                st.pop();
            else 
                st.push(c);
        }

        while(!st.empty())
        {
            char tp = st.top();
            st.pop();
            ans += tp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};