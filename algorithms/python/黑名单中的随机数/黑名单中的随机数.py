# Source : https://leetcode.cn/problems/random-pick-with-blacklist/description/
# Author : Yanan Wang
# Date   : 2023-12-27

class Solution:

    def __init__(self, n: int, blacklist: List[int]):
        self.sz = n - len(blacklist)
        self.mapping = {}
        for elem in blacklist:
            self.mapping[elem] = 778
        
        last = n - 1
        for elem in blacklist:
            if elem >= self.sz:
                continue
            while last in self.mapping:
                last -= 1
            self.mapping[elem] = last
            last -= 1 


    def pick(self) -> int:
        index = random.randint(0, self.sz - 1)
        if index in self.mapping:
            return self.mapping[index]
        return index


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()