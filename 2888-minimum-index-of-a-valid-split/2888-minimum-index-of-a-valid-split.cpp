class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        // Giving wrong answer at 227/917
        /*
        if(nums.size() == 1)
            return -1;

        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int maxi = INT_MIN, num = -1, count = 0, index = -1;
        for(auto x: mp)
        {
            if(x.second > maxi)
            {
                maxi = x.second;
                num = x.first;
            }
        }

        if(maxi == nums.size())
            return 0;
        
        bool isPresent = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == num)
            {
                count++;
                if(maxi % 2 == 0)
                {
                    if(count == maxi/2)
                    {
                        index = i;
                        mp[nums[i]] = maxi - count;
                        maxi = maxi - count;
                        break;
                    }
                }
                else 
                {
                    if(count == maxi/2 + 1)
                    {
                        index = i;
                        mp[nums[i]] = maxi - count;
                        maxi = maxi - count;
                        break;
                    }
                }
            }
        }

        for(int i = nums.size()-1; i > index; i--)
        {
            if(mp[nums[i]] == maxi && num != nums[i])
                return -1;
        }
        return index;   */

        unordered_map<int, int> firstMap, secondMap;
        int n = nums.size();
        for (auto& num : nums) 
        {
            secondMap[num]++;
        }

        for (int index = 0; index < n; index++) 
        {
            int num = nums[index];
            secondMap[num]--;
            firstMap[num]++;

            // Check if valid split
            if (firstMap[num] * 2 > index + 1 &&
                secondMap[num] * 2 > n - index - 1) 
                return index;
        }
        return -1;
    }
};