class Solution {
    static bool comp(int a, int b)
    {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        return x == y ? a < b : x < y;
    }
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};