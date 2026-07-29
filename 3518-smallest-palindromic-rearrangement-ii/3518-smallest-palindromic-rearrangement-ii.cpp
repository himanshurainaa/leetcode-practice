class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        
        int oddCount = 0;
        char midChar = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                midChar = i + 'a';
            }
            count[i] /= 2;
        }
        
        if (oddCount > 1) return "";
        
        int n = 0;
        for (int x : count) n += x;
        
        string leftHalf = "";
        long long targetK = k; 
        
        
        for (int i = 0; i < n; i++) {
            bool foundChar = false;
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    count[j]--; 
                    
                    long long ways = calcWays(count, targetK);
                    
                    if (targetK <= ways) {
                        leftHalf += (char)(j + 'a');
                        foundChar = true;
                        break; 
                    } else {
                        targetK -= ways;
                        count[j]++; 
                    }
                }
            }
            if (!foundChar) return ""; 
        }
        
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        
        if (oddCount == 1) {
            return leftHalf + midChar + rightHalf;
        }
        return leftHalf + rightHalf;
    }

private:
    long long calcWays(const vector<int>& count, long long limit) {
        long long ways = 1;
        int sum = 0;
        
        for (int x : count) {
            if (x > 0) {
                sum += x;
                int r = x;
                if (r > sum / 2) r = sum - r; 
                long long current_nCr = 1;
                for (int i = 1; i <= r; ++i) {
                    current_nCr = (long long)((__int128)current_nCr * (sum - i + 1) / i);
                    if (current_nCr > limit) {
                        current_nCr = limit + 1;
                        break;
                    }
                }
                
                if (current_nCr > limit) return limit + 1;
                
                if (limit / ways < current_nCr) {
                    return limit + 1;
                } else {
                    ways *= current_nCr;
                }
            }
        }
        return ways;
    }
};