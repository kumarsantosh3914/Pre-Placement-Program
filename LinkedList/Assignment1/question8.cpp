Node *deleteNode(Node *head, int x)
{
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    Node *curr = head;
    for (int i = 1; i < x - 1; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    if (curr->next->next != NULL)
    {
        curr->next = curr->next->next;
        temp->next->prev = curr;
    }
    else
        curr->next = NULL;

    delete (temp);
    return head;
}