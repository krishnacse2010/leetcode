class Solution:
    
        
    def longestPalindrome(self, s: str) -> int:
        
        hashmap = {}
        
        for char in s:
            if char in hashmap:
                hashmap[char] += 1
            else:
                hashmap[char] = 1
        Count = 0
        flag = 0
        for key in hashmap:
            if hashmap[key] % 2 == 0:
               
               Count += hashmap[key]
            else:
                flag = 1 
                if hashmap[key] > 1 :
                   
                   Count += int(hashmap[key] / 2) * 2
            
        if flag:
           Count += 1
        return Count

a = Solution()
print(a.longestPalindrome('aaa'))