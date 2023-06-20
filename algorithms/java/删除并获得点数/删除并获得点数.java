// Source : https://leetcode.cn/problems/delete-and-earn/
// Author : Yanan Wang
// Date   : 2023-06-20

class Solution {
    public int deleteAndEarn(int[] nums) {
        final int N = 10001;
        int[] arr = new int[N];
        for (int i = 0; i < nums.length; i++) {
            arr[nums[i]] += 1;
        }
        int[] f = new int[N];
        int[] g = new int[N];
        for (int i = 1; i < N; i++) {
            f[i] = g[i - 1] + arr[i] * i;
            g[i] = Math.max(f[i - 1], g[i - 1]);
        }
        return Math.max(f[N - 1], g[N - 1]);
    }
}