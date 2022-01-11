#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isRotated(string sA, string sB){
	
	cout<<"stg 1";
	vector<int> idxs;
    
	cout<<"stg 2";
    if(sA.length() != sB.length()) return false;

    cout<<"stg 3";
    // pushing indexes in idxs array
	for (int i = 0; i < sB.length(); ++i)
	{
		if (sA[0] == sB[i])
			idxs.push_back(i);
	}

	cout<<"stg 4";

	bool flag = false;
	for (int i = 0; i < idxs.size(); ++i)
	{
		int j=0;
		while( sA[j] == sB[ (idxs[i] + j)%sA.length() ] && j<sA.length() ){
			flag = true;
			j++;
		}
		if (flag == true && j==sA.length()-1)
		{
			return true;
		}
		else flag=false;
	}

	// if (flag == true)
	// {
	// 	return true;
	// }

	cout<<"stg 5";
	// printing idxs array
	for (int i = 0; i < idxs.size(); ++i)
	{
		cout<<idxs[i];
	}

	cout<<"stg 6";
	return false;
}

int main(){

	string s1;
	string s2;

	cin>>s1>>s2;

	// cout<<s1<<", "<<s2;
	bool result = false;
	result = isRotated(s1, s2);

	cout<<"The result = "<< result;


	return 0;
}