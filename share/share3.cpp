#include <iostream>
#include <climits>

using namespace std;

#define MAX 1001000

int array[MAX];
int sums[MAX];
int N;

bool check(int limit)
{
	int count = 0;
	int sum = 0;

	for (int i = 0; i < N; ++i)
	{
		if (sum + array[i] > limit)
		{
			++count;
			sum = array[i];
		}
		else
		{
			sum += array[i];
		}

		if (count == 3)
			return false;
	}

	return true;
}

int main()
{
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> array[i];
		sum += array[i];
	}

	int ans = 42;
	for (int i = sum / 3; i < sum; ++i)
	{
		if (check(i))
		{
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
