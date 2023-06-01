int smallestRangeI(vector<int> &nums, int k)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int mini = *min_element(nums.begin(), nums.end());
    return max(0, maxi - k - mini - k);
}