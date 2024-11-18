class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        vector<int> ans;
        int n = code.size();

        if(k == 0)
        {
            for(int i = 0; i < n; i++)
            {
                ans.push_back(0);
            }
            return ans;
        }
        else if(k > 0)
        {
            int i = 0;
            while(i < n)
            {
                int j = i+1, cnt = 0, sum = 0;
                while(cnt < k)
                {
                    if(j == n)
                        j = 0;

                    sum += code[j];
                    j++;
                    cnt++;
                }
                i++;
                ans.push_back(sum);
            }
            return ans;
        }
        else
        {
            int  i = 0;
            while(i < n)
            {
                int j = i-1, cnt = 0, sum = 0, kpos = -1*(k);

                if(i == 0) 
                    j = n-1;

                while(cnt < kpos)
                {
                    if(j == -1)
                        j = n-1;
                    sum += code[j];
                    j--;
                    cnt++;
                } 
                i++;
                ans.push_back(sum);
            }
            return ans;
        }
        return ans;
    }
};