class Solution {
public:
    long long solve(string &s, int idx, long long num, int sign) {

        // Base case: end of string
        if (idx >= s.size()) {
            return sign * num;
        }

        // If current character is not a digit, stop
        if (s[idx] < '0' || s[idx] > '9') {
            return sign * num;
        }

        // Add current digit
        num = num * 10 + (s[idx] - '0');

        // Handle overflow
        if (sign == 1 && num > INT_MAX) {
            return INT_MAX;
        }

        if (sign == -1 && -num < INT_MIN) {
            return INT_MIN;
        }

        return solve(s, idx + 1, num, sign);
    }

    int myAtoi(string s) {

        int n = s.size();
        int idx = 0;

        // 1. Skip leading spaces
        while (idx < n && s[idx] == ' ') {
            idx++;
        }

        // 2. Empty string
        if (idx == n) {
            return 0;
        }

        // 3. Determine sign
        int sign = 1;

        if (s[idx] == '-') {
            sign = -1;
            idx++;
        }
        else if (s[idx] == '+') {
            idx++;
        }

        // 4. Recursively process digits
        return solve(s, idx, 0, sign);
    }
};