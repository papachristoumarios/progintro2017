#include <cstdio>
#include <algorithm>

#define MAXN 1001000

using namespace std;

int A[ MAXN + 1 ], N;

bool check( int num ) {
    int cnt = 0, sum = 0;
    for( int i = 1; i <= N; i++ ) {
        sum += A[ i ];
        if( sum > num ) {
            sum = 0;
            cnt++;
            i--;
        }
        if( cnt == 3 ) return false;
    }
    return true;
}

int main( void ) {
    int sum = 0;
    scanf("%d", &N );
    for( int i = 1; i <= N; i++ ) {
      scanf("%d", &A[ i ] );
      sum += A[ i ];
    }
    int lo = 0, hi = sum, ans = sum;
    while( lo <= hi ) {
        int mid = ( lo + hi ) / 2;
        if( check( mid ) ) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans );
    return 0;
}
