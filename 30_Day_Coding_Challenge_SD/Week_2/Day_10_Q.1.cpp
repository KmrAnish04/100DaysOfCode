int viralAdvertising(int n) {
    int totalLiked=2;
    int shared=5;
    int liked=2;
    
    if(n>=2){
        for(int i=2; i<=n; i++){
            shared = 3*liked;
            liked = shared/2;
            totalLiked += liked;            
        }
    }
    
    return totalLiked;
}