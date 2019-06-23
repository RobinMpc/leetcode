class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        def split(y):
            i = 0
            while y[i] == '0' and i < len(y):
                i = i + 1
            return y[i:]
        if x == 0:
            return x
        s = str(x)
        if s[0] == '-':
            res = split(s[1:][::-1])
        else:
            res = split(s[::-1])
        if int(res) > 2147483647:
            return 0
        else:
            if s[0] == '-':
                return 0-int(res)
            else:
                return int(res)
s = Solution()
print s.reverse('123')
