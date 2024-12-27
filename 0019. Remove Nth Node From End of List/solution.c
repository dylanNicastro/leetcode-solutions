#include <cstddef>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head;
    struct ListNode* endPtrCheck = head;
    for (int i = 0; i < n; i++) endPtrCheck = endPtrCheck->next;
    if (endPtrCheck == NULL) return head->next;

    while (endPtrCheck->next != NULL) {
        ptr = ptr->next;
        endPtrCheck = endPtrCheck->next;
    };
    if (ptr->next == NULL) return NULL;

    ptr->next = ptr->next->next;
    return head;
}