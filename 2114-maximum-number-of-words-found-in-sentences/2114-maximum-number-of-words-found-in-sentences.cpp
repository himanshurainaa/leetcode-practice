class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCount = 0;
        for (const string& s : sentences) {
            int spaces = 0;
            for (char c : s) {
                if (c == ' ') spaces++;
            }
            maxCount = max(maxCount, spaces + 1);
        }
        return maxCount;
    }
};