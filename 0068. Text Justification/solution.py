class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        def createLine(wordIndexStart):
            # Use in the form:
            # wordsIndex, currentLine = createLine(wordsIndex)

            line = words[wordIndexStart]
            wordIndexStart += 1

            wordsAdded = 0
            for wordToAdd in words[wordIndexStart:]:
                if len(line) + 1 + len(wordToAdd) <= maxWidth:
                    line += ' ' + wordToAdd
                    wordsAdded += 1
                else: break

            return wordIndexStart+wordsAdded, line

        def addExtraSpaces(line, isFinalLine):
            # Use in the form:
            # currentLine = addExtraSpaces(currentLine)

            if isFinalLine:
                while len(line) < maxWidth:
                    line += ' '
                return line

            spacePositions = [index for index, ch in enumerate(line) if ch == ' ']
            numSpaces = len(spacePositions)

            insertIndex = 0
            currentSpace = 0
            while len(line) < maxWidth:
                if numSpaces == 0:
                    insertIndex = len(line)
                else:
                    insertIndex = spacePositions[currentSpace]
                    currentSpace = (currentSpace+1) % numSpaces
                    for index, value in enumerate(spacePositions):
                        if index >= currentSpace:
                            spacePositions[index] += 1

                line = line[:insertIndex+1] + ' ' + line[insertIndex+1:]

                insertIndex += 1

            return line

        lines = []
        wordsIndex = 0

        while True:
            if wordsIndex == len(words):
                break
            wordsIndex, currentLine = createLine(wordsIndex)
            isFinal = True if wordsIndex == len(words) else False
            currentLine = addExtraSpaces(currentLine, isFinal)
            lines.append(currentLine)

        return lines

        