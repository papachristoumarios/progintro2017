#include <cstdio>
#include <algorithm>

#define MAXN 1000100

using namespace std;

int N, M, u, s = 0, maxim[ MAXN + 1 ], minim[ MAXN + 1 ];

int main( void ) {
  scanf("%d%d", &N, &M );
  for( int i = 0; i < N; i++ ) {
    scanf("%d", &u );
    s += u;
    maxim[ s % M ] = s;
    if( !minim[ s % M ] && s % M > 0 ) minim[ s % M ] = s;
  }
  int ans = 0;
  for( int i = 0; i < M; i++ ) ans = max( ans, maxim[ i ] - minim[ i ] );
  printf("%d\n", ans );
  return 0;
}
