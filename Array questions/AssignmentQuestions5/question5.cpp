int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(arr2.begin(), arr2.end());

    int count = 0, low, high;
    for (auto it : arr1)
    {
        low = it - d, high = it + d;
        auto l = lower_bound(arr2.begin(), arr2.end(), low);
        auto h = lower_bound(arr2.begin(), arr2.end(), high);

        if (l == h && (*l != low && *l != high))
            count++;
    }
    return count;
}