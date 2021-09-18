int utopianTree(int n) {
    int finalHeight = 1;
    
    if(n==0) return finalHeight;
    else{
        for(int i=1; i<=n; i++){
            if(i%2 != 0) finalHeight += finalHeight;
            else{
                finalHeight += 1;
            }
        }
    }
    
    return finalHeight;

}