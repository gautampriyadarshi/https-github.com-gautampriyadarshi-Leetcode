#define MOD 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) 
    {
        vector<int> vec1(n, 1), vec2(n, 0);

        int count = 0;
        while(count < k)
        {
            int j = 1;
            vec2[0] = 1;
            for(int i = 1; i < n; i++)
            {
                vec2[i] = ((vec2[i-1] + vec1[j]) % MOD) % MOD;
                j++;
            }

            // for(int i = 0; i < n; i++)
            // {
            //     cout << vec2[i] << " ";
            // }
            // cout << endl;

            // if(count == 4)
            // {
            //     for(int i = 0; i < n; i++)
            //     {
            //         cout << vec1[i] << " ";
            //     }
            //     cout << endl;
            // }

            vec1 = {0};
            for(int i = 0; i < n; i++)
            {
                vec1[i] = vec2[i];
            }

            if(count+1 != k)
                vec2 = {0};

            count++;
        }
        return vec2[n-1];
    }
};