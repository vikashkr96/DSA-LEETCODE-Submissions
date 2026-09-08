class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(0,0,n,s,res);
        return res;
    }

    void backtrack(int openN, int closedN, int n, string &s, vector<string> &res){

        // base case ...
        if(openN == closedN && closedN == n){
            res.push_back(s);
            return;
        }

        // adding (
        if(openN < n){
            s.push_back('(');
            backtrack(openN+1 , closedN , n , s , res);
            s.pop_back();
        }

        // adding )
        if(closedN < openN){
            s.push_back(')');
            backtrack(openN , closedN+1 , n , s , res);
            s.pop_back();
        }

    }
};