class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res: List[List[str]] = []
        mp: dict[str, List[str]] = defaultdict(list)

        for i in range(0,len(strs),1):
            st = strs[i]
            key = ''.join(sorted(st))
            mp[key].append(strs[i])

        for key in mp:
            res.append(mp[key])
        return res
