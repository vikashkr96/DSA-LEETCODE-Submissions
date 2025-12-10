class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if( n == 1) return s;

        int start = 0;
        int maxLen = 1;

        for(int i =0; i<n; i++){

            int left = i , right = i; // for odd length of strings
            while(left >= 0 && right < n && s[right] == s[left]){
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }

            left = i , right = i+1; // for even length of strings
            while(left >= 0 && right < n && s[right] == s[left]){
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
    }
};