void QueueStack ::push(int x)
{
    if (q1.empty() && q2.empty())
    {
        q1.push(x);
    }
    else if (q1.empty() && !q2.empty())
    {
        q2.push(x);
    }
    else
    {
        q1.push(x);
    }
}

int QueueStack ::pop()
{
    if (q1.empty() == false)
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    else if (q2.empty() == false)
    {
        while (q2.size() != 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        int x = q2.front();
        q2.pop();
        return x;
    }
    else
    {
        return -1;
    }
}