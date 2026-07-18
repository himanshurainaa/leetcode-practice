#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) return false;
        
        unordered_set<char> uniqueChars;
        for (char c : sentence) {
            uniqueChars.insert(c);
            if (uniqueChars.size() == 26) return true;
        }
        
        return uniqueChars.size() == 26;
    }
};