class Solution:
    def vowelCount(self, s):
        dict={}
        
        for i in s:
            if i in 'aeiou':
                if i in dict:
                    dict[i]+=1
                else:
                    dict[i]=1
        
        if len(dict)==0:
            return 0
        total=1
        n=len(dict)
        for i in dict:
            total*=(n*dict[i])
            n-=1
        return total 