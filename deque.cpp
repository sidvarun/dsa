// Circular tour - https://practice.geeksforgeeks.org/problems/circular-tour/1#
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
           int currSum = 0;
           int prevSum = 0;
           int start = 0;
           for(int i = 0; i<n; i++){
               currSum += p[i].petrol - p[i].distance;
               if(currSum < 0){
                   prevSum += currSum;
                   start = i+1;
                   currSum = 0;
               }
           }
            if(currSum + prevSum >= 0)
                return start;
            return -1;
     
    }
};

/*********************************************************************/
