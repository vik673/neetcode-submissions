class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string result="";
        int rem = 0;
        while(columnNumber > 0)
        {
           columnNumber--; 

           rem = columnNumber % 26;
           result += (rem + 'A');
           columnNumber = columnNumber/26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};