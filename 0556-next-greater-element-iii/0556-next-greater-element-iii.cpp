class Solution {
public:
    int nextGreaterElement(int n) 
    {
        // vector<int> num;
        // int help = n, rev = 0;
        // while(help > 0)
        // {
        //     rev = help % 10;
        //     num.push_back(rev);
        //     help = help / 10;
        // }
        // //cout << num[0] << " " << num[1] << endl;

        // int ans = 0, x = 1;
        // sort(num.begin(), num.end());
        // for(int i = 0; i < num.size(); i++)
        // {
            
        //     ans = ans + num[i]*x;
        //     x = x*10;
        // }
        
        // //cout << ans;
        // if(ans > n)
        //     return ans;
        
        // return -1;

        string s = to_string(n);
        next_permutation(s.begin(), s.end());

        long long t;
        t = stol(s);

        if(t > INT_MAX or t <= n)
            return -1;
            
        return t;   
    }
};