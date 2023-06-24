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

Node *reverse_alternate_k_nodes(Node *head, int k)
{
    if (head == NULL || k == 1)
    {
        return head;
    }

    int count = 0;
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL && count < k)
    {
        next = current->next;
        if (count % 2 == 1)
        {
            current->next = prev;
            prev = current;
            current = next;
        }
        else
        {
            prev = current;
            current = next;
        }

        count += 1;
    }
    if (next != NULL)
    {
        head->next = reverse_alternate_k_nodes(next, k);
    }

    return prev;
}
