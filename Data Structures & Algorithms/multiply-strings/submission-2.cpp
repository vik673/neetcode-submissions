class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int size = n1+n2;

        vector<int> result(size, 0);
        int mul;
        int pos1 =0, pos2 =0, sum =0;
        bool leadingZero = false;
        string res="";

        for(int i= n1-1; i>=0;i--)
        {
            for(int j = n2-1; j>=0;j--)
            {
                pos1 = i+j;
                pos2 = i+j+1;
                
                mul = (num1[i] - '0') * (num2[j] -'0');
                sum = mul + result[pos2];
                result[pos2] = sum%10;
                result[pos1] += sum/10;
            }
        }

        for(int i=0;i<result.size();)
        {
            if(!leadingZero)
            {
                if(result[i] == 0)
                {
                    i++;
                } 
                if(result[i] !=0)
                { 
                    leadingZero = true; 
                }
            }
            else
            {
                res += (result[i] +'0');
                i++;
            }
        }
        if(res.empty()) return "0";
        return res;

    }
};
