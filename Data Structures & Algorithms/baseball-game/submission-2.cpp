class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &ch : operations)
        {
           if(st.size() >=2 && ch[0] =='+')
           {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            int third = first+second;
            st.push(first);
            st.push(second);
            st.push(third);
           }
           else if(!st.empty() && ch[0] == 'D')
           {
            int item = st.top();
            st.push(item * 2);
           }
           else if(!st.empty() && ch[0] == 'C')
           {
            st.pop();
           }
           else
           {
            int num =0;
            int i=0;
            int sign=1;
            if(ch[0]=='-')
            {
                sign =-1;
                i++;
            }
            while(i<ch.size())
            {
                num = num * 10 + (ch[i] -'0');
                i++; 
            }
            st.push(num*sign);
           }
        }
        
        int sum =0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};