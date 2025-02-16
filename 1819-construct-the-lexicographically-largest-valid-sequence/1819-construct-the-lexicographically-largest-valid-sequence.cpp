class Solution {
    vector<int>res;
    bool helper(int index, vector<int>& visited, vector<int>& ans, int& n)
    {
        if(index >= ans.size())
        {
            res = ans;
            return true;
        }

        if(ans[index] != -1)
            return helper(index+1, visited, ans, n);

        for(int i = n; i > 0; i--)
        {
            if(visited[i]) 
                continue;

            if(i == 1)
            {
                ans[index] = i;
                visited[i] = 1;

                if(helper(index+1, visited, ans, n))
                    return true;

                ans[index] = -1;
                visited[i] = 0;
            }
            else if(index+i < ans.size()  && ans[i+index] == -1)
            {
                ans[index] = i;
                ans[i+index] = i;
                visited[i] = 1;

                if(helper(index+1, visited, ans, n))
                    return true;
    
                ans[index] = -1;
                ans[i+index] = -1;
                visited[i] = 0;
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> ans(2*n-1, -1);
        vector<int> visited(n+1, 0);
        helper(0, visited, ans, n);
        return ans;
    }
};