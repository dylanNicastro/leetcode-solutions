#include <cstddef>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode* head = (list1->val > list2->val ? list2 : list1);
    if (head == list1) list1 = list1->next;
    else list2 = list2->next;

    struct ListNode* ptr = head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            ptr->next = list1; 
            list1 = list1->next;
        }
        else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if (list1 != NULL) ptr->next = list1;
    else if (list2 != NULL) ptr->next = list2;

    return head;
}