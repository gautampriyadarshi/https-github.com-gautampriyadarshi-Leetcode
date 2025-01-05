class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        long long int sum = 0;
        for(int i = 0; i < shifts.size(); i++)
        {
            sum += shifts[i];
        }

        int shift;
        for(int i = 0; i < s.size(); i++)
        {
            shift = sum % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
            sum -= shifts[i];
        }
        return s;
    }
};