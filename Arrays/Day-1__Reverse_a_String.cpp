// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int length = str.length();
  char temp;
  int counter = length-1;
  
  for(int i = 0; i<length/2; i++){
      temp = str[i];
      str[i] = str[counter];
      str[counter] = temp;
      counter--;
  }
  
  return str;
}

//Anish