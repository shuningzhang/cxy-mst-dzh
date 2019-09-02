#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i = 0;
    struct ListNode* pre = NULL;
    struct ListNode* back = NULL;
    struct ListNode* pre_back = NULL;
    
    pre = head;
    for (i=0; i<n-1 && pre; i++) {
        pre = pre->next;
    }
    
    if (pre == NULL) {
        return NULL;
    }
    
    back = head;
    while (pre->next) {
        pre_back = back;
        back = back->next;
        pre = pre->next;
    }
    
    if (back->next) {   
        back->val = back->next->val;
        back->next = back->next->next;
    } else {
        if (pre_back) {
            pre_back->next = NULL;            
        } else {
            return NULL;
        }
        
    }
    
    return head;
}



int main()
{
	struct ListNode l1;
	struct ListNode l2;
	struct ListNode l3;
	struct ListNode l4;
	struct ListNode l5;

	l1.val = 1;
	l1.next = &l2;
	
	l2.val = 2;
	l2.next = &l3;

	l3.val = 3;
	l3.next = &l4;

	l4.val = 4;
	l4.next = &l5;

	l5.val = 5;
	l5.next = NULL;	

	removeNthFromEnd(&l1, 2);
}
