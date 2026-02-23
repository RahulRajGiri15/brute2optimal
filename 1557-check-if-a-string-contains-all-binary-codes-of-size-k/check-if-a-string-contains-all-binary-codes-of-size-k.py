class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        st : set[str] = set()
        count = pow(2 , k)
        n = len(s)
        for i in range(k,n+1,1):
            sb = s[i-k : i]
            if(sb not in st):
                st.add(sb)
                count -= 1
            if(count == 0):
                return True
        return False