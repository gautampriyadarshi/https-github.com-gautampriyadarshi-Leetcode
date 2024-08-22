#include<bits/stdc++.h>
class Solution {
    string to_binary(int num)
    {
        int x = num;
        string binary = "";

        while(x > 0)
        {
            binary += to_string(x % 2);
            x = x/2; 
        }
        reverse(binary.begin(), binary.end());
        cout << binary << " ";
        return binary;
    }

    string compliment(string &binary)
    {
        for(int i = 0; i < binary.size(); i++)
        {
            if(binary[i] == '0')
                binary[i] = '1';
            else
                binary[i] = '0';
        }
        cout << binary << " ";
        return binary;
    }

    int complement(string comp)
    {
        long long int ans = 0, p = 1;
        int i = comp.size()-1;
        while(i >= 0)
        {
            long long int x = (comp[i] - '0');
            ans += (p * x);
            i--;
            p *= 2;
        }
        return ans;
    }
public:
    int findComplement(int num) 
    {
        string binary = to_binary(num);
        string comp = compliment(binary);

        return complement(comp);
    }
};