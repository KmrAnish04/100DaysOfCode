#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isShuffled(string sA, string sB, string reslut){

	if (sA.length()+sB.length() != reslut.length()) return false;

	int i=0,j=0;
	for (int k = 0; k < reslut.length(); k++)
	{
		if (reslut[k]==sA[i]) i++;
		else if(reslut[k]==sB[j]) j++;
		else return false;
	}
	
	return true;

}

int main(){

	string s1;
	string s2;
	string reslut;

	cin>>s1>>s2>>reslut;
	// cout<<s1<<", "<<s2<<", "<<reslut;

	bool ans = isShuffled(s1, s2, reslut);
	cout<<ans;

	return 0;
}