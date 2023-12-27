# Source : https://leetcode.cn/problems/insert-delete-getrandom-o1/
# Author : Yanan Wang
# Date   : 2023-12-27

class RandomizedSet:

    def __init__(self):
        self.nums = []
        self.valToIndex = {}


    def insert(self, val: int) -> bool:
        if val in self.valToIndex:
            return False
        self.valToIndex[val] = len(self.nums)
        self.nums.append(val)        
        return True


    def remove(self, val: int) -> bool:
        if val not in self.valToIndex:
            return False
        index = self.valToIndex[val]
        self.valToIndex[self.nums[-1]] = index
        self.nums[index] = self.nums[-1]
        self.nums.pop()
        self.valToIndex.pop(val) 
        return True


    def getRandom(self) -> int:
        return random.choice(self.nums)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()