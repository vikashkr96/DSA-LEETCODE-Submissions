class Solution {
public:
    string countAndSay(int n) {
        string say = "1";
        for (int step = 1; step < n; step++) {
            string current = "";
            int i = 0;
            
            while (i < say.size()) {
                int count = 1;
                
                while (i + 1 < say.size() && say[i] == say[i + 1]) {
                    count++;
                    i++;
                }
                current += to_string(count) + say[i];
                i++;
            }
            
            say = current;
        }
        
        return say;
    }

};