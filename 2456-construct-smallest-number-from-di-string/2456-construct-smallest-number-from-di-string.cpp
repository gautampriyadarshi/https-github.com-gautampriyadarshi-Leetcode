class Solution {
public:
    string smallestNumber(string pattern) 
    {
        string ans = "";
        stack<char> st;
        int n = pattern.size()+1;
        for(int i = 1; i <= n; ++i)
        {
            st.push(i + '0');
            cout << i + '0' << " ";
            if(i == n || pattern[i-1] == 'I')
            {
                while(!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};