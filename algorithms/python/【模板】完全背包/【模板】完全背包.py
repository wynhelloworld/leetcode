# Source : https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=230&tqId=2032575&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
# Author : Yanan Wang
# Date   : 2024-01-29

n, V = map(int, input().split())
v, w = [], []
for _ in range(n):
    l = list(map(int, input().split()))
    v.append(l[0])
    w.append(l[1])
dp = [[0] * (V + 1) for _ in range(n + 1)]
dp_2 = [[0] * (V + 1) for _ in range(n + 1)]
for j in range(1, V + 1):
    dp_2[0][j] = -1
for i in range(1, n + 1):
    for j in range(1, V + 1):
        dp[i][j] = dp[i - 1][j]
        dp_2[i][j] = dp_2[i - 1][j]
        if j >= v[i - 1]:
            dp[i][j] = max(dp[i][j], dp[i][j - v[i - 1]] + w[i - 1])
            if dp_2[i][j - v[i - 1]] != -1:
                dp_2[i][j] = max(dp_2[i][j], dp_2[i][j - v[i - 1]] + w[i - 1])
print(dp[-1][-1])     
print(dp_2[-1][-1] if dp_2[-1][-1] != -1 else 0)     
