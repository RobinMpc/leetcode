class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        sub_len = 0
        station = 0
        str_len = len(s)
	for i in range(0, str_len):
            j = 0;
            while i - j >= 0 and i + j < str_len:
                if s[i - j] == s[i + j]:
                    j = j + 1
                else:
                    break
            if j > sub_len:
                sub_len = j
                station = i
	j_len = sub_len

	o_station, sub_len = 0, 0
	for i in range(0, str_len):
            j = 0
	    while i - j >= 0 and i + j + 1< str_len:
                if s[i - j] == s[i + j + 1]:
                    j = j + 1
		else:
                    break
	    if j > sub_len:
                sub_len = j
		o_station = i
	o_len = 2 * sub_len
	if 2 * j_len > 2 * sub_len:
            return s[station - j_len + 1 : station + j_len]
        else:
            return s[o_station - sub_len + 1 : o_station + sub_len + 1]

if __name__ == "__main__":
    s = Solution()
    print s.longestPalindrome('bbaabbaab')


