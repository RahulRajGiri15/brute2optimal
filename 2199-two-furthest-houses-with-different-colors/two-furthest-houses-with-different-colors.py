class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        i = 0
        maxd = float('-inf')
        for i in range(len(colors)):
            j = i+1
            for j in range(len(colors)):
                if(colors[i] != colors[j]):
                    maxd = max(abs(j-i), maxd)
        
        return maxd