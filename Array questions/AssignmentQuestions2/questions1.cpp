int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxSum = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
        maxSum += nums[i];
    }
    return maxSum;
}