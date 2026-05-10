/* Subarray Sum Equals K with Negative Integers
||
|| Prefix Sums
|| 
|| Subarray(L...R) = A smaller(Sub) array inside an array with elements from Index L...R
|| Subarray Sum(L...R) = Sum of elements in Subarray(L...R) 
|| Pref[i] = Subarray Sum(0...i)
||
|| Subarray Sum(L...R) = Pref[R] - Pref[L - 1]
|| We want Subarray Sum(L...R) = Target --> Pref[R] - Pref[L - 1] = Target --> Pref[R] - x = pref[L - 1]
|| So, If ( Sum till R ) - x == ( Sum till some index before R ), cnt++
|| 
|| Note: Prefix Array is not explicitly required.
|| Time Complexity: R goes from 0 to N, and log N (avg>) for Hash Table (Map) --> N * 2log N Ops --> O(Nlog N)
|| Space Complexity: N-sized vector for Input, and N-sized Map for Algo (Worst case) --> O(N) 
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
	
	long long cnt = 0;
	long long sum = 0;
	map<long long, int> countSum;  // Prefix sums for fast look up. Not prefix array
	countSum[0]++;                 // Empty array sum. Not standard prefix sum. 
				                   // Catches Pref[R] = Target cases, ie, subarrays starting from index 0 
	for(int R = 0; R < n; R++) {
		sum += arr[R];
		long long need = sum - target;
		cnt += countSum[need];
		countSum[sum]++;
	}

	cout << cnt << '\n';

	return 0;
}

// Problem Links:
// https://cses.fi/problemset/task/1661
// https://leetcode.com/problems/subarray-sum-equals-k
