import java.util.ArrayList;

// House robbery problem

public class DP_06 {

    // Time complexity = O(n)
    // Space complexity = O(n)
    
    public static void main(String[] args) {
        
        int[] arr = {1,2,3,1};

        ArrayList<Integer> first = new ArrayList<>();
        ArrayList<Integer> second = new ArrayList<>();

        for(int i=0 ;i<arr.length ;i++){
            if( i != arr.length-1){
                first.add(arr[i]);
            }
            if(i != 0){
                second.add(arr[i]);
            }
        }
        

        int ans_1 = solve(first , first.size()-1);
        int ans_2 = solve(second , second.size()-1);

        int answer = Math.min(ans_1, ans_2);

        System.out.println(answer);
    }



    private static int solve(ArrayList<Integer> first, int n) {
        
        int prev2 = 0;
        int prev1 = first.get(0);

        for(int i=1 ; i<first.size() ; i++){
            int include = prev2 + first.get(i);
            int exclude = prev1;

            int ans = Math.max(include , exclude);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

}
