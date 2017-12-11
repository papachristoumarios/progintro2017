/* You are given the position of N chilren as coordinates on the x-axis
 * and a radius K. You want to place an ice-cream maker  in a position
 * such that the total number of happy children is maximized and you are
 * asked to output this count.
 */ 

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() { // O(N) solution
	int N, K; 
	cin >> N >> K;
	int a[N + 1];
	for (int i = 1; i <= N; i++) cin >> a[i];
	int l = 1, r = 2, count = 1, maximum = INT_MIN;
	
	while (r <= N) {
		if ( a[r] - a[l] <= 2*K) {
			r++; count++;
		}
		else {
			l++; count--;
		}
		maximum = max( maximum, count);		
	}
	cout << maximum << endl;
	
}
