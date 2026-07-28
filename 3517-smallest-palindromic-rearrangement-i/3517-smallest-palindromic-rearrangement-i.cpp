class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        string first_half = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                middle = string(1, i + 'a');
            }
            if (freq[i] > 0) {
                first_half.append(freq[i] / 2, i + 'a');
            }
        }
        
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        return first_half + middle + second_half;
    }
};