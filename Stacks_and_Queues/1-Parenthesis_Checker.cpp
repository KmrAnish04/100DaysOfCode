/*
    Algorithm:  
    
    Declare a character stack S.
    
    Now traverse the string.  If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) 
    then push it into stack. If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) 
    then compare it with top of stack.
    
    If top of stack has opening bracket of different type then brackets are not balanced so return 
    false else pop the top element from stack.
    
    After complete traversal, if there is some starting bracket left in stack then return false else true.
*/



/*
    My Solution
    Question Link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

    Complexity Analysis:
    
*/
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        
        if(x.length()<2) return false;
        
        for(int i=0; i<x.length(); i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                char ele=x[i];
                stk.push(ele);
            }
            else if(!stk.empty() && (x[i]==')' || x[i]=='}' || x[i]==']')){
                if(x[i] == ')' &&  stk.top()=='(' ){
                    stk.pop();
                }
                else if(stk.top()=='{' && x[i]=='}') stk.pop();
                
                else if(stk.top()=='[' && x[i]==']') stk.pop();
                
                else return false;
            }
            else return false;
        }
        
        return stk.empty();
    }

};



// Solution from GFG
class Solution
{
    public:
    //Function to check if opening and closing brackets are of same type.
    bool cmp(char b,char c)
    {
        if(b=='{' && c=='}')
            return true;
        else if(b=='[' && c==']')
            return true;
        else if(b=='(' && c==')')
            return true;
         return false;
    }
    
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        
        //iterating over the string.
        for(int i=0;i<x.size();i++)
        {
            //if opening bracket is encountered, we push it into stack.
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
                s.push(x[i]);
            
            //if closing bracket is encountered, we compare it with top of stack.
            else if(x[i]==']' || x[i]=='}' || x[i]==')')
            {
                //if top of stack has opening bracket of different
                //type, we return false.
                if(s.empty() || !cmp(s.top(),x[i])) 
                    return false;
                //else we pop the top element from stack.
                else
                    s.pop();
            }
        }
        //if stack becomes empty, we return true else false.
        if(s.empty())
            return true;
        else
            return false;
    }
};