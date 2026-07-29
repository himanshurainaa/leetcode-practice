#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string original = std::to_string(x);
        
        std::string reversed = original;
        
        std::reverse(reversed.begin(), reversed.end());
        
        return original == reversed;
    }
};