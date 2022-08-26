#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int M, int N){
//CODE HERE 
    vector<string> ans;
    string design = ".|.";
    int noOfDgnOcc=1;

    for(int row=1; row<=M; row++){
        string rowRst = "";

        int noOfDashes = ((N-(3*noOfDgnOcc))/2);
        for(int col=1; col<=noOfDashes; col++){
            rowRst+="-";
        }

        // for middle row
        if(row == (M/2)+1){
            for(int k=1; k<=(N-9)/2; k++){
                rowRst+="-";
            }
            rowRst+="DEVSNEST!";
            for(int k=1; k<=(N-9)/2; k++){
                rowRst+="-";
            }
        }
        else if(row<=M/2){
            for(int noOfDgn=1; noOfDgn<=noOfDgnOcc; noOfDgn++){
                rowRst+=design;
            }
            noOfDgnOcc+=2;
        }
        else if(row>(M/2)+1){
            for(int noOfDgn=noOfDgnOcc; noOfDgn>=1; noOfDgn--){
                rowRst+=design;
            }
            noOfDgnOcc-=2;
        }
        for(int col=noOfDashes; col>=1; col--){
            rowRst+="-";
        }

        if(row==(M/2)+1){
            noOfDgnOcc-=2;
        }
        ans.push_back(rowRst);
    }

    return ans;
}



int main(){
    int m;
    int n;

    cin>>m;
    cin>>n;

    vector<string> ans = solve(m,n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}