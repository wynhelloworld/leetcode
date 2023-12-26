# Source : https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-26

class Solution:
    def reverseMessage(self, message: str) -> str:
        message = message.strip()

        left = right = len(message) - 1
        word = []
        while left >= 0:
            while left >= 0 and message[left] != ' ':
                left -= 1
            word.append(message[left + 1: right + 1])
            while left >= 0 and message[left] == ' ':
                left -= 1
            right = left

        return " ".join(word)    
