from typing import List

# class representing a node (which in turn represents a course)
class Node:
	def __init__(self, num):
		self.num = num
		self.prereqs = []
		self.tempLock = False
		self.checked = False
	def addPrereq(self, prereq):
		self.prereqs.append(prereq)



class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.courses = []
        self.canFinish = True
        #build a list containing objects for all the courses
        for i in range (numCourses):
        	self.courses.append(Node(i))

        #now all all of the prerequisites to the courses
        for edge in prerequisites:
        	course = edge[0]
        	prereq = edge[1]
        	result = self.courses[course].addPrereq(prereq)
        
        for course in self.courses:
        	self.checkPrereqs(course)

        return self.canFinish

    def checkPrereqs(self, course):
    	if course.tempLock:
    		self.canFinish = False
    		return False
    	elif course.checked:
    		return True
    	else:
    		course.tempLock = True
    		for prereq in course.prereqs:
    			result = self.checkPrereqs(self.courses[prereq])
    			if not result:
    				return False
    		course.tempLock = False
    		course.checked = True
    		return True


soln = Solution()
result = soln.canFinish(2, [[1,0]])
print(result)