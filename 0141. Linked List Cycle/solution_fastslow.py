# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return False
        ptr1 = head
        ptr2 = head.next
        while ptr1 is not ptr2:
            if not ptr1.next or not ptr2:
                return False
            ptr1 = ptr1.next
            if not ptr2.next:
                return False
            ptr2 = ptr2.next.next
        return True
        