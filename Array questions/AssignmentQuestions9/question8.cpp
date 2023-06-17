int productOfArray(vector<int> &nums)
{
    int ans = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        ans *= i;
    }
    return ans;
}