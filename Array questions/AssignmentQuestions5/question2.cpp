int arrangeCoins(int n)
{
    // brute force
    // int rows = 1;
    // while(n > 0) {
    //     rows++;
    //     n -= rows;
    // }
    // return rows - 1;

    int left = 1, right = n;
    // corner case
    if (n == 1)
        return 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int coinsNeeds = mid * (mid + 1) / 2;
        if (coinsNeeds == n)
            return mid;
        else if (coinsNeeds > n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}