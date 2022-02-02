/*
    Problem: Circular Tour
    Question Link: https://practice.geeksforgeeks.org/problems/circular-tour/1#

    Complexity Analysis:
        Time: O(N)
        Space: O(1)
*/

// My Solution (very easy to understand with 50% GFG Accuracy)
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int count=0,count2=0;
       for(int i=0;i<n;i++){
           count+=p[i].petrol;
           count2+=p[i].distance;
       }
       //what if sum of total petrol is smaller than distance
       //then whats the need to check through
       if(count<count2) return -1;
       
       
       // The Main Approch
       int start=0;
       int end=0;
       int carry=0;
       int i=1;
       while(i!=n){
           if(carry+p[end].petrol>=p[end].distance){
               carry=carry+p[end].petrol-p[end].distance;
               end=(end+1)%n;
               i++;
           }
           else{
               end=(end+1)%n;
               carry=0;
               start=end;
               i=1;
           }
       }
       
       return start;
    }
};



/*
    GFG Algorithm:

        Brute-Force Approch:
            A Simple Solution is to consider every petrol pumps as a starting point and see if there is a possible tour. 
            If we find a starting point with a feasible solution, we return that starting point. The worst case time complexity
            of this solution is O(n^2).
        
        Optimal Approch:
            An efficient approach is to use a Queue to store the current tour. 
            We first enqueue first petrol pump to the queue, we keep enqueueing petrol pumps till we either complete the tour,
            or the current amount of petrol becomes negative. If the amount becomes negative, 
            then we keep dequeuing petrol pumps until the queue becomes empty.
            
            Instead of creating a separate queue, we use the given array itself as a queue. We maintain two index
            variables start and end that represent the rear and front of the queue.
*/


// Solution by GFG
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        //considering first petrol pump as a starting point.
        int start = 0;
        int end=1;
        int cur_pet = p[start].petrol-p[start].distance;
        
        //we run a loop while all petrol pumps are not visited and we have 
        //reached first petrol pump again with 0 or more petrol.
        while(end!=start or cur_pet <0)
        {
            //if current amount of petrol in truck becomes less than 0,
            //then remove the starting petrol pump from tour.
            while(cur_pet<0 and  start!=end)
            {
                //removing starting petrol pump and changing starting point. 
                cur_pet -=p[start].petrol-p[start].distance;
                start=(start+1)%n;
                
                //if 0 is being considered as start again, then there 
                //is no possible solution.
                if(start==0)
                    return -1;
            }
            //adding a petrol pump to current tour.
            cur_pet +=p[end].petrol - p[end].distance;
            end=(end+1)%n;
        }
        //returning starting point. 
        return start;
    }
};