vector<int> leftSmaller(int n, int a[])
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(a[i]);
        }
        else
        {
            while (!st.empty() and st.top() >= a[i])
                st.pop();
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(a[i]);
        }
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}