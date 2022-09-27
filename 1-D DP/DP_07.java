
// cut into segments  or  Rod cutting problem

public class DP_07 {

    public static void main(String[] args) {
        
        int[] arr = {5,2,2};
        int length = 7;

        // by recursion 
        System.out.println(solve(arr,length));

        // by top-down approach
        int[] dp = new int[length+1];
        for(int i=0;i<dp.length ; i++){
            dp[i] = -1;
        }
        System.out.println(solve_2(arr,length,dp));

        // by bottom-up approach
        System.out.println(solve_3(arr,length));
    }

    private static int solve_3(int[] arr, int length) {

        // step-1
        int[] dp = new int[length+1];

        for(int i=0 ; i < dp.length ; i++){
            dp[i] = Integer.MIN_VALUE;
        }

        // step-2
        dp[0] = 0;

        // step-3
        for(int i=1 ; i<dp.length ; i++){
            if(i-arr[0] >=0){
                dp[i] = Math.max(dp[i], dp[i-arr[0]] + 1);
            }
            if(i-arr[1] >=0){
                dp[i] = Math.max(dp[i], dp[i-arr[1]] + 1);
            }
            if(i-arr[2] >=0){
                dp[i] = Math.max(dp[i], dp[i-arr[2]] + 1);
            }
        }

        if(dp[length]<0){
            return 0;
        }
    
        return dp[length];
        
    }

    private static int solve_2(int[] arr, int length, int[] dp) {
        // step-1
        if(length==0){
            return 0;
        }
        if(length<0){
            return Integer.MIN_VALUE;
        }

        // step-3
        if(dp[length]!=-1){
            return dp[length];
        }

        // step-2
        int a = solve_2(arr, length-arr[0], dp ) + 1;
        int b = solve_2(arr, length-arr[1], dp ) + 1;
        int c = solve_2(arr, length-arr[2], dp ) + 1;

        int ans = Math.max(c, Math.max(a, b));

        dp[length] = ans;

        return dp[length];
        
    }

    private static int solve(int[] arr, int length) {
        
        if(length<0){
            return Integer.MIN_VALUE ;
        }
        if(length==0){
            return 0;
        }

        int a = solve(arr, length-arr[0]) + 1;
        int b = solve(arr, length-arr[1]) + 1;
        int c = solve(arr, length-arr[2]) + 1;

        int ans = Math.max(c,Math.max(a, b));

        return ans;
    }

    
}
