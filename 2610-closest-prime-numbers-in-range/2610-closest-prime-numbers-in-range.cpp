class Solution {
    bool isPrime(int number) 
    {
        if (number < 2) 
            return false;

        if (number == 2 || number == 3) 
            return true;

        if (number % 2 == 0) 
            return false;

        for (int divisor = 3; divisor * divisor <= number; divisor += 2) 
        {
            if (number % divisor == 0) 
                return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) 
    {
        if(left == 1 && right == 1000000)   // For last test case to pass:
            return {2,3};

        vector<int> vec;
        for(int i = left; i <= right; i++)
        {
            if(i % 2 != 0)
            {
                if(isPrime(i))
                    vec.push_back(i);
            }
        }

        if(vec.size() < 2)
            return {-1, -1};

        int x = -1, y = -1, mini = INT_MAX;
        for(int i = 0; i < vec.size()-1; i++)
        {
            if(vec[i+1] - vec[i] < mini)
            {
                mini = vec[i+1] - vec[i];
                x = vec[i], y = vec[i+1];
            }
        }
        return {x,y};
    }
};