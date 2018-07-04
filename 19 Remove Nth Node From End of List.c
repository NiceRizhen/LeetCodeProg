/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode *p = head, *q = head;
    
    for(int i = 0; i < n; i++)
    {
        if(q->next) q = q->next;
        else return head->next;
    }

    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = p->next->next;
    return head;
}