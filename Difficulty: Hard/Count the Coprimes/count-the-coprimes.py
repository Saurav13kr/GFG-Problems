class Solution:
    def cntCoprime(self, arr):
       # code here
       
        from collections import defaultdict
        from math import isqrt
        from itertools import combinations
        from functools import reduce
        from operator import mul
        
        def prime_factors(x: int) -> list[int]:
            """given integer, return all the prime factors"""
            ret = []
            k = 2
            while k*k <= x:
                if x%k == 0:
                    ret.append(k)
                while x%k == 0:
                    x //= k
                k += 1
            if x > 1:
                ret.append(x)
            return ret
            
        cnt = defaultdict(int)
        ans = 0
        
        for i, e in enumerate(arr):
            if e == 1:
                ans += i
                continue
            
            primes = prime_factors(e)
            k = len(primes)
            
            shared = 0
            for r in range(1, k+1):
                for comb in combinations(primes, r):
                    prod = reduce(mul, comb, 1)
                    if r&1:   #inclusive
                        shared += cnt[prod]
                    else:     #exclusive
                        shared -= cnt[prod]
            ans += i-shared
            
            for r in range(1, k+1):
                for comb in combinations(primes, r):
                    prod = reduce(mul, comb, 1)
                    cnt[prod] += 1
        return ans