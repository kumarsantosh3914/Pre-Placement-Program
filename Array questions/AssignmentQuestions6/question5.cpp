int minProductSum(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), greater<int>());
    int i = 0, j = nums1.size() - 1;
    int ans = 0;
    while (i < nums.size() && j >= 0)
    {
        ans = nums1[i] * nums2[j];
        i++;
        j--;
    }
    return ans;
}
