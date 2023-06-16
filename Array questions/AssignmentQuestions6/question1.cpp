vector<int> diStringMatch(string &s)
{
    int n = s.length();
    vector<int> perm;
    int start = 0, end = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            perm.push_back(start);
            start++;
        }
        else if (s[i] == 'D')
        {
            perm.push_back(end);
            end--;
        }
    }
    perm.push_back(start);
    return perm;
}