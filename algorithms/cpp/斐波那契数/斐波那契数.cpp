// Source : https://leetcode.cn/problems/fibonacci-number/ 
// Author : Yanan Wang
// Date   : 2023-09-17

// 记忆化搜索（递归版本的动态规划）
//   1、递归返回的时候将结果保存到备忘录中
//   2、递归进入的时候先瞅一瞅备忘录中有没有需要的内容

class Solution {
private:
    int memory[31];
public:
    int memorySearch(int n) {
        if (memory[n] != -1) {
            return memory[n];
        }
        if (n == 0 || n == 1) {
            memory[n] = n;
            return n;
        }
        memory[n] = memorySearch(n - 1) + memorySearch(n - 2);
        return memory[n];
    }
    int fib(int n) {
        memset(memory, -1, sizeof memory);
        return memorySearch(n);
    }
};