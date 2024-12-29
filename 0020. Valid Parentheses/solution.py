class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for char in s:
            if char in ['(', '{', '[']:
                stack.append(char)
            elif char in [')', '}', ']']:
                if stack[-1] is char:
                    stack.pop()
        if len(stack) is 0:
            return True
        else:
            return False