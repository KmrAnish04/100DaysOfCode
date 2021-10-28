class Solution{
    bool isInteger(double N)
        {
         
            // Convert float value
            // of N to integer
            int X = N;
         
            double temp2 = N - X;
         
            // If N is not equivalent
            // to any integer
            if (temp2 > 0) {
                return false;
            }
            return true;
        }
public:
    int inSequence(int A, int B, int C){
        // code here
        if((A<0 && C<0 && B>=0) || (A>=0 && C>=0 && B<0) || (A>B && C>=0) 
        || (A<B && C<0)) return 0;
        
        double nthTerm = (double(B-A)/(double)C)+1;
        return isInteger(nthTerm);
    }
};
