ListNode *helper(ListNode *head, bool &anychange)
{
    // base case
    if (head == NULL)
    {
        return head;
    }

    ListNode *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->val;
        if (sum == 0)
        {
            break;
        }
        temp = temp->next;
    }

    if (sum == 0)
    {
        anychange = true;
        return temp->next;
    }

    head->next = helper(head->next, anychange);
    return head;
}

ListNode *removeZeroSumSublists(ListNode *head)
{
    while (true)
    {
        bool anychange = false;
        head = helper(head, anychange);
        if (head == NULL || anychange == false)
            break;
    }
    return head;
}