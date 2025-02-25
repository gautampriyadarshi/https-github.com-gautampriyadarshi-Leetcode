#define MOD 1000000007;
class Solution {    
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        long long oddcnt = 0, psum = 0;
        for (int num : arr) {
            psum += num;
            oddcnt += psum % 2;
        }
        oddcnt += (arr.size() - oddcnt) * oddcnt;
        return oddcnt % MOD;
    }
};