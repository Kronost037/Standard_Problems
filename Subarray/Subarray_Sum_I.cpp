/* Subarray Sum Equals K with Only Positive Integers
||
|| Sliding Window (Two Pointers)
||
|| Subarray(L...R) = A smaller(Sub) Array inside an Array with elements from Index L...R
|| Subarray sum(L...R) = Sum of elements in Subarray(L...R) 
||
|| We look at blocks(L...R) / Subarrays(L...R): Fix L at a point and increment R.
|| We thus effectively look at the family of Subarrays starting from L.
|| If in the family of Subarrays(L...R), we find a Subarray Sum(L...R) >= Target,
|| we move to family of Subarrays(L+1, R), i.e., increment L by 1, and adjust Subarray Sum
|| 
|| Constraints: Works because there are only Positive Integers (arr[i] > 0); a higher Sum cannot fall down
|| Time Complexity: Worst Case, L and R both reach the end --> 2*N Ops for N elements --> O(N)
|| Space Complexity: N-sized vector only for input; algorithm uses constant space --> O(N) Input / O(1) Algo
||
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);	
    for(int i = 0; i < n; i++) cin >> arr[i];
        
    int sum = 0;
    int cnt = 0;
    int L = 0;
    for(int R = 0; R < n; R++) { 
        sum += arr[R];
    
        while(sum >= target) {	
            if(sum == target) cnt++;
            sum -= arr[L];
            L++;
        } 
    }
    
    cout << cnt << '\n';
    	
    return 0;
}

// Problem Links: 
// https://cses.fi/problemset/task/1660
