class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int i;
         
         vector<vector<int>> B(n , vector<int>(n,0));
   
       
        
        int top =0, bottom = n-1;
        int left = 0, right = n-1;
    
        int count = 1;
   	while(left<=right && top <=bottom)
	{
	    if(left < right)
	    {
    		for(i=left; i<=right; i++)
    		{
    			B[top][i] = count++;   		
    		}
    		top++;
	    }

		if(top < bottom)
		{
			for(i=top; i<=bottom; i++)
			{
				B[i][right] = count++;				
			}
			right--;
		}

		if(left <= right)
		{
			for(i=right; i>=left; i--)
			{
				B[bottom][i] = count++;				
			}
			bottom--;
		}

		if(top <= bottom)
		{
			for(i=bottom; i>=top; i--)
			{
				B[i][left] = count++;               
			}
			left++;
		}		
	}
    
    return B; 
    }
};