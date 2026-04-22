class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        result = []
        for query in queries:
            for s in dictionary:
                diff = 0
                for i in range(len(query)):
                    if (s[i] != query[i]):
                        diff += 1
                        if(diff > 2):
                            break
                    
                if(diff <= 2):
                    result.append(query)
                    break   #stop cecking for this any further

        return result





