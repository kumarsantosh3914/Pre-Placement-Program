int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;