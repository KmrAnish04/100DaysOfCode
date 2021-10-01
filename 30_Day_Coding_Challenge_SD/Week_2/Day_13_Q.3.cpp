// Solution by Anish
long taumBday(long b, long w, long bc, long wc, long z) {
    long long minCost;
    if((bc==wc) || (bc>wc && (bc==wc+z || bc<wc+z)) || (wc>bc && (wc==bc+z || wc<bc+z))){
        minCost = ((long long)(b*bc) + (long long)(w*wc));
        return minCost;
    }
    else if(bc>wc && bc>wc+z){
        // conversion happens
        long long totalGifts = (long long)b+w;
        minCost = ((long long)(totalGifts*wc) + (long long)(b*z));
    }
    else if(wc>bc && wc>bc+z){
        // conversion happens
        long long totalGifts = (long long)b+w;
        minCost = ((long long)(totalGifts*bc) + (long long)(w*z));
    }
        
    return minCost;
}


// Same logic as above but shorter code
long taumBday(long b, long w, long bc, long wc, long z) {
    
    long long res = (long long)b * bc + (long long)w * wc;
    res = min(res, (long long)b * bc + (long long)w * (bc + z));
    res = min(res, (long long)b * (wc + z) + (long long)w * wc);
    
    return res;   
}
