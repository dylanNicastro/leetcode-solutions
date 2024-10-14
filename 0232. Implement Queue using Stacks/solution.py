class MyQueue(object):

    def __init__(self):
        self.queue = []
        self.back = 0

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.queue.append(x)
        self.back += 1
        
        

    def pop(self):
        """
        :rtype: int
        """
        if self.empty():
            return None
        item = self.queue[0]
        del self.queue[0]
        self.back -= 1
        return item
            
        
        

    def peek(self):
        """
        :rtype: int
        """
        return self.queue[0]
        

    def empty(self):
        """
        :rtype: bool
        """
        if not self.queue:
            return True
        return False
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()