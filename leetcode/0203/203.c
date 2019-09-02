#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* pre = NULL;
    struct ListNode* cur = NULL;
    
    cur = head;
    while (cur) {
        if (cur->val == val) {
            if (cur->next) {
                cur->val = cur->next->val;
                cur->next = cur->next->next;
            } else if (!cur->next && pre) {
                pre->next = NULL;
                cur = NULL;
            } else {
                return NULL;
            }
                       
        } else {
            pre = cur;
            cur = cur->next;
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
	struct ListNode l6;
	struct ListNode l7;

	l1.val = 1;
	l1.next = &l2;
	
	l2.val = 2;
	l2.next = &l3;

	l3.val = 6;
	l3.next = &l4;

	l4.val = 3;
	l4.next = &l5;

	l5.val = 4;
	l5.next = &l6;	

	l6.val = 5;
	l6.next = &l7;

	l7.val = 6;
	l7.next = NULL;

	removeElements(&l1, 6);
}
