#define llt long long int
llt binarySearch(int n)
{
    int left = 0, right = n;
    llt mid = left + (right - left) / 2;
    llt ans = -1;
    while (left <= right)
    {
        llt squre = mid * mid;
        if (squre == n)
            return mid;
        else if (squre < n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    return ans;
}

int mySqrt(int x)
{
    return binarySearch(x);
}
