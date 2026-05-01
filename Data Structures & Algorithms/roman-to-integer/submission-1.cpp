class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol_map;
        symbol_map['I'] = 1;
        symbol_map['V'] = 5;
        symbol_map['X'] = 10;
        symbol_map['L'] = 50;
        symbol_map['C'] = 100;
        symbol_map['D'] = 500;
        symbol_map['M'] = 1000;

        int result = symbol_map[s[0]];
        for(int i = 1;i<s.size();i++)
        {
            if(symbol_map[s[i-1]] < symbol_map[s[i]])
            {
                result += symbol_map[s[i]];
                result -= 2*symbol_map[s[i-1]];
            }
            else
            {
                result += symbol_map[s[i]];
            }
        }
        return result;
    }
};