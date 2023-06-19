void linkdelete(struct Node *head, int M, int N)
{
    Node *curr = head;
    int count = 0;
    while (curr && curr->next)
    {
        // skipping
        count++;
        int node = N;
        if (M == count)
        {
            // regenrate.
            count = 0;
            while (node && curr && curr->next)
            {
                curr->next = curr->next->next;
                node--;
            }
        }
        curr = curr->next;
    }
}