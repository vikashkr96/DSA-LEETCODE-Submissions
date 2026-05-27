class Solution {
public:

    void solve(string &s, int i, int k){

        // base case
        if(i >= s.length())
            return;

        // reverse first k chars
        int l = i;
        int r = min(i + k - 1, (int)s.length() - 1);

        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }

        // move to next 2k block
        solve(s, i + 2 * k, k);
    }

    string reverseStr(string s, int k) {

        solve(s, 0, k);

        return s;
    }
};