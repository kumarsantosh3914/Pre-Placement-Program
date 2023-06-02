int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto a : nums)
    {
        ans = ans ^ a;
    }
    return ans;
}