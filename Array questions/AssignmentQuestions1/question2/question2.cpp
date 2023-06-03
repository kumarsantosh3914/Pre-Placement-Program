#include <bits/stdc++.h>
using namespace std;

int removalElement(vector<int> &nums, int val, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}

int main()
{
    int n = 4;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << removalElement(nums, val, n);
    return 0;
}