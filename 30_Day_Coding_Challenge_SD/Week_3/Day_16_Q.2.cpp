int chocolateFeast(int n, int c, int m) {
    int choc=0;
    int wraps=0;
    choc = wraps = n/c;
    while(wraps>=m){
        choc += wraps/m;
        int tmpwrp = wraps/m;
        tmpwrp += wraps%m;
        wraps = tmpwrp;
    }
    return choc;
}
