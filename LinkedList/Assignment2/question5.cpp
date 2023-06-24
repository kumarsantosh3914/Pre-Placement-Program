ListNode *oddEvenList(ListNode *head)
{
    // base case
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    ListNode *odd = head;
    ListNode *even = odd->next;
    ListNode *evenHead = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}