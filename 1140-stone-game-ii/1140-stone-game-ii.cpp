#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        std::vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                } else {
                    for (int x = 1; x <= 2 * M; ++x) {
                        dp[i][M] = std::max(dp[i][M], suffixSum[i] - dp[i + x][std::max(M, x)]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};