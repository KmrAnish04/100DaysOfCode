// Optimized Approch
// Time Complexity = O(N)
// Space Complexity = O(1)
int designerPdfViewer(vector<int> h, string word) {
    int stringSize = word.size();
    int ans=0;
    int maxHgt=INT_MIN;
    
    for(int i=0; i<stringSize; i++){
        int asciVal = int(word[i]);
        int index = asciVal-97;
        maxHgt = max(h[index], maxHgt);
    }
    
    ans = maxHgt * stringSize;
    
    return ans;

}





// Using binary search
// Time Complexity = O(nlog n) approx
// Space Complexity = O(1)

int binarySearch(int left, int right, int k){
    int arr[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                   111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
                   
    /* 
        int arr[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                       111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
                       
        is equal to
    
        char arr[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
                        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}
    */
    
                   
    int mid = (left+right)/2;
    
    if(arr[mid]==k){
        return mid;
    }
    else if(k < arr[mid]){
        return binarySearch(left, mid-1, k);
    }
    
    return binarySearch(mid+1, right, k);
            
}
 

int designerPdfViewer(vector<int> h, string word) {
    int stringSize = word.size();
    int ans=0;
    int maxHgt=INT_MIN; // max height of characters
    
    for(int i=0; i<stringSize; i++){
        int asciiVal = int(word[i]); // getting ASCII value of character of word string
        
        int charIndex=binarySearch(0, 25, asciiVal);// binary search fucntion returns the index of the charcter in the ASCII array of lower case letters. 
         
        maxHgt = max(h[charIndex], maxHgt); // keeping the record of max character height
        
    }
    
    ans = maxHgt * stringSize; // calculating the area of highlighted rectangle
    
    return ans;

}


