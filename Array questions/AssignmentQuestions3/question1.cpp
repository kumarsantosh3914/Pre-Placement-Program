int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int ans, min_diff = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                return sum;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
            if (abs(sum - target) < min_diff)
            {
                min_diff = abs(sum - target);
                ans = sum;
            }
        }
    }
    return ans;
}