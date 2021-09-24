int findDigits(int n) {
    int r=n;
    int count = 0;
    
    while(r > 0){
        if(r % 10 != 0 && n % (r % 10) == 0) count++;
        r = r / 10;
    }
    
    return count;
}