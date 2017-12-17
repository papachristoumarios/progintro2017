// in-class implementation - optimal solution
#include <iostream>
#include <climits>

using namespace std;

#define MAX 1001000

int array[MAX];
int sums[MAX];
int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> array[i];

	sums[0] = 0;
	for (int i = 1; i <= N; ++i)
		sums[i] = array[i-1] + sums[i-1];

	int ans = INT_MAX;

	int i = 1, j = 2;
	while (true)
	{
		if (j >= N || i == j)
			break;

		int sum1 = sums[i];
		int sum2 = sums[j] - sums[i];
		int sum3 = sums[N] - sums[j];

		if (sum3 >= sum2 && sum3 >= sum1)
		{
			ans = min(ans, sum3);
			++j;
		}
		else if (sum2 >= sum1)
		{
			ans = min(ans, sum2);
			++i;
		}
		else
		{
			ans = min(ans, sum1);
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
