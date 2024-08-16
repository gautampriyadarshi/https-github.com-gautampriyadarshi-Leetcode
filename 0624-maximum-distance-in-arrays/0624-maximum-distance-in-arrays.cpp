class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) 
    {
        // Wrong ans: 128/136 passed:
    /*  int mini = INT_MAX, maxi = INT_MIN;
        int k = -1;

        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < arr[i].size(); j++)
            {
                if(arr[i][j] > maxi)
                {
                    maxi = arr[i][j];
                    k = i;
                }
            }
        }

        for(int i = 0; i < arr.size(); i++)
        {
            if(k == i)
                continue;
            
            for(int j = 0; j < arr[i].size(); j++)
            {
                if(arr[i][j] < mini)
                    mini = arr[i][j];
            }
        }

        return abs(maxi - mini);    */

        int smallest = arr[0][0];
        int biggest = arr[0].back();
        int max_distance = 0;

        for (int i = 1; i < arr.size(); ++i) 
        {
            max_distance = max(max_distance, abs(arr[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arr[i][0]));
            smallest = min(smallest, arr[i][0]);
            biggest = max(biggest, arr[i].back());
        }

        return max_distance;
    }
};