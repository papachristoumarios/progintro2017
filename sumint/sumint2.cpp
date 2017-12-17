// in-class implementation 
#include <iostream>
#include <climits>

using namespace std;

#define MAX 1001000

int array[MAX];
int sums[MAX];
int N, K;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> array[i];

	sums[0] = 0;
	for (int i = 1; i <= N; ++i)
		sums[i] = array[i-1] + sums[i-1];

	long long int ans = 0;

	int left = 1, right = 1;
	for (left = 1; left <= N; left++)
	{
		while(right <= N && sums[right] - sums[left-1] <= K)
		{
			right++;
		}
		ans += right - left;
	}

	cout << ans << endl;

	return 0;
}
