void insert(stack<int> &st, int t)
{
    if (st.empty())
    {
        st.push(t);
        return;
    }
    int x = st.top();
    st.pop();
    insert(st, t);
    st.push(x);
}
void solve(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int t = st.top();
    st.pop();
    solve(st);
    insert(st, t);
}
void Reverse(stack<int> &St)
{
    if (St.empty())
    {
        return;
    }
    solve(St);
}