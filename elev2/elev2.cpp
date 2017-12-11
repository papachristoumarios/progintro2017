/* Given the weighs W[i] of N people and the maximum weight B which your
 * elevator can carry (the elevator can only withstand two people), 
 * you are asked to print the minimum number that you need to call the 
 * lift in order to move eveybody to the other floor.
 */ 

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N,B,x;

void solution_with_sorting() { //O(N*logN) solution
	int W[N];
	for (int i = 0; i < N; i++) cin >> W[i];
	sort(W, W + N - 1);
	
	int l = 0, count = 0;
  
	for (int r = N - 1; l <= r; r--) {
		if (l < r && W[l] + W[r] <= B) l++;
		count++;	
	}
	cout << count << endl;
}

void solution_with_counting_sort()  { // O(N + B) solution with buckets
	int count = 0;
	int l = INT_MAX;
	int r = INT_MIN;
	int x, W[B + 1];
	for (int i = 0; i <= B; i++) W[i] = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> x;
		W[x]++;
		l = min(x, l);
		r = max(x, r);
	}
	
	while (l <= r) {
		if (l + r <= B) {
			W[l]--; 				
			while (W[l] == 0) l++;
		}
		count++; W[r]--;
		while (W[r] == 0) r--;
	}
		
	cout << count << endl;		
}

int main() {
	cin >> N >> B;
	solution_with_counting_sort();
}
