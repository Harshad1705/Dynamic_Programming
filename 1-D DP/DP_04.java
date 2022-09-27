
// minimum number of coins to get target sum

public class DP_04 {

    public static void main(String[] args) {

        int[] coins = { 1,2,3};
        int target = 7 ;
        int n = target+1;

        // by recurssion
        System.out.println(solve(coins,target));
        
        // by top-down approach
        int[] dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        System.out.println(solve_2(coins,target,dp));

        // by bottom-up apprach
        System.out.println(solve_3(coins,target));

    }

    private static int solve_3(int[] coins, int target) {

        // Time complexity = O(conis.size() * target)
        // Space complexity = O(dp.size)
        
        int[] dp = new int[target+1];
        for(int i = 0 ;i<dp.length ; i++){
            dp[i] = Integer.MAX_VALUE;
        }

        dp[0] = 0;

        for(int i=1 ; i<=target;i++){
            for(int j = 0 ;j<coins.length ; j++){
                if((i-coins[j]>=0) && (dp[i-coins[j]] != Integer.MAX_VALUE))
                    dp[i] = Math.min(dp[i] , 1 + dp[i-coins[j]]);
            }
        }

        if(dp[target]==Integer.MAX_VALUE){
            return -1;
        }
        return dp[target];
    }

    private static int solve_2(int[] coins, int target, int[] dp) {

        // Time complexity = O(conis.size() * target)
        // Space complexity = O(dp.size) + O(dp.size)

        // step-1
        if(target==0){
            return 0;
        }
        if(target<0){
            return Integer.MAX_VALUE;
        }

        // step-3
        if(dp[target] != -1){
            return dp[target];
        }

        // STEP-2
        int mini = Integer.MAX_VALUE;

        for(int i=0 ; i< coins.length ; i++){
            int ans = solve(coins, target-coins[i]);
            if(ans!=Integer.MAX_VALUE){
                mini = Math.min(mini, 1+ans);
            }
        }

        dp[target] = mini;

        return dp[target];
        
    }

    private static int solve(int[] coins, int target) {

        // Time complexity = exponential

        if(target==0){
            return 0;
        }
        if(target<0){
            return Integer.MAX_VALUE;
        }

        int n = coins.length;
        int mini = Integer.MAX_VALUE;

        for(int i=0 ; i<n ; i++){

            int ans = solve(coins, target-coins[i]);

            if(ans!=Integer.MAX_VALUE){
                mini = Math.min(mini, 1+ans);
            }
        }

        return mini;
    }


    
}
