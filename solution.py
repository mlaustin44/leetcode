class Solution:
	def maxProfit(self, prices):
		minPrice = 2**32
		maxProf = 0
		for price in prices:
			if price < minPrice:
				minPrice = price
			elif (price - minPrice) > maxProf:
				maxProf = price - minPrice
		return maxProf


s = Solution()
r = s.maxProfit([7,6,4,3,1])
print(r)
