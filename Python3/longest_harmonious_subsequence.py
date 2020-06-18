class Solution:
    def findLHS(self, nums: List[int]) -> int:
        result = 0
        
        if not nums: return result
        
        dict = {}
        for num in nums:
            if num not in dict:
                dict[num] = 1
                continue
            dict[num] += 1
        
        keys = sorted(list(dict.keys()))
        for i in range(len(keys) - 1):
            if keys[i] + 1 == keys[i+1]:
                sum2 = dict[keys[i]] + dict[keys[i+1]]
                if sum2 > result: result = sum2
        
        return result
