class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size(), i = 1, count = 0;
        vector<int> ans(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int ind = st.top();
                st.pop();
                ans[ind] = i - ind; 
            }
            st.push(i);
        }

        return ans;
    }
};