// Source : https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
// Author : Yanan Wang
// Date   : 2023-08-14

/**
 * 同余定理：(a - b) ➗ p = k ...... 0  （如果a-b能被p整除），那么a % p == b % p
 * c++、java中，假设a是负数、p是正数，那么 a % p == 负数，
 *             为了修正这一结果，可以写成a % p + p, 但有可能a又是正数，所以为了a的正负统一，最终写成(a % p + p) % p
 *
 * 假设求以i结尾的数组中，子数组之和可被k整除的子数组数目。
 *      |<---------sum-------->|
 *      -------------------------------------
 *      |<----x---->|          i
 *   根据上图，只需求出(sum - x) % k 是否等于0即可，那么就只需求出sum % k 是否等于 x % k即可，然后求出符合条件的次数。
 *
 * 上面只是求出了以i结尾的数组，那么本题只需要将i从0遍历nums到结尾，然后把结果加起来即可。      
 */
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0 % k] = 1;   
        int sum = 0, result = 0;
        for (auto &x : nums) {
            sum += x;
            int rem = (sum % k + k) % k;
            if (hash.count(rem)) result += hash[rem];
            ++hash[rem];
        }
        return result;
    }
};