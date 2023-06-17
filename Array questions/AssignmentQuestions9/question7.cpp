void permutations(string &s, vector<string> &ans, int idx)
{
    if (idx == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        swap(s[idx], s[i]);
        permutations(s, v, idx + 1);
        swap(s[idx], s[i]);
    }
}

vector<string> findPermutation(string &s)
{
    vector<string> ans;
    int idx = 0;
    permutations(s, v, idx);
    sort(ans.begin(), ans.end());
    return ans;
}