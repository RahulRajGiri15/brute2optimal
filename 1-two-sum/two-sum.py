class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        n = len(nums)
        i = 0
        while(i < n-1):
            j = i+1
            while(j < n):
                if(nums[i] + nums[j] == target):
                    ans.append(i)
                    ans.append(j)
                    return ans
                j += 1

            i += 1

        return ans
        


            

