int helper(int jump, int start, int n, bool leftToRight)
{
    // base case
    if (n <= 1)
    {
        return start;
    }
    // left to right wala case
    if (leftToRight)
    {
        start += jump;
    }

    else if (n & 1)
    {
        start += jump;
    }
    return helper(jump * 2, start, n / 2, !leftToRight);
}

int lastRemaining(int n)
{
    int jump = 1;
    int start = 1;
    bool leftToRight = true;
    return helper(jump, start, n, leftToRight);
}