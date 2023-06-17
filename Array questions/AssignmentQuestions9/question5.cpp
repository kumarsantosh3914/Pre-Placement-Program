int findMaximum(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    // base case
    if (low == high)
    {
        return nums[low];
    }
    else
    {
        int mid = (left + right) / 2;
        return max(findMaximum(arr, left, mid), findMaximum(arr, mid + 1, right));
    }
}