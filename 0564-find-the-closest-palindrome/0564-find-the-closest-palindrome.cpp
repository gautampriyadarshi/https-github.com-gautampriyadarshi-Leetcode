class Solution {
    long long generatePalindrome(long long leftHalf, bool isEvenLength) 
    {
        long long palindrome = leftHalf;
        if (!isEvenLength) 
            leftHalf /= 10;

        while (leftHalf > 0) 
        {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
public:
    string nearestPalindromic(string numberStr) 
    {
        long long number = stoll(numberStr);
        if (number <= 10) 
            return to_string(number - 1);

        if (number == 11) 
            return "9";

        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindrome(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindrome(leftHalf, length % 2 == 0);
        palindromeCandidates[2] = generatePalindrome(leftHalf + 1, length % 2 == 0);
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;

        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;

        for (long long candidate : palindromeCandidates) 
        {
            if (candidate == number) 
                continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) 
            {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }
        return to_string(nearestPalindrome);
    }
};