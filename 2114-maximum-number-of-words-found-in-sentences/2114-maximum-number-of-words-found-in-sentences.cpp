#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCount = 0;
        
        // Use .size() to get the number of sentences
        for (int i = 0; i < sentences.size(); i++) {
            int wordCount = 0;
            
            // Count spaces to find word count (words = spaces + 1)
            // This is a built-in approach using std::count
            wordCount = count(sentences[i].begin(), sentences[i].end(), ' ') + 1;
            
            // Update maxCount
            maxCount = max(maxCount, wordCount);
        }
        
        return maxCount;
    }
};