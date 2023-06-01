int findLHS(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int start = 0, end = 1;
    int ans = 0;
    while (end < nums.size())
    {
        int diff = nums[end] - nums[start];
        if (diff == 1)
        {
            ans = max(ans, end - start + 1);
        }
        if (diff <= 1)
            end++;
        else
            start++;
    }
    return ans;
}