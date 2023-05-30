vector<int> digits(vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i] += 1;
            return digits;
        }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}

int main()
{
    vector<int> nums = {9, 9, 9, 9};
    vector<int> ans = digits(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}