from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.rows = len(grid)
        if self.rows == 0:
            return 0
        self.cols = len(grid[0])
        if self.cols == 0:
            return 0

        self.grid = grid
        islands = 0

        self.searchDirs = ((0, 1), (1, 0), (0,-1), (-1, 0))

        #search grid to hold the status of whether a given square has been found or not yet
        self.searchGrid = [[0 for i in range(self.cols)] for j in range(self.rows)]
        
        #a dfs will get all the attached land to our island - the key concept here
        # is that each DFS search cycle (i.e., triggered by the main function)
        # has a unique ID.  This lets us understand whether a given square found in the DFS
        # was found in *the current* DFS (which means it can be a new island) or a *previous*
        # DFS (which means it's already been counted as part of another search)
        searchId = 1
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == "1":
                    res = self.dfs(i, j, searchId)
                    if not res:
                        islands += 1
                    searchId += 1
        
        return islands

    #all we care about is islands - so all we really care about is whether this is 
    # new land (in which case - it's an new island), if it's old land found in a previous 
    # search (in which case  - it's already been counted).  

    # Since every DFS cycle is initiated on a square of land that is garuenteed to be part of an island, 
    # we only care if it's a new island (return 0) or an old islane (return 1)
    def dfs(self, r, c, id):
        #WATER CASES (edge or actual water) - return 0 because they don't say anything about new vs old islands
        #hit an edge
        if (r < 0) or (r == self.rows) or (c < 0) or (c == self.cols):
            return 0
        #hit water square
        if self.grid[r][c] == "0":
            return 0
        
        #check if we've already searched here.  if we have, there are two cases:
        #   case 1: we've already searched here in a previous search -> it's an old island, return 1
        #   case 2: we've already searched here during the current search -> new island, return 0
        if (self.searchGrid[r][c] > 0):
            if (self.searchGrid[r][c] == id):
                return 0
            else:
                return 1
        
        #set the current location to the id of the current search
        self.searchGrid[r][c] = id
        
        # since the search returns 0 for new island an 1 for old we can keep summing the results
        res = 0
        for d in self.searchDirs:
            res += self.dfs(r + d[0], c + d[1], id)
        
        return res

s = Solution()

grid = [["1","0","1","1","0","1","1"]]

r = s.numIslands(grid)
print(r)