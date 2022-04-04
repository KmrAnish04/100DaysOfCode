/*
    Problem: BFS traversal on directed Graph
    Question Link: 
        GFG:
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int k=0; k<matrix.size(); k++){
	        for(int i=0; i<matrix.size(); i++){
	            for(int j=0; j<matrix.size(); j++){
	                if(matrix[i][k]==-1 || matrix[k][j]==-1 || i==k || j==k) continue;
	                else if(matrix[i][j]==-1||matrix[i][k]+matrix[k][j]<matrix[i][j])
	                    matrix[i][j]=matrix[i][k]+matrix[k][j];
	            }
	        }
	    }
	}
};

