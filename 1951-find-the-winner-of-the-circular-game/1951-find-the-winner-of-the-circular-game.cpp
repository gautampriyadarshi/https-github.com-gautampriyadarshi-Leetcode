class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        vector<int> vec;
        for(int i = 1; i <= n; i++)
        {
            vec.push_back(i);
        }

    /*  int totalLeft = n, count = 0, ans = -1;;
        while(totalLeft > 1)
        {
            int i;
            for(i = 1; i <= n && totalLeft > 1; i++)
            {
                if(vec[i] != 0)
                    count++;

                if(count == k)
                {
                    vec[i] = 0;
                    count = 0;
                    totalLeft--;
                }

                if(i == n)  break;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(vec[i] != 0)
                ans = i;
        }   */

        int ptr = 0;
        while (vec.size() > 1) 
        {
            ptr = (ptr + k - 1) % vec.size();
            vec.erase(vec.begin() + ptr);
        }
        return vec[0];
    }
};