/* Subarray Sum Equals K (Positive Integers Only)
||
|| Sliding Window (Two Pointers)
||
|| Subarray(L...R) = A smaller(Sub) Array inside an Array with all elements from Index L...R
|| Subarray-Sum(L...R) = Sum of elements in Subarray(L...R) 
||
|| We look at blocks(L...R) / Subarrays(L...R): Fix L at a point and increment R.
|| We thus effectively look at the family of Subarrays starting from L.
|| If in the family of Subarrays(L...R), we find a Subarray-Sum(L...R) >= Target,
|| we move to the family of Subarrays(L+1, R), i.e., increment L by 1, and adjust Subarray-Sum
|| 
|| Note: Works because there are only Positive Integers (arr[i] > 0); a higher Sum cannot fall down
|| Time Complexity: O(N)
|| Space Complexity: O(N) Input / O(1) Algo
||
*/

#include <bits/stdc++.h>

using namespace std;

// Counts subarrays whose elements sum to the target.
int subarraySum(vector<int> &arr, int target) {
	int n = arr.size();
	
	int sum = 0;
    int cnt = 0;
    int L = 0;
    // At most 2n Operations. L can not exceed R  
    for(int R = 0; R < n; R++) { 
        sum += arr[R];
    
        while(sum >= target) {	
            if(sum == target) cnt++;
            sum -= arr[L];
            L++;
        } 
    }
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);	
    for(int i = 0; i < n; i++) cin >> arr[i];
        
    int cnt = subarraySum(arr, target);
    cout << cnt << '\n';
    	
    return 0;
}

// Problem Links: 
// https://cses.fi/problemset/task/1660
