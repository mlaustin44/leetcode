class Solution(object):
	def twoSum(self, nums, target):
		lenNums = len(nums)
		numDict = {}
		#create a dictionary of all of the numbers that do exist
		for i in range(lenNums):
			numDict[nums[i]] = i

		#then run through the list
		#calculate the other number that's needed
		#then see if it exists
		for i in range(lenNums):
			currentNum = nums[i]
			needed = target - currentNum
			result = numDict.get(needed, None)
			if i == result:
				continue
			if result:
				return [i, result]

soln = Solution()

res = soln.twoSum([3,3], 6)
print(res)