
void helper(string &ds, string &str, vector<string> &ans, int freq[])
{
    if (ds.size() == str.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(str[i]);
            freq[i] = 1;
            helper(ds, str, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<string> permute(string str)
{
    vector<string> ans;
    string ds;
    int freq[str.size()];
    for (int i = 0; i < str.size(); i++)
        freq[i] = 0;
    helper(ds, str, ans, freq);
    return ans;
}