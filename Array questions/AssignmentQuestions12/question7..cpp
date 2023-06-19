struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *lastNodeList1 = list1;
    while (lastNodeList1->next)
    {
        lastNodeList1 = lastNodeList1->next;
    }
    ListNode *firstNodeList2 = list2;

    ListNode *lastNodeList2 = list2;
    while (lastNodeList2->next)
    {
        lastNodeList2 = lastNodeList2->next;
    }
    lastNodeList1->next = firstNodeList2;

    ListNode *nodeAfterInsertion = list1;
    for (int i = 0; i < b + 1; i++)
    {
        nodeAfterInsertion = nodeAfterInsertion->next;
    }
    lastNodeList2->next = nodeAfterInsertion;

    return list1;
}
