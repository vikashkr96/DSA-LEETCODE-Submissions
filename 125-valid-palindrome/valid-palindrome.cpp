class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        
        // Build cleaned string with only lowercase alphanumeric 
        for (char c : s) {
            if (isalnum(c)) {
                res += tolower(c);
            }
        }

        // Two-pointer 
        int i = 0, j = res.size() - 1;
        while (i < j) {
            if (res[i] != res[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

