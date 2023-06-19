bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }

    return false;
}