// C++ program for Implementing 
// prefix sum array 
// use to calculate sum of array element in a given range in the time complexity of O(n) and by taking an extra new array for storing the sum of array element
// link for the problem related to this topic 
// 1.https://leetcode.com/problems/subarray-sum-equals-k
// 2.https://practice.geeksforgeeks.org/problems/adding-ones/0#problems
// 3.https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/best-index-1-45a2f8ff/
// 4.https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
// 5.https://www.codechef.com/tags/problems/prefix-sum

#include <bits/stdc++.h> 
using namespace std; 

void PrefixSum(int a[], int n, int prefixSum[]) 
{ 
	prefixSum[0] = a[0]; 

	// Adding present element 
	// with previous element 
	for (int i = 1; i < n; i++) 
		prefixSum[i] = prefixSum[i - 1] + a[i]; 
} 

int main() 
{ 
	int a[] = { 10, 4, 16, 20 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int prefixSum[n]; 

	PrefixSum(a, n, prefixSum); 
	for (int i = 0; i < n; i++) 
		cout << prefixSum[i] << " "; 
} 
