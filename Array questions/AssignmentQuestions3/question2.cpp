vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target_2 = target - nums[i] - nums[j];
            int front = j + 1, back = n - 1;
            while (front < back)
            {
                int two_sum = nums[front] + nums[back];
                if (two_sum < target_2)
                    front++;
                else if (two_sum > target_2)
                    back--;
                else
                {
                    vector<int> quadrant(4, 0);
                    quadrant[0] = nums[i];
                    quadrant[1] = nums[j];
                    quadrant[2] = nums[front];
                    quadrant[3] = nums[back];
                    ans.push_back(quadrant);
                    while (front < back && nums[front] == quadrant[2])
                        front++;
                    while (front < back && nums[back] == quadrant[3])
                        back--;
                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }
    return ans;
}
