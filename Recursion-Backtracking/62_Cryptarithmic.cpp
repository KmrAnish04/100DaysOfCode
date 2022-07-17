// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding:
        nados:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

int getNum(string str, map<char,int>mp){
    int num;
    string numStr="";
    
    for(int i=0; i<str.length(); i++){
        string nmCh = to_string(mp[str[i]]);
        numStr+=nmCh;
    }
    
    num = stoi(numStr); 
    return num;
} 

void Solution(string uqStr, map<char,int>&mp, vector<bool>&nums, string s1, string s2, string s3, int idx){
    
    if(idx==uqStr.length()){
        int num1 = getNum(s1, mp);
        int num2 = getNum(s2, mp);
        int num3 = getNum(s3, mp); 
        
        if(num3==num1+num2){
            
            for(auto it: mp){
                if(it.first>=97 && it.first<=122){
                    cout<<it.first<<"-"<<it.second<<" ";
                }
            }
            // for(int i=0; i<26; i++){
            //     char ch='a'+i;
            //     if(mp[ch]){
            //         cout<<ch<<"-"<<mp[ch]<<" ";
            //     }
            // }
            cout<<endl;
            return; 
        }
    }
    
    
    char ch=uqStr[idx];
    for(int i=0; i<=9; i++){
        if(nums[i]==false){
            mp[ch]=i;
            nums[i]=true;
            Solution(uqStr, mp, nums, s1, s2, s3, idx+1);
            mp[ch]=-1;
            nums[i]=false;
        }
    }
}


int main(){
    string str1;
    string str2;
    string str3;
    
    cin>>str1;
    cin>>str2;
    cin>>str3;
    
    string uqStr="";
    map<char,int> mp;
    for(int i=0; i<str1.length(); i++){
        if(mp[str1[i]]==0){
            uqStr+=str1[i];
            mp[str1[i]]++;
        }
    }
    for(int i=0; i<str2.length(); i++){
        if(mp[str2[i]]==0){
            uqStr+=str2[i];
            mp[str2[i]]++;
        }
    }
    for(int i=0; i<str3.length(); i++){ 
        if(mp[str3[i]]==0){
            uqStr+=str3[i];
            mp[str3[i]]++;
        } 
    } 
    for(auto it: mp){
        mp[it.first]=-1;
    }
    // cout<<uqStr<<endl;
    // for(auto it: mp){
    //     cout<<it.first<<": "<<it.second<<endl;
    // }
    
    vector<bool> numUsed(10, false);
    
    Solution(uqStr, mp, numUsed, str1, str2, str3, 0);
    
    // map<char,int>mps; 
    // string ss="";  
    // for(int i=1; i<9; i++){    
    //     char ch=char(97+i);
    //     ss+=ch;
    //     mps[ch]=i;
    // }
    // for(auto it: mps){
    //     cout<<it.first<<": "<<it.second<<endl;
    // }
    // cout<<ss<<endl;
    // cout<<getNum(ss, mps);
    
    return 0;
    
    
}


