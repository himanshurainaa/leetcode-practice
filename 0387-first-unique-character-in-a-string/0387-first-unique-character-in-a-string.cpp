class Solution {
public:
    int firstUniqChar(string s) {
        // 1. Count frequencies
        int count[26] = {0}; // Array for 'a' through 'z'
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // 2. Find the first character with count 1
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        // 3. Return -1 if no unique character found
        return -1;
    }
};