vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    vector<vector<int>> res(m, vector<int>(n, 0));

    // this is for impossible case
    if (m * n != original.size())
        return {};

    for (int i = 0; i < original.size(); i++)
    {
        res[i / n][i % n] = original[i];
    }
    return res;
}