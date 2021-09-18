string angryProfessor(int k, vector<int> a) {
    int stdArrivedOnTime=0;
    
    for(int i=0; i<a.size(); i++){
        if(a[i]<=0) stdArrivedOnTime++;
    }
    
    if(stdArrivedOnTime>=k) return "NO";
    else return "YES";
}