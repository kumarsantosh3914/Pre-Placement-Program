bool duplicate(vector<int> &nums)
{
    unordered_set<int> st;
    for (auto &it : nums)
    {
        st.insert(it);
    }
    if (nums.size() == st.size())
        return false;
    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool ans = duplicate(nums);
    cout << ans;
    return 0;
}