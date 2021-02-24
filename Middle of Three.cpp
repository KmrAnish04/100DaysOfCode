// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if( (A>B && A<C) || (A>C && A<B) ){
            return A;
        }
        else if( (B>A && B<C) || (B>C && B<A) ){
            return B;
        }
        else if( (C>B && C<A) || (C>A && C<B) ){
            return C;
        }
        
        /* Explanation:-
            1) when A is middle]
            Case(a) B - is first no. and C - is last no.
            Case(b) C - is first no. and B - is last no.
           
           2) when B is middle]
            Case(a) A - is first no. and C - is last no.
            Case(b) C - is first no. and A - is last no.
            
           3) when C is middle
            Case(a) B - is first no. and A - is last no.
            Case(b) A - is first no. and B - is last no.
        */
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends