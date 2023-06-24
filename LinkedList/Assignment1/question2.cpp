class Node
{
public:
    int info;
    Node *next;
    Node(int data = 0)
    {
        info = data;
        next = NULL;
    }
};

Node *remove_duplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        if (current->info == current->next->info)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}
