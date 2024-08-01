class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int count = 0;
        for(int i = 0; i < details.size(); i++)
        {
            int num = 0, x = 1;
            for(int j = details[i].size()-3; j >= details[i].size()-4; j--)
            {
                num += (details[i][j] - '0')*x;
                x *= 10;
            }

            if(num > 60) 
                count++;
        }
        return count;
    }
};