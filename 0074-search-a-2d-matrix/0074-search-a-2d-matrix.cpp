class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m*n-1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int midVal = matrix[mid / n][mid % n];

            if(target == midVal)
                return true;
            else if(target > midVal)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};