class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        special : List[str] = []
        start = 0 
        balance = 0
        for i in range(0 , len(s),1):
            balance += 1 if s[i] == '1' else -1
            if(balance == 0):
                inner = s[start +1 : i]
                special.append('1' + self.makeLargestSpecial(inner) + '0')
                start = i+1
            
        special.sort(reverse=True)
        result = ""
        for st in special:
            result += st
        
        return result