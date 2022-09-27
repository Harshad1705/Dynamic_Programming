
// min cost climbing stairs 

public class DP_03 {

    public static void main(String[] args) {

        int heigth_of_stairs = 3 ;
        int[] cost = {10,15,20};
        
        // by recurssion
        int answer =  Math.min(solve(cost, heigth_of_stairs-1) , solve(cost, heigth_of_stairs - 2));
        System.out.println(answer);

        // by top down-approach
        int[] dp = new int[heigth_of_stairs+1];
        for(int i=0;i<dp.length;i++){
            dp[i] = -1;
        }
        int ans = Math.min(solve_2(cost,heigth_of_stairs-1,dp),solve_2(cost,heigth_of_stairs-2,dp));
        System.out.println(ans);

        // by bottom up approach 
        System.out.println(solve3(cost, heigth_of_stairs));

        // space utilization in bottom-up
        System.out.println(solve4(cost, heigth_of_stairs));
    }


    
    public static int  solve(int[] cost, int i) {
        if(i==1){
            return cost[1] ;
        }
        if(i==0){
            return cost[0] ;
        }
        int ans = cost[i] + Math.min(solve(cost, i-1), solve(cost, i-1));
        return ans;
    }
 
    public static int solve_2(int[] cost, int i, int[] dp) {

        // Time complexity : O(n)
        // Space complexity : O(n) + O(n)
        
        // step-1 : base case
        if(i==0){
            return cost[0];
        }
        if(i==1){
            return cost[1];
        }

        // step-3 : if value already exist
        if(dp[i] != -1){
            return dp[i];
        }

        // step-2 : claculate value amd insert in array

        dp[i] = cost[i] + Math.min(solve(cost, i-1), solve(cost, i-1));

        return dp[i];

    }

    public static int solve3(int[] cost , int height){

        // Time complexity : O(n)
        // Space complexity : O(n)  

        // step-1 : create array
        int[] dp = new int[height+1];

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2 ; i<height ; i++){
            dp[i] = cost[i] + Math.min(dp[i-1],dp[i-2]);
        }

        return Math.min(dp[height-1],dp[height-2]);

    }
    public static int solve4(int[] cost , int height){

        // Time complexity : O(n)
        // Space complexity : O(1)  

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2 ; i<height ; i++){
            int curr = cost[i] + Math.min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;

        }

        return Math.min(prev1, prev2);

    }

    
}
