class Solution {
public:

    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);

        if (exp % 2 == 0)
            return (half * half) % MOD;

        return (((half * half) % MOD) * base) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long ans = power(5, evenPositions);
        ans = (ans * power(4, oddPositions)) % MOD;

        return ans;
    }
};