/*
    Problem: First Non Reapeating Character In a Stream
    Question Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

    Complexity Analysis:
        Time: O(26 * n)
        Space: O(26)
*/

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> ordQue;
		    unordered_map<char, int> freq;
		    string ans="";
		    
		    for(int i=0; i<A.length(); i++){
		        
		        if(freq[A[i]]<1){
		            freq[A[i]]++;
		            ordQue.push(A[i]);
		        }
		        else
    		        freq[A[i]]++;
    		        
		        
		        while(!ordQue.empty() && freq[ordQue.front()]>1)
		            ordQue.pop();
		        
		        if(i != 0 && ordQue.empty())
    		        ans.push_back('#');
		        else
		            ans.push_back(ordQue.front());
		    }
		    
		    return ans;
		}

};