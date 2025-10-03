class Solution:
    def possibleWords(self, arr):
        # code here
        d2l = [
            [""],
            [""],
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        ]
        n = len(arr)
        
        def gen(i=0, acc=[], ans=[]):
            if i == n:
                ans.append("".join(acc))
            else:
                for c in d2l[arr[i]]:
                    acc.append(c)
                    gen(i + 1)
                    acc.pop()
            return ans
        
        return gen()