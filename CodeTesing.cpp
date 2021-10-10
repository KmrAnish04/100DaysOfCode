// #include<iostream>
// #include<map>
// // #include<unordered_map>
// #include<vector>
// using namespace std;


// int main()
// {
//     // unordered_map<int, int>map;
//     // map[1] = 1;
//     // map[20] = 3;

//     // printf("%d", map[20]);
//     // map[20]++;
//     // printf("%d", map[20]);

//     // int arr[] = {1,2,5,1,20,80,5,20,100,80,1,20};
//     // int count = 0;
//     // unordered_map<int,int>mapArr;
        
//     // for(int i=0; i<11; i++){
//     //     // int x = k-arr[i];
        
//     //     if(mapArr[arr[i]]==0){
//     //         mapArr[arr[i]]++;
//     //     }
//     //     else{
//     //         // count += mapArr[x];
//     //         mapArr[arr[i]]++;
//     //     }
//     // }

//     // for (auto x : mapArr){
//     //     // cout << x.first << " " << x.second << endl;
//     //     if (x.second>=2)
//     //     {
//     //         cout<<"This element occurs more than 1 times:"<<x.first<<endl;
//     //     }
//     // }   
//     int n1=6, n2=5, n3=8;
//     int A[n1] = {1, 5, 10, 20, 40, 80};
//     int B[n2] = {6, 7, 20, 80, 100};
//     int C[n3] = {3, 4, 15, 20, 30, 70, 80, 120};
//     vector<int> wholeArr;
//     map<int,int>mapArr;
//     map<int,int>mapBrr;
//     map<int,int>mapCrr;
//     vector<int> result;
            
//     for(int i=0; i<n1; i++){
//         wholeArr.push_back(A[i]);
//         if(mapArr[A[i]] == 0){
//             cout<<"in for loop of mapA\n";
//             mapArr[A[i]] = 1;
//         }
//     }
//     for(int i=0; i<n2; i++){
//         wholeArr.push_back(B[i]);
//         if(mapBrr[B[i]] == 0){
//             cout<<"in for loop of mapB\n";
//             mapBrr[B[i]] = 1;
//         }
//     }
//     for(int i=0; i<n3; i++){
//         wholeArr.push_back(C[i]);
//         if(mapCrr[C[i]] == 0){
//             cout<<"in for loop of mapC\n";
//             mapCrr[C[i]] = 1;
//         }
//     }

//     // printf("%d", wholeArr[3]);

//     // for(auto i = wholeArr.begin(); i != wholeArr.end(); ++i)
//     //     cout << *i << " ";

    
        
//     for(int i=0; i<wholeArr.size(); i++){
//         // int x = k-arr[i];
//         cout<<wholeArr[i]<<" ";
//         if(mapArr[wholeArr[i]]==1 && mapBrr[wholeArr[i]]==1 && mapCrr[wholeArr[i]]==1){
//             // mapArr[wholeArr[i]]++;
//             cout<<"pushing to result array\n";
//             result.push_back(wholeArr[i]);
//         }
//         // else{
//         //     // count += mapArr[x];
//         //     mapArr[wholeArr[i]]++;
//         // }
//     }

//     for (int i = 0; i<result.size(); i++)
//     {
//         cout<<"printing reult array\n";
//         cout<<result[i]<<endl;
//     }
    

//     // for (auto x : mapArr){
//     //     // cout << x.first << " " << x.second << endl;
//     //     if (x.second>=3)
//     //     {
//     //         result.push_back(x.first);
//     //         cout<<"This element occurs more than 1 times:"<<x.first<<endl;
//     //     }
//     // }   


//     return 0;
// }









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
