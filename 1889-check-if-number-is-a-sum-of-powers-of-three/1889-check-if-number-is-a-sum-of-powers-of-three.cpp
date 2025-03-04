class Solution {
    /*
    bool solve(int i, int n, vector<long long> vec)
    {
        if(i == 15)
            return n == 0;
        
        if(n == 0)
            return true;
        
        bool select = false, notSelect = false;

        select = solve(i+1, n - vec[i], vec);
        notSelect = solve(i+1, n, vec);

        return (select || notSelect ); 
    }   */
public:
    bool checkPowersOfThree(int n) 
    {
        /*
        // 128/129 case passed then TLE.
        vector<long long> vec;
        for(int i = 0; i <= 14; i++)
        {
            long long num = pow(3,i);
            vec.push_back(num);
        }

        return solve(0, n, vec);    */

        while (n > 0) 
        {
            if (n % 3 == 2) 
                return false;

            n /= 3;
        }
        return true;
    }
};