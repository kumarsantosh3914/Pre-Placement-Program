vector<int> findOriginalArray(vector<int> &changed)
{
    unordered_map<int, int> mp;
    sort(changed.begin(), changed.end());
    for (int it : changed)
    {
        mp[it]++;
    }

    vector<int> ans;
    for (int i = 0; i < changed.size(); i++)
    {
        if (mp[changed[i]] == 0)
            continue;
        mp[changed[i]]--;
        if (mp[2 * changed[i]])
        {
            ans.push_back(changed[i]);
            mp[2 * changed[i]]--;
        }
        else
        {
            vector<int> dummy;
            return dummy;
        }
    }
    return ans;
}