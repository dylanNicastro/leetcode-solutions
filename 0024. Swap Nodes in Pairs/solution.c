#include <cstddef>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* ptr = head;
    struct ListNode* secondPtr;
    struct ListNode* nextInLine;
    while (ptr != NULL) {
        if (ptr->next == NULL) break; // no pair
        secondPtr = ptr->next;
        if (head == ptr) head = secondPtr;
        ptr->next = secondPtr->next;
        if (ptr->next != NULL && ptr->next->next != NULL) ptr->next = ptr->next->next;
        nextInLine = secondPtr->next;
        secondPtr->next = ptr;

        ptr = nextInLine;
    }
    return head;
}