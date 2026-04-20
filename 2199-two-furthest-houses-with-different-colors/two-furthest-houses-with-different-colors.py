# class Solution:
#     def maxDistance(self, colors: List[int]) -> int:
#         i = 0
#         maxd = float('-inf')
#         for i in range(len(colors)):
#             j = i+1
#             for j in range(len(colors)):
#                 if(colors[i] != colors[j]):
#                     maxd = max(abs(j-i), maxd)
        
#         return maxd

# class Solution:
#     def maxDistance(self, colors: List[int]) -> int:
#         maxd = float('-inf')
#         for i in range(0,len(colors)):
#             for j in range(i+1,len(colors)):
#                 if(colors[i] != colors[j]):
#                     maxd = max(abs(j-i), maxd)
        
#         return maxd


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        maxd = float('-inf')
        n = len(colors)
        for i in range(n-1,0,-1):
            if(colors[i] != colors[0]):
                maxd = max(maxd, abs(i-0))
                maxd = max(maxd , abs((n-1)-i))

        return maxd