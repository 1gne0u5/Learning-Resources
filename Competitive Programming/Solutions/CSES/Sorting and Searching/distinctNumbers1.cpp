#include <algorithm> 
#include <iostream> 

// C++ program to count all distinct elements in a given array 

using namespace std; 

int countDistinct(int arr[], int n) 
{ 
	/*First sort the array so that all 
    occurrences become consecutive 
    */
	sort(arr, arr + n); 

	// Traverse the sorted array 
	int res = 0; 
	for (int i = 0; i < n; i++) { 

		/*Move the index ahead while 
		there are duplicates 
        */
		while (i < n - 1 && arr[i] == arr[i + 1]) 
			i++; 

		res++; 
	} 

	return res; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << countDistinct(arr, n); 
	return 0; 
} 
