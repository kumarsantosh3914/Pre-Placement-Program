struct node *reverse(struct node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    // step 1: reverse first k nodes
    struct node *next = NULL;
    struct node *curr = head;
    struct node *prev = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    // step2: Recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    // step 3: return krdo head ko
    return prev;
}