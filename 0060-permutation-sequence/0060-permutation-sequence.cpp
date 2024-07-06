class Solution {
    void pNext(string& str)
    {
        int idx1 = 0, idx2 = 0, val = -1, n = str.size();
        for(int i = n-2; i >= 0; i--)
        {
            if(str[i] < str[i+1])
            {
                idx1 = i;
                val = i;
                break;
            }
        }

        if(val == -1)
        {
            reverse(str.begin(), str.end());
            return;
        }

        for(int i = n-1; i >= 0; i--)
        {
            if(str[i] > str[idx1])
            {
                idx2 = i;
                break;
            }
        }
        swap(str[idx1], str[idx2]);
        reverse(str.begin() + idx1 + 1, str.end());
    }
public:
    string getPermutation(int n, int k) 
    {
        string str = "";
        for(int i = 1; i <= n; i++)
        {
            str +=  to_string(i);
        }

        for(int i = 0; i < k-1; i++)
        {
            pNext(str);
        }
        return str;
    }
};