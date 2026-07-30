#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int kid = 0;
        int cookie = 0;
        
        while (kid < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[kid]) {
                kid++;
            }
            cookie++;
        }
        
        return kid;
    }
};