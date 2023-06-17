void solve(vector<string> &nums, vector<string> &output, int index, vector<vector<string>> &ans)
{
    // Base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(nums, output, index + 1, ans);

    // Include
    string element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);

    // Backtrack
    output.pop_back();
}

vector<vector<string>> subsets(vector<string> &nums)
{
    vector<vector<string>> ans;
    vector<string> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}