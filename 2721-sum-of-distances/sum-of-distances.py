# class Solution:
#     def distance(self, nums: List[int]) -> List[int]:
#         result = []
#         arrm = {}
#         for i in range(len(nums)):
#             arrm[nums[i]] = arrm.get(nums[i],0) + 1
#         for i in range(len(nums)):
#             msum = 0
#             if(arrm[nums[i]] > 1):
#                 for j in range(len(nums)):
#                     if(nums[i] == nums[j]):
#                         msum += abs(i - j)

#             result.append(msum)
        
#         return result


# 

# class Solution:
#     def distance(self, nums: List[int]) -> List[int]:
#         result = []
#         arrm = defaultdict(list)
#         for i in range(len(nums)):
#             arrm[nums[i]].append(i)

#         for i in range(len(nums)):
#             msum = 0
#             for idx in arrm[nums[i]]:
#                 msum += abs(i - idx)
            
#             result.append(msum)
        
#         return result


from collections import defaultdict

class Solution:
    def distance(self, nums):
        arrm = defaultdict(list)

        for i, num in enumerate(nums):
            arrm[num].append(i)

        result = [0] * len(nums)

        for indices in arrm.values():
            prefix = 0

            for i in range(len(indices)):
                result[indices[i]] += indices[i]*i - prefix
                prefix += indices[i]

            prefix = 0

            for i in range(len(indices)-1, -1, -1):
                result[indices[i]] += prefix - indices[i]*(len(indices)-1-i)
                prefix += indices[i]

        return result