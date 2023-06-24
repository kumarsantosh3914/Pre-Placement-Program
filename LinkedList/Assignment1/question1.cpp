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

Node *merge_linked_lists(Node *list1, Node *list2)
{
    Node *result_head = NULL;
    Node *result_tail = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        Node *new_node;
        if (list1->info >= list2->info)
        {
            new_node = new Node(list1->info);
            list1 = list1->next;
        }
        else
        {
            new_node = new Node(list2->info);
            list2 = list2->next;
        }
        if (result_head == NULL)
        {
            result_head = new_node;
            result_tail = new_node;
        }
        else
        {
            result_tail->next = new_node;
            result_tail = new_node;
        }
    }
    while (list1 != NULL)
    {
        Node *new_node = new Node(list1->info);
        list1 = list1->next;

        if (result_head == NULL)
        {
            result_head = new_node;
            result_tail = new_node;
        }
        else
        {
            result_tail->next = new_node;
            result_tail = new_node;
        }
    }
    while (list2 != NULL)
    {
        Node *new_node = new Node(list2->info);
        list2 = list2->next;

        if (result_head == NULL)
        {
            result_head = new_node;
            result_tail = new_node;
        }
        else
        {
            result_tail->next = new_node;
            result_tail = new_node;
        }
    }

    return result_head;
}
