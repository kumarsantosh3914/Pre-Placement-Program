void nonZeros(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            nums[i++] = nums[j];
        }
    }
    for (; i < n; i++)
    {
        nums[i] = 0;
    }
}