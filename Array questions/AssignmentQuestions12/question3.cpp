int getNthFromLast(Node *head, int n)
{

    Node *p1 = head;
    Node *p2 = head;
    if (head == NULL)
    {
        return -1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        p2 = p2->next;
        if (p2 == NULL)
        {
            return -1;
        }
    }

    while (p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1->data;
}