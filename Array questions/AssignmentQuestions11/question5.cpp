bool binarySearch(vector<int> arr, int x)
{
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = r - ((r - l) / 2);

        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;
    for (int i = 0; i < nums2.size(); i++)
    {
        if (i > 0 && nums2[i] == nums2[i - 1])
            continue;
        if (binarySearch(nums1, nums2[i]) && (ans.size() == 0 || ans.back() != nums2[i]))
        {
            ans.push_back(nums2[i]);
        }
    }
    return ans;
}