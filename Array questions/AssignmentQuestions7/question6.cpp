bool rotateString(string A, string B)
{
    if (A.length() != B.length())
        return 0;
    int n = A.length();
    if (n == 0)
        return 1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n && A[(i + j) % n] == B[j])
            j++;
        if (j == n)
            return 1;
    }
    return 0;
}