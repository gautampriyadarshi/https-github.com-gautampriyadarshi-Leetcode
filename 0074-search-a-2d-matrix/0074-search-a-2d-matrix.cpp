class Solution {
    bool binarySearch(vector<int> vec, int target, int low, int high)
    {
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(target == vec[mid])
                return true;

            if(target > vec[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++)
        {
            if(binarySearch(matrix[i], target, 0, n-1))
                return true;
        }
        return false;
    }
};