bool helper(string A,int i,int j,bool flag){
    while(i<j){
        if(A[i]==A[j]){
            i++;
            j--;
        }else{
            if(flag){
              return helper(A,i+1,j,false) or helper(A,i,j-1,false);    
            }
            return false;
        }
    }
    
    return true;
}


int Solution::solve(string A) {
    int n = A.length();
    bool flag=true;
    return helper(A,0,n-1,flag);
}
