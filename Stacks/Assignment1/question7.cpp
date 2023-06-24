
stack<int> st, minSt;

MinStack()
{
}

void push(int val)
{
    if (minSt.empty() || val <= minSt.top())
    {
        minSt.push(val);
    }
    st.push(val);
}

void pop()
{
    if (st.top() == minSt.top())
    {
        minSt.pop();
    }
    st.pop();
}

int top()
{
    return st.top();
}

int getMin()
{
    return minSt.top();
}