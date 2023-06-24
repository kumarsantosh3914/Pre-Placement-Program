int pre = 1;
Node *addOne(Node *head, int i = 0)
{
    if (head == NULL)
    {
        return NULL;
    }
    addOne(head->next, i + 1);
    head->data += pre;
    if (head->data >= 10 && i != 0)
    {
        pre = 1;
        head->data %= 10;
    }
    else if (head->data < 10)
    {
        pre = 0;
    }
    return head;
}