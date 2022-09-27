
// combination sum

public class DP_10 {
    
    public static void main(String[] args) {
        
        int[] arr = {1,2,5};
        int target = 5;

        // by recursion
        System.out.println(solve(arr,target));

        // by top-down approach
        int[] dp = new int[target+1];
        for(int i=0 ; i<dp.length;i++){
            dp[i] = -1;
        }
        System.out.println(solve_1(arr,target,dp));

        // by botton-up approach
        System.out.println(slove_2(arr,target));
        
    }

    private static int slove_2(int[] arr, int target) {
        
        int[] dp = new int[target+1];
        for(int i=0 ; i<dp.length ;i++){
            dp[i] = 0;
        }

        dp[0] = 1;

        for(int i=1 ;i<dp.length ; i++){
            for(int j=0;j<arr.length;j++){
                if(i-arr[j] >=0)
                    dp[i] = dp[i] + dp[i-arr[j]];
            }
        }

        return dp[target];
    }

    private static int solve_1(int[] arr, int target, int[] dp) {
        // step-1
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }

        // step-3
        if(dp[target]!=-1){
            return dp[target];
        }

        // step-2
        int ans = 0;
        for(int i=0;i<arr.length;i++){
            ans = ans + solve_1(arr, target-arr[i], dp);
        }

        dp[target] = ans;

        return dp[target];

    }

    private static int solve(int[] arr, int target) {
        
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }

        int ans = 0;
        
        for(int i=0 ;i<arr.length ; i++){
            ans = ans + solve(arr, target-arr[i]) ;     
        }

        return ans;
    }
}
