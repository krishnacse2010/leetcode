class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        Slist = self.getListVal(s)
        tList = self.getListVal(t)
        if Slist == tList:
            return True
        else:
            return False
    def getListVal(self,str1):
        #hash map with pos as value and char as key
        index_mapping = {}
        #final value to be checked ,list of pos/rep pos
        posList = []
        
        for pos , val in enumerate(str1):
            if val not in index_mapping:
                index_mapping[val] = pos
            posList.append(index_mapping[val])
        return posList
        
        
a=Solution()
print(a.isIsomorphic('paper','title'))
        
        
        
        