/* You are given an array A[] of N elements and an integer K
 * and you want to count the number of subarrays A[i..j] 
 * such that A[i] + ... + A[j] <= K
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() { // O(N) solution
	int N, x; ll K;
	cin >> N >> K;
	ll S[N + 1], count = 0;
	S[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		S[i] = S[i-1] + x;
	}
	
	int l, r;
	for (l = 1, r = 1; l <= N; l++) {
		while (r <= N && S[r] - S[l -1] <= K) r++;
		count += r - l;
			
	} 
	cout << count << endl;
	
}

