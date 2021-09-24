// returns prefix
// int prefix(int num){
//     int pre;
//     while(num>=10){
//         num=num/10;
//     }
//     pre=num;
//     cout<<"prefix="<<pre;
//     return pre;
// }

// returns num which will become prefix later
// int sufix(int num){}


int findDigits(int n) {
    // n=1012;
    int qui=n/10;
    int rem=n%10;
    vector<int> nums;
    // int cnt=0;
    
    cout<<"qui="<<qui<<endl;
    cout<<"rem="<<rem<<endl;
    
    if(n%qui==0 && qui<=9) nums.push_back(qui);
    if(n%rem==0) nums.push_back(rem);
    while(qui>=10){
        rem = qui%10;
        cout<<"qui="<<qui<<endl;
        cout<<"rem="<<rem<<endl;
        if(n%rem==0) nums.push_back(rem);
        qui = qui/10;
    }
    if(n%qui==0 && qui<=9) nums.push_back(qui);
    if(n%rem==0) nums.push_back(rem);
    // while(rem>=10){
    //     cout<<"In while";
    //     int preNum=prefix(qui);
    //     nums.push_back(preNum);
    //     qui=rem/10;
    //     rem=rem%10;
    // }
    // nums.push_back(qui);
    // nums.push_back(rem);
    
    cout<<"starting ";
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
    
    return 9;
}