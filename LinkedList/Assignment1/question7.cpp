#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

Node *reverse_doubly_linked_list(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *current = head;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }

    return head;
}

Node *head = new Node(10);
Node *second = new Node(8);
Node *third = new Node(4);
Node *fourth = new Node(2);

head->next = second;
second->prev = head;

second->next = third;
third->prev = second;

third->next = fourth;
fourth->prev = third;
Node *result = reverse_doubly_linked_list(head);
while (result != NULL)
{
    cout << result->data << " ";
    result = result->next;
}