
//Since it is known that a number occurs 2N – 1 times in all the subset of the given array of size N. 
//So, if a number X is prime then the contibution of X will be X * X * X * ….. * 2N – 1 times i.e. After that value each can be calculated
// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 
  
  // Following is the fermat theorem to find out power with large expoo
int power(int a, int b, int mod) 
{ 
    int aa = 1; 
    while(b) 
    { 
        if(b & 1) 
        {  
            aa = aa * a; 
            aa %= mod; 
        } 
        a = a * a; 
        a %= mod; 
        b /= 2; 
    } 
    return aa; 
} 
  
// Function to return the prime subset  
// product of the given array 
int product(int A[], int n) 
{ 
  
    // Create Sieve to check whether a 
    // number is prime or not 
    int N = 100010; 
    int mod = 1000000007; 
    vector<int> prime(N, 1); 
    prime[0] = prime[1] = 0; 
    int i = 2; 
    while (i * i < N) 
    { 
        if (prime[i]) 
            for (int j = 2 * i; 
                     j <= N;j += i) 
                prime[j] = 0; 
  
        i += 1; 
    } 
  
    // Length of the array 
    // Calculating 2^(n-1) % mod 
    int t = power(2, n - 1, mod - 1); 
  
    int ans = 1; 
  
    for (int j = 0; j < n; j++) 
    { 
        int i = A[j]; 
  
        // If element is prime then add 
        // its contribution in the result 
        if( prime[i]) 
        { 
            ans *= power(i, t, mod); 
            ans %= mod; 
        } 
    } 
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    int A[] = {3, 7}; 
      
    int n = sizeof(A) / sizeof(A[0]); 
      
    printf("%d", product(A, n)); 
} 
