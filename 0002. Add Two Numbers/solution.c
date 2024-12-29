#include <cstddef>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum;
    int carryover = 0;
    struct ListNode* l1head = malloc(sizeof(struct ListNode));
    l1head->next = NULL;
    l1head->val = 0;
    struct ListNode* ptr = l1head;
    while (l1 != NULL || l2 != NULL || carryover != 0) {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carryover;
        if (sum > 9) carryover = 1;
        else carryover = 0;

        struct ListNode* nextNode = malloc(sizeof(struct ListNode));
        nextNode->next = NULL;
        nextNode->val = sum % 10;
        ptr->next = nextNode;

        ptr = ptr->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    struct ListNode* l1newhead = l1head->next;
    free(l1head);
    return l1newhead;
}