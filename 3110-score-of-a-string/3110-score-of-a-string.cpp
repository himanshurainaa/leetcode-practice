class Solution {
public:
    int scoreOfString(string s) {
        int string_count=0;
        for(int i=0; i<s.size()-1;i++){
        
        string_count=string_count+abs(s[i]-s[i+1]);

    }
    return string_count;
    }
};