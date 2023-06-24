int getLength(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode *rotateRight(ListNode *head, int k)
{
    int n = getLength(head);

    // base case
    if (head == NULL || head->next == NULL || k == 0 || k % n == 0)
        return head;

    // update k
    k = k % n;

    int t = n - k;

    ListNode *prev = NULL;
    ListNode *curr = head;
    while (t--)
    {
        prev = curr;
        curr = curr->next;
    }
    // steps:2
    prev->next = NULL;
    // steps3:
    ListNode *tail = curr;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    // step:4
    return curr;
}