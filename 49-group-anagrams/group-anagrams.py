# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         res: List[List[str]] = []
#         mp: dict[str, List[str]] = defaultdict(list)

#         for i in range(0,len(strs),1):
#             st = strs[i]
#             key = ''.join(sorted(st))
#             mp[key].append(strs[i])

#         for key in mp:
#             res.append(mp[key])
#         return res


# 

class Solution:
    def sortana(self , word: str) -> str:
        freq : List[int] = [0]*26
        res = ""
        for ch in word:
            freq[ord(ch) - ord('a')] += 1
        for i in range(0,26,1):
            if(freq[i] > 0):
                res += chr(i+ ord('a')) * freq[i]
        return res

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res: List[List[str]] = []
        mp: dict[str, List[str]] = defaultdict(list)

        for i in range(0,len(strs),1):
            st = strs[i]
            key = self.sortana(st)
            mp[key].append(strs[i])

        for key in mp:
            res.append(mp[key])
        return res
