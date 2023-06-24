class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        next = NULL;
    }
};

Node *delete_last_occurrence(Node *head, int key)
{
    if (head == NULL)
    {
        return head;
    }

    Node *last_occurrence = NULL;
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            last_occurrence = current;
        }
        prev = current;
        current = current->next;
    }
    if (last_occurrence == NULL)
    {
        return head;
    }
    if (last_occurrence == head)
    {
        head = head->next;
        return head;
    }
    prev = NULL;
    current = head;
    while (current != NULL && current != last_occurrence)
    {
        prev = current;
        current = current->next;
    }

    if (prev != NULL)
    {
        prev->next = current->next;
    }

    return head;
}
