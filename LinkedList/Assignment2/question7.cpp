struct node
{
    int val;
    int index;
};
vector<int> nextLargerNodes(ListNode *head)
{
    if (head == nullptr)
        return {0};

    int n = 0;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        curr = curr->next;
        n++;
    }

    vector<int> result(n, 0);
    stack<node> s;
    curr = head;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().val < curr->val)
        {
            result[s.top().index] = curr->val;
            s.pop();
        }
        s.push({curr->val, i});
        curr = curr->next;
    }
    return result;
}