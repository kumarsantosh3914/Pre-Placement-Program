
void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        int prev = ind;
        for (int i = ind + 1; i < n; i++)
        {
            if (nums[i] > nums[ind - 1] && nums[i] <= nums[prev])
            {
                prev = i;
            }
        }
        swap(nums[ind - 1], nums[prev]);
        reverse(nums.begin() + ind, nums.end());
    }
}
