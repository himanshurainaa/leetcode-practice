#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp_t = t;
        vector<int> req(4, 0);
        vector<int> primes = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (temp_t % primes[i] == 0) {
                req[i]++;
                temp_t /= primes[i];
            }
        }

        if (temp_t > 1) return "-1";

        vector<vector<int>> factor_map = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0},
            {2,0,0,0}, {0,0,1,0}, {1,1,0,0}, {0,0,0,1},
            {3,0,0,0}, {0,2,0,0}
        };

        bool valid = true;
        vector<int> current_factors(4, 0);
        for (char c : num) {
            if (c == '0') {
                valid = false;
                break;
            }
            vector<int> f = factor_map[c - '0'];
            for (int j = 0; j < 4; ++j) {
                current_factors[j] += f[j];
            }
        }
        if (valid) {
            bool ok = true;
            for (int j = 0; j < 4; ++j) {
                if (current_factors[j] < req[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return num;
        }

        int N = num.length();
        int limit = N;
        for (int i = 0; i < N; ++i) {
            if (num[i] == '0') {
                limit = i;
                break;
            }
        }

        vector<vector<int>> pref_factors(N + 1, vector<int>(4, 0));
        for (int i = 0; i < limit; ++i) {
            int d = num[i] - '0';
            for (int j = 0; j < 4; ++j) {
                pref_factors[i + 1][j] = pref_factors[i][j] + factor_map[d][j];
            }
        }

        auto get_min_digits = [](int a, int b, int c, int d) -> string {
            int c_8 = max(0, a) / 3;
            int rem_a = max(0, a) % 3;
            int c_9 = max(0, b) / 2;
            int rem_b = max(0, b) % 2;

            string digits = "";
            digits.append(max(0, d), '7');
            digits.append(max(0, c), '5');
            digits.append(c_8, '8');
            digits.append(c_9, '9');

            if (rem_a == 1 && rem_b == 0) digits += '2';
            else if (rem_a == 2 && rem_b == 0) digits += '4';
            else if (rem_a == 0 && rem_b == 1) digits += '3';
            else if (rem_a == 1 && rem_b == 1) digits += '6';
            else if (rem_a == 2 && rem_b == 1) digits += "26";

            sort(digits.begin(), digits.end());
            return digits;
        };

        // 3. Search for the smallest strictly greater valid string of length N
        // We only replace with a digit STRICTLY GREATER than num[i].
        for (int i = min(N - 1, limit); i >= 0; --i) {
            int start_digit = 1;
            if (i < limit) {
                start_digit = (num[i] - '0') + 1;
            }
            
            for (int d = start_digit; d <= 9; ++d) {
                vector<int> f = factor_map[d];
                
                int cur_a = req[0] - (pref_factors[i][0] + f[0]);
                int cur_b = req[1] - (pref_factors[i][1] + f[1]);
                int cur_c = req[2] - (pref_factors[i][2] + f[2]);
                int cur_d = req[3] - (pref_factors[i][3] + f[3]);
                
                string min_str = get_min_digits(cur_a, cur_b, cur_c, cur_d);
                int rem_len = N - 1 - i;
                
                if ((int)min_str.length() <= rem_len) {
                    string padding(rem_len - min_str.length(), '1');
                    string prefix = num.substr(0, i) + to_string(d);
                    return prefix + padding + min_str;
                }
            }
        }

        string min_str = get_min_digits(req[0], req[1], req[2], req[3]);
        int target_len = max(N + 1, (int)min_str.length());
        string padding(target_len - min_str.length(), '1');
        return padding + min_str;
    }
};