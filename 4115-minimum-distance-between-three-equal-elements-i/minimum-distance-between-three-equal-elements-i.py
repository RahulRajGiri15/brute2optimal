class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        dist = float('inf')
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    if(nums[i] == nums[j] and nums[j] == nums[k]):
                        distfind = abs(i-j) + abs(j - k) + abs(k - i)
                        dist = min(dist , distfind)
        
        return dist if dist != float('inf') else -1
            