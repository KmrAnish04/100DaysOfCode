class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        vector<int> arr={A , B, C};
        sort(arr.begin(), arr.end());
        return arr[1];
    }
};