#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isRotated(string sA, string sB){
	
	vector<int> idxs;

    if(sA.length() != sB.length()) return false;

    // pushing indexes in idxs array
	for (int i = 0; i < sB.length(); ++i)
	{
		if (sA[0] == sB[i])
			idxs.push_back(i);
	}

	bool flag = false;
	for (int i = 0; i < idxs.size(); i++)
	{
		int j=0;
		while( sA[j] == sB[ (idxs[i] + j)%sA.length() ] && j<sA.length() ){
			flag = true;
			j++;
		}
		if (flag == true && j==sA.length())
		{
			return true;
		}
		else flag=false;
	}

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