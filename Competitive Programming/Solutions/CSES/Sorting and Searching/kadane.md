# Kadane’s Algorithm:

**Initialize:**  
    max_so_far = 0  
    max_ending_here = 0  

Loop for each element of the array  
- max_ending_here = max_ending_here + a[i]  
- if(max_so_far < max_ending_here)  
    `max_so_far = max_ending_here`  
- if(max_ending_here < 0)  
`   max_ending_here = 0`   
`   return max_so_far`

_Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far_


