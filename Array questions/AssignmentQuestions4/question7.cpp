int maxCount(int m, int n, vector<vector<int>> &nums)
{
    int min_row = m;
    int min_col = n;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] < min_row)
            min_row = nums[i][0];
        if (nums[i][1] < min_col)
            min_col = nums[i][1];
    }
    return min_row * min_col;
}