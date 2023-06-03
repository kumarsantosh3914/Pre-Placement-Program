void mergeArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int size = (m + n - 1);
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[size--] = nums1[i--];
        }
        else
        {
            nums1[size--] = nums2[j--];
        }
    }
    while (i >= 0)
    {
        nums1[size--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[size--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 6;
    int n = 3;
    mergeArray(nums1, m, nums2, n);
    return 0;
}