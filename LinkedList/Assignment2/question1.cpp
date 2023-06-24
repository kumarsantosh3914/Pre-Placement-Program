void removeLoop(Node *head)
{
    Node *temp = head;
    map<Node *, bool> m;
    m[temp];
    Node *prev = temp;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
        if (m.find(temp) != m.end())
        {
            prev->next = NULL;
            break;
        }
        else
        {
            m[temp];
        }
    }
}