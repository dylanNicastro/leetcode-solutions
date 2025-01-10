class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        frequencies = {}
        returnArray = []
        for word in words2:
            currentFrequency = {}
            for ch in word:
                currentFrequency[ch] = currentFrequency.get(ch, 0) + 1
            for ch, freq in currentFrequency.items():
                frequencies[ch] = max(frequencies.get(ch, 0), freq)
        
        for word in words1:
            currentFrequency = {}
            for ch in word:
                currentFrequency[ch] = currentFrequency.get(ch, 0) + 1
            flag = 1
            for key in frequencies:
                if currentFrequency.get(key, 0) < frequencies[key]:
                    flag = 0
                    break
            if flag == 1:
                returnArray.append(word)
        
        return returnArray
