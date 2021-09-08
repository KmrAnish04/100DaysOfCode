int birthdayCakeCandles(vector<int> candles) {
    int tall=candles[0];
    int cnt=0;
    for(int i=1; i<candles.size(); i++){
        tall = max(tall, candles[i]);
    }
    for(int j=0; j<candles.size(); j++){
        if(candles[j]==tall) cnt++;
    }
    
    return cnt;
}