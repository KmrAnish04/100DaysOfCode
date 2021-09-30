#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string organizingContainers(vector<vector<int>> container) {
    int Size=container.size();
    vector<int> contSizes;
    vector<int> ballCnt;
    
    for(int i=0; i<Size; i++){
        int contSum=0;
        for(int j=0; j<Size; j++){
            contSum += container[i][j];
        }
        contSizes.push_back(contSum);
    }    
    
    for(int i=0; i<Size; i++){
        int ballSum=0;
        for(int j=0; j<Size; j++){
            ballSum += container[j][i];
        }
        ballCnt.push_back(ballSum);
    }  
    
    for(int i=0; i<contSizes.size(); i++) cout<<contSizes[i]<<" ";
    cout<<endl;
    for(int i=0; i<ballCnt.size(); i++) cout<<ballCnt[i]<<" ";

    sort(contSizes.begin(), contSizes.end());
    sort(ballCnt.begin(), ballCnt.end());

    if(contSizes==ballCnt) return "Possible";
    
    return "Impossible";

}

int main(){
    vector<vector<int>> arr={{2, 1, 1, 1}, {2, 1, 2, 1}, {1, 2, 4, 1}, {5, 2, 1, 2}};
    string s = organizingContainers(arr);
    cout<<endl;
    cout<<s;

    return 0;
}
