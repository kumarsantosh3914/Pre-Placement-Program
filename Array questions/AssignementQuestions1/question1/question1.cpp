#include <bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> targetSum(vector<int> &nums, int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

// optimal approach
vector<int> targetSum1(vector<int> &nums, int target, int n)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({nums[i], i});
    }

    sort(vec.begin(), vec.end());
    vector<int> ans;
    int i = 0, j = vec.size() - 1;
    while (i < j)
    {
        if (vec[i].first + vec[j].first == target)
        {
            ans.push_back(vec[i].second);
            ans.push_back(vec[j].second);
            return ans;
        }
        else if (vec[i].first + vec[j].first > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = targetSum(nums, target, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
