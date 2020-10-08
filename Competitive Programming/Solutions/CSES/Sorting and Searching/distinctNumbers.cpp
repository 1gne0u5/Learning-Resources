#include <iostream>

using namespace std;

// C++ program to count distinct elements in a given array 

int countDistinct(int arr[], int n) 
{ 
	int res = 1; 

	// Pick all elements one by one 
	for (int i = 1; i < n; i++) { 
		int j = 0; 
		for (j = 0; j < i; j++) 
			if (arr[i] == arr[j]) 
				break; 

		// If not printed earlier, then print it 
		if (i == j) 
			res++; 
	} 
	return res; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << countDistinct(arr, n); 
	return 0; 
} 