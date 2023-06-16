int findMaxLength(vector<int> &nums)
{
    int maxLen = 0, sum = 0;
    unordered_map<int, int> ump;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] == 0 ? -1 : 1;
        if (sum == 0)
            return maxLen = i + 1;
        if (ump.find(sum) != ump.end())
        {
            maxLen = max(maxLen, i - ump[sum]);
        }
        else
        {
            ump[sum] = i;
        }
    }
    return maxLen;
}