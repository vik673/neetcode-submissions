class Solution {
    int gcd(int a, int b)
    {
        if(a < b) swap (a, b);

        while(b >0)
        {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1 + str2 != str2 + str1) return "";
        int len = gcd(str1.length(), str2.length());
        return str1.substr(0, len);
    }
};