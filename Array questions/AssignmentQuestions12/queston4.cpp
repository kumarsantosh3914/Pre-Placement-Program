struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode *head)
{
    stack<int> st;
    ListNode *current = head;
    while (current)
    {
        st.push(current->val);
        current = current->next;
    }
    current = head;

    while (current)
    {
        if (current->val != st.top())
        {
            return false;
        }
        st.pop();
        current = current->next;
    }

    return true;
}