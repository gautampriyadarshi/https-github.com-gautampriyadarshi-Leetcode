/* My code: Time limit exceeded at 123/200 case
class Solution {
    void solve(string nums, vector<string> &ans, int index, int k)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1, k);

            //Backtracking
            swap(nums[index], nums[j]);
        }
    }
public:
    string getPermutation(int n, int k) 
    {
        int index = 0;
        string nums = "";
        for(int i = 1; i <= n; i++)
        {
            nums += to_string(i);
        }

        vector<string> ans;
        solve(nums, ans, index, k);

        sort(ans.begin(), ans.end());
        
        return ans[k-1];
    }
};  */

class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int fact = 1;
        vector<int> nums;
        for(int i = 1; i < n; i++)
        {
            fact = fact*i;
            nums.push_back(i);
        }

        nums.push_back(n);
        k = k-1;
        string ans="";

        while(true)
        {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);

            if(nums.size() == 0)
                break;
            
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};