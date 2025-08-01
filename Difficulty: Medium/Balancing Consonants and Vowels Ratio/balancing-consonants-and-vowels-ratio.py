class Solution:
    def countBalanced(self, arr):
        def is_vowel(c):
            return c in 'aeiou'

        n = len(arr)
        prefix_diff = 0
        res = 0
        count = {0: 1}  # {prefix difference: frequency}

        for s in arr:
            v = sum(is_vowel(c) for c in s)
            cons = len(s) - v
            prefix_diff += v - cons
            res += count.get(prefix_diff, 0)
            count[prefix_diff] = count.get(prefix_diff, 0) + 1

        return res