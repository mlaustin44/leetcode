class Solution:
    def merge(self, intervals):
        # first sort the list of intervals by the start value
        intervals.sort()

        result = []
        current_int_start = intervals[0][0]
        current_int_end = intervals[0][1]

        for i in intervals:
            if i[0] <= current_int_end:
                if i[1] > current_int_end:
                    current_int_end = i[1]
            else:
                result.append([current_int_start, current_int_end])
                current_int_start = i[0]
                current_int_end = i[1]

        result.append([current_int_start, current_int_end])

        return result



s = Solution()

#test = [[1,3],[2,6],[8,10],[15,18]]
#test = [[1,4],[4,5]]
test = [[1,4], [2,3]]

r = s.merge(test)

print(r)