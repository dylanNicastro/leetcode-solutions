class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = {} # table structure: {number: [index, count]}
        for index, num in enumerate(nums):
            table.setdefault(target-num, [-1, 0])
            if table[target - num][1] > 0: # if the other number already exists in dict
                return [index, table[target-num][0]]
            table.setdefault(num, [-1, 0])
            table[num] = [index, table[num][1]+1] # otherwise add number to dict and go next
        return None