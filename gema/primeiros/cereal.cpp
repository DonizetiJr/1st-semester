#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int dp[N][N];

int F (int x, int n) {
	if (x == 0) {
		return 1;
	}
	
	int res = 0;
	for(int p = n; p <= x; p += n) {
		res += F(x - p, p);
	}
	if  (dp[x][n] != -1){
		return dp[x][n];
	}
	return dp[x][n] = res;
}

int main (void) {

	int n;
	cin >> n;
	int res = 0;

	memset (dp, -1, sizeof(dp));
	for(int p = 1; p <= n; ++p) {
		res += F(n - p, p);
	}
	cout << res << endl;

}