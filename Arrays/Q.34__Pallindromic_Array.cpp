// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.
    int ans = 0;
    
    
    for(int i=0; i<n; i++){
        
        string strNum = to_string(a[i]);
        if(strNum.length()>1){
            for(int j=0; j<strNum.length()/2; j++){
                if(strNum[j]==strNum[(strNum.length()-1)-j]){
                    ans=1;
                }
                else{
                    ans=0;
                    return ans;
                }
            }
        }
        else{
            ans=1;
        }
    }
        
    return ans;
    
}