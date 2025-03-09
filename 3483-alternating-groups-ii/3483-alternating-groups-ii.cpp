class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int window = 1, n = colors.size(), count = 0;
        for(int i = 0; i < n+k-2; i++)
        {
            if(colors[i % n] != colors[(i+1) % n])
            {
                window++;
                if(window >= k)
                    count++;
            }
            else
                window = 1;
        }
        return count;
    }
};