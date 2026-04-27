class Solution {

    int excceed = 0;
public:
     void sumUp(vector<int> &v, int start,int end, int passengers, int capacity)
     {
        for(int i = start; i<end;i++)
        {
            v[i] += passengers;
            if(v[i] > capacity) 
            {
                excceed = -1;
                break;
            }
        }
     }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int start =0, end =0; 
        
        vector<int> v(1001, 0);
        for(auto &trip : trips)
        {
            start = trip[1];
            end = trip[2];
            sumUp(v, start, end, trip[0], capacity);
            if(excceed == -1) return false;
           }

        return true;
        
    }
};