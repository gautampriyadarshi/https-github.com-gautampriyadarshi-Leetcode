class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans;
        bool isDestroyed = false;
        for(int x: asteroids)
        {
            isDestroyed = false;
            while(!ans.empty() && ans.back() > 0 && x < 0)
            {
                if(ans.back() < -x)
                    ans.pop_back();
                else if(ans.back() == -x)
                {
                    ans.pop_back();
                    isDestroyed = true;
                    break;
                }
                else
                {
                    isDestroyed = true;
                    break;
                }
            }

            if(!isDestroyed)
                ans.push_back(x);
        }

        return ans;
    }
};