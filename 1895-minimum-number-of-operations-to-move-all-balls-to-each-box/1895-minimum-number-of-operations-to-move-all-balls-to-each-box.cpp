class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int> ans(n,0);

        for(int i = 0; i < boxes.size(); i++)
        {
            int sum = 0;
            for(int j = i+1; j < boxes.size(); j++)
            {
                if(boxes[j] == '1')
                    sum += abs(j-i);
            }

            for(int k = 0; k < i; k++)
            {
                if(boxes[k] == '1')
                    sum += abs(k-i);
            }
            ans[i] = sum;
        }
        return ans;
    }
};