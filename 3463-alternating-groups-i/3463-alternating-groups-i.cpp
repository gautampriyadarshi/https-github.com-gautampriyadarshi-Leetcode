class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& color) 
    {
        int count = 0, n = color.size();
        for(int i = 0; i < n; i++)
        {
            int pr = color[(i+n-1) % n];
            int nx = color[(i+1) % n];

            if(pr == nx && color[i] != pr && color[i] != nx)
                count++;
        }
        return count;
    }  
};