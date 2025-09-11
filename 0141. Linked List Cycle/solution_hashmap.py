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
        hash = {}
        if not head or not head.next:
            return False
        node = head
        while node:
            if hash.get(node, None):
                return True
            else:
                hash[node] = 1
            node = node.next
        return False