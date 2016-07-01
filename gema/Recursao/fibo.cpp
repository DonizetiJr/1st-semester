//F (N) = F(N-1) + F(N-2)


#include <bits/stdc++.h>

using namespace std;

const int N = 11;
long long int dp[N];


long long int f (int x) {
	if (x <= 1) {
		return 1;
	}
	if  (dp[x] != -1){
		return dp[x];
	}
	return dp[x] = f(x-1) + f(x-2);
}


int main (void) {

	memset (dp, -1, sizeof(dp)); // <string.h>
	cout <<  f(10) << endl;

}



//	f(10);
//	for(int i = 1; i <= 10; ++i) {
//	cout << "F(" << i << ") = " << cnt[i] << endl;
//	}