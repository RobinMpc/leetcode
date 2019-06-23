class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        def get_index(x, y):
            if numRows == 1:
                return y
            if x == 1 or x == numRows:
                return x + 2 * (y - 1) * (numRows - 1)
            else:
                if y % 2 == 1:
                    return x + (y - 1) * (numRows - 1)
                else:
                    return x + (y - 2) * (numRows - 1) + 2 * (numRows - x)
        
        str_len = len(s)
        result = ''
        for i in range(0, numRows):
            col = 1
            index = get_index(i + 1, col)
            while index <= str_len:
                result = result + s[index - 1]
                col = col + 1
                index = get_index(i + 1, col)

        return result
