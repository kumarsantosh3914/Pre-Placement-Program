vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    map<int, bool> mp;
    for (int i = 0; i < n1; i++)
    {
        mp[A[i]] = false;
    }

    for (int i = 0; i < n2; i++)
    {
        if (mp.find(B[i]) != mp.end())
        {
            mp[B[i]] = true;
        }
    }
    vector<int> ans;
    for (int i = 0; i < n3; i++)
    {
        if (mp.find(C[i]) != mp.end())
        {
            if (mp[C[i]] == true)
            {
                ans.push_back(C[i]);
                mp.erase(C[i]);
            }
        }
    }
    return ans;
}