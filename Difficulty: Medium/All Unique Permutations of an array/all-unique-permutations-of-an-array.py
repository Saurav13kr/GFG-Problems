from itertools import permutations
from typing import List
class Solution:
    def uniquePerms(self, arr):
        # code here 
        # 1. itertools.permutations generates all possible permutations, including duplicates.
        #    For an input like [1, 1, 2], it will produce (1, 1, 2) twice.
        all_perms_iterator = permutations(arr)
        
        # 2. Placing the results into a set automatically removes any duplicates.
        #    The set will contain unique tuples, e.g., {(1, 1, 2), (1, 2, 1), (2, 1, 1)}.
        unique_perms_set = set(all_perms_iterator)
       
        result = sorted([list(p) for p in unique_perms_set])
        
        return result