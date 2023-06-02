string getRange(long long n1, long long n2)
{
    if (n1 == n2)
    {
        return to_string(n1);
    }
    else
    {
        return to_string(n1) + "->" + to_string(n2);
    }
}

vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
{
    vector<string> res;
    long long next = lower;

    for (int i = 0; i < nums.size(); i++)
    {
        if (lower == INT_MAX)
            return res;
        if (nums[i] < next)
        {
            continue;
        }

        if (nums[i] == next)
        {
            next++;
            continue;
        }

        res.push_back(getRange(next, (long long)nums[i] - 1));
        if (nums[i] == INT_MAX)
            return res;
        next = (long long)nums[i] + 1;
    }

    if (next <= upper)
    {
        res.push_back(getRange(next, (long long)upper));
    }

    return res;
}
