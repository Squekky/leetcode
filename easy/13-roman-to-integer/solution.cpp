#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> char_vals = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        if (s.size() == 1) {
            return char_vals[s.at(0)];
        }

        int result = 0;
        for (int i = 1; i <= s.size() - 1; i++) {
            if (char_vals[s.at(i - 1)] < char_vals[s.at(i)]) {
                result -= char_vals[s.at(i - 1)];
            } else {
                result += char_vals[s.at(i - 1)];
            }
        }
        // Add final character
        result += char_vals[s.at(s.size() - 1)];
        return result;
    }
};