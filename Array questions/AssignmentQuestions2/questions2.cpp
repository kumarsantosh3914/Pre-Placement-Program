int distributeCandies(vector<int> &candyType)
{
    set<int> st;
    for (auto &it : candyType)
    {
        st.insert(it);
    }
    if (st.size() <= candyType.size() / 2)
        return st.size();
    return candyType.size() / 2;
}