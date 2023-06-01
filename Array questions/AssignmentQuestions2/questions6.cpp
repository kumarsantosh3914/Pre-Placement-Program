int bs(int start, int end, vector<int> &nums, int target)
{
    // base case
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    if (nums[mid] < target)
        return bs(start + 1, end, nums, target);
    return bs(start, end - 1, nums, target);
}

int search(vector<int> &nums, int target)
{
    return bs(0, nums.size() - 1, nums, target);
}