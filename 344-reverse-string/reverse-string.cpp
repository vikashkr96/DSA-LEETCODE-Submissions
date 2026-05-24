class Solution {
public:
    
    void solve(vector<char>& s, int left, int right) {
        
        // Base Case
        if(left >= right) {
            return;
        }

        // Swap characters
        swap(s[left], s[right]);

        // Recursive call
        solve(s, left + 1, right - 1);
    }

    void reverseString(vector<char>& s) {
        solve(s, 0, s.size() - 1);
    }
};
