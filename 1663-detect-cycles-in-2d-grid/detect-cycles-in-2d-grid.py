class Solution:

    direction = [(-1,0),(1,0),(0,-1),(0,1)]
    def Dfscycle(self,i,j,prev_i,prev_j,grid: List[List[str]],visited):
        if(visited[i][j] == True): 
            return True
        visited[i][j] = True

        for dir in self.direction:
            new_i = i + dir[0]
            new_j = j + dir[1]

            if(new_i >=0 and new_i < self.m and new_j >=0 and new_j < self.n and grid[i][j] == grid[new_i][new_j]):
                if(new_i == prev_i and new_j == prev_j):
                    continue

                if(self.Dfscycle(new_i,new_j,i,j,grid,visited)):
                    return True

        return False

    def containsCycle(self, grid: List[List[str]]) -> bool:
        
        self.m = len(grid)
        self.n = len(grid[0])
        visited = [[False for _ in range(self.n)] for _ in range(self.m)]

        for i in range(self.m):
            for j in range(self.n):
                if(visited[i][j] == False and self.Dfscycle(i,j,i,j,grid,visited)):
                    return True

        
        return False
    