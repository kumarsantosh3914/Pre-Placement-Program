int power(int n, int p)
{
    int ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans *= n;
    }
    return ans;
}