class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int i=0;
        for(;i<digits.size();i++)
        {
            if(digits[i]==9)
            {
                digits[i] =0;
            }
            else
            {
                digits[i] +=1;
                break;
            }
        }

        if(i == digits.size()) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
