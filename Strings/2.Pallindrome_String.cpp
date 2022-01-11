class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int j=S.length()-1;
	    bool isPalin = true;
	    for(int i=0; i<S.length()/2; i++){
	        if(S[i]!=S[j]){
	            isPalin = false;
	            break;
	        }
	        j--;
	    }
	    
	    return isPalin;
	}

};