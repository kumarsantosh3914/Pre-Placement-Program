bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    int ind = 0, on = 0;
    while (ind < 32)
    {
        if (n & 1)
            on++;
        if (on > 1)
            return false;
        n >>= 1;
        ind++;
    }
    return true;
}