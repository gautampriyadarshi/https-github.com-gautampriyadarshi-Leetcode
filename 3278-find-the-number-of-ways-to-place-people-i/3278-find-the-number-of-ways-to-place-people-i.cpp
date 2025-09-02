class Solution {
    bool check2(pair<int, int> tl, pair<int, int> br) 
    {
        return tl.first <= br.first && tl.second >= br.second;
    }
    
    bool check(pair<int, int> point, pair<int, int> top_left, pair<int, int> bottom_right) 
    {
        int x = point.first, y = point.second;
        
        int x1 = top_left.first, x2 = bottom_right.first;
        int y1 = top_left.second, y2 = bottom_right.second;
    
        if (!check2(top_left, bottom_right))
            return false;
        
        if (x1 <= x && x <= x2 && y1 >= y && y >= y2) 
            return true;
        else 
            return false;
    }
    
public:
    int numberOfPairs(vector<vector<int>>& v1) 
    {
        vector<vector<int>> v2=v1;
        vector<pair<int,int>> v;

        for(auto it:v1)
        {
            v.push_back({it[0],it[1]});
        }
            
        int n = v.size(), ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;

                if(check2(v[i],v[j]))
                {
                    int temp = 1;
                    for(int k = 0; k < n; k++)
                    {
                        if(k == i || k == j)
                            continue;

                        if(check(v[k],v[i],v[j]) == 1)
                        {
                            temp = 0;
                            break;
                        }
                    }
                    if(temp)
                        ans++;
                }
            }
        }
        return ans;
    }
};