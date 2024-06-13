class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        int count = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int j = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            count += abs(seats[i] - students[j]);
            j++;
        }
        return count;
    }
};