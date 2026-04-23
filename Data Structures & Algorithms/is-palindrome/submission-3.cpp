class Solution {
public:
    bool isPalindrome(string s) {
        
        int left =0, right = s.size()-1;
        char ch1, ch2;
        while(left < right)
        {
            while((left < right) && !isalnum(s[left])) left++;
            while((left < right) && !isalnum(s[right])) right--;
            
            if(left>right) return true;

            ch1 = tolower((unsigned char)s[left]);
            ch2 = tolower((unsigned char)s[right]);
            
            if(ch1 != ch2) return false;

            left++;
            right--;
        }
        return true;
    }
};
