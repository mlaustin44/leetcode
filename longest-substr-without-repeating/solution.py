class Solution:
	def lengthOfLongestSubstring(self, s: str) -> int:
		s_len = len(s)
		longest = 0

		for i in range(s_len):
			used_letters = []
			for j in range(i, s_len):
				cur_ltr = s[j]
				print(f'i: {i}	j: {j}	longest: {longest} cur_ltr: {cur_ltr}	used_letters: {used_letters}')
				if cur_ltr in used_letters:
					print('main if')
					used_letters.clear()
					cur_len = j-i
					if cur_len > longest:
						longest = cur_len
					break
				elif j == s_len - 1:
					cur_len = j - i + 1
					print(f'last letter! i: {i}, j: {j}, curlen: {cur_len}')
					if cur_len > longest:
						longest = cur_len
				else:
					print('just if')
					used_letters.append(cur_ltr)
		return longest


soln = Solution()

res = soln.lengthOfLongestSubstring('dvdf')
print(res)