struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteMiddleNode(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
}
