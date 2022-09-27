class Solution{
    
    static int[][] dp;
    
    public static int solve(int arr[] , int i , int j){
        
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int min = Integer.MAX_VALUE;
        
        for(int k=i ; k<j ; k++){
            
            int temp = solve(arr,i,k) + solve(arr,k+1 , j) + 					(arr[i-1]*arr[k]*arr[j]) ; 
            
            if(temp < min){
                min = temp;
            }
            
        }
        
        dp[i][j] = min;
        
        return dp[i][j];
        
    }
    
    
    static int matrixMultiplication(int N, int arr[])
    {
        dp = new int[601][501];
        
        for(int i=0 ; i<dp.length ;i++){
            Arrays.fill(dp[i],-1);
        }
        
        return solve(arr,1,N-1);
    }
}