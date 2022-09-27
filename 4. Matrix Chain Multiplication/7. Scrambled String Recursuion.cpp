class Solution {
public:
    
     bool solve(string a , string b){
        
        if(a.compare(b)==0){
            return true;
        }
        
        
        bool flag = false;
        int n = a.length();
        
        for(int i=1 ;i<n;i++){
                  
            bool case1 = (solve(a.substr(0,i),b.substr(n-i,i))&&solve(a.substr(i,n-i),b.substr(0,n-i)));
            bool case2 = (solve(a.substr(0,i),b.substr(0,i))&&solve(a.substr(i,n-i),b.substr(i,n-i)));
            
            if(case1||case2){
                flag = true;
                break;
            }
            
        }
         
         return flag;
     }

    

    bool isScramble(string s1, string s2) {
        
        if(s1.length() != s2.length()){
            return false;
        }
        
        if(s1.length()==0 && s2.length()==0){
            return true;
        }
        
        return solve(s1,s2);
    }
};