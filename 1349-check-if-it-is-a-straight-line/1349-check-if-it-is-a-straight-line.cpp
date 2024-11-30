class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) 
    {
        if (co[0][0] == co[1][0])
        {
            for(int i = 2; i < co.size(); i++)
            {
                if (co[i][0] != co[0][0])
                    return false;
            }
            return true;
        }

        sort(co.begin(),co.end());
        double m= (1.0*(co[0][1])-(co[1][1]))/(1.0*(co[0][0])-(co[1][0]));

        for (int i = 2; i < co.size(); i++)
        {
            if (co[i][0] == co[0][0])
                return false;

            double curr_m= (1.0*(co[i][1])-(co[1][1]))/(1.0*(co[i][0])-(co[1][0]));
            if (curr_m != m) 
                return false;
        }
        return true;
    }
};