class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        sIndex = 0
        tIndex = 0
        match = 0
        if len(s) == 0:
            return True
        #incrementing left pointer and right pointer if match is seen 
        #else increment right pointer alone
        
        while sIndex < len(s) or tIndex < len(t):
            if len(t) == tIndex:
                break
            if len(s) == sIndex:
                break
            if s[sIndex] == t[tIndex]:
                sIndex+=1
                tIndex+=1
                match +=1
                if match == len(s):
                    return True
            else:
                tIndex+=1
                
        return False



obj = Solution()
print(obj.isSubsequence("abc","abzxcj"))