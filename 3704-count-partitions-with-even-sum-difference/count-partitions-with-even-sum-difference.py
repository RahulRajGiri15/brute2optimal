class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        sum = 0
        for num in nums:
            sum += num
        if(sum % 2 == 0):
            return len(nums)-1
        else:
            return 0
        