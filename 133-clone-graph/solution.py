

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

#Recursive depth-first search approach
#using the original graph as a base, keep
#adding nodes by evaluating the neighbors of the graph

class Solution:
	#for some reason leetcode wont accept just assiging class values so need two functions
    def cloneGraph(self, node: 'Node') -> 'Node':
    	#return empty graphs automatically
        if node == None:
            return node
        #empty dictionary serves as copied graph
        self.graph = {}
        #call the function with recursion to copy the graph
        return self.copyNode(node)
        
    def copyNode(self, node):
    	#if the node exists in the graph, return it
    	if self.graph.get(node.val):
    		return self.graph[node.val]
    	else:
    		#create a node and add it to the graph
    		copy = Node(node.val)
    		self.graph[node.val] = copy
    		#then process the neighboring nodes recursivel
    		for nbr in node.neighbors:
    			copy.neighbors.append(self.copyNode(nbr))
    		return copy