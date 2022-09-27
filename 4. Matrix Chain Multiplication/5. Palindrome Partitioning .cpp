
class Solution{
    
    static int[][] t;
    
    public static boolean isPalindrome(String s , int i , int j){

        while(i<j){
            
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
        
    }
    
    public static int solve(String s , int i , int j){
        
        if(i>=j){
            return 0;
        }
        
        if(isPalindrome(s,i,j)==true){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int mini = Integer.MAX_VALUE;
        
        for(int k=i ; k<j ; k++){
            int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
            
            if(temp < mini){
                mini = temp;
            }
        }
        
        t[i][j] = mini;
        
        return t[i][j];
        
    }
    
    
    static int palindromicPartition(String str)
    {
        int n = str.length();
        
        t = new int[n+1][n+1];
        
        for(int i=0 ; i<n+1 ; i++){
            Arrays.fill(t[i],-1);
        }
        
        return solve(str,0,str.length()-1);
    }
}