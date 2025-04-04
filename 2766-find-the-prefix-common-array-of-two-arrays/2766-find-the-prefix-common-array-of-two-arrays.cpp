class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        vector<int> ans;
        int count = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < A.size(); i++)
        {
            mp[A[i]]++;
            if(mp[A[i]] == 2)
                count++;
            
            mp[B[i]]++;
            if(mp[B[i]] == 2)
                count++;

            ans.push_back(count);
        }
        return ans;
    }
};