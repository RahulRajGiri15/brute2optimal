class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mp = {}
        for nm in nums:
            mp[nm] = mp.get(nm , 0) + 1
        
        for key,values in mp.items():
            if(values) > 1 : 
                return True
        return False

        