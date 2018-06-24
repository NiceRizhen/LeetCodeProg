/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1==NULL&&l2==NULL) return NULL;
    if(l1==NULL&&l2!=NULL) return l2;
    if(l1!=NULL&&l2==NULL) return l1;
    
    
    
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *head = NULL;
    
    if(l1->val <= l2->val){
        head = l1;
        p1 = p1->next;
    }
    else 
    {
        head = l2;
        p2 = p2->next;
    }
    
    struct ListNode *p = head;
    
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->val <= p2->val)
        {
            p->next = p1;
            p = p->next;
            p1=p1->next;
        }
        else
        {
            p->next = p2;
            p = p->next;
            p2=p2->next;
        }
    }
    
    if(p1==NULL&&p2==NULL) return head;
    if(p1==NULL&&p2!=NULL) p->next = p2;
    if(p1!=NULL&&p2==NULL) p->next = p1;
    
    return head;
    
}