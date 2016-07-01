#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int v[N];
bool vis[N];

int main(void) {

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	int rod = 0;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {

		if(vis[i]) {
			continue;
		}
		vis[i] = true;
		int y = v[i];	
		int cnt = 1;
		
		while (y != i) {
			vis[y] = true;
			y = v[y];
			cnt++;
		}
		if (cnt > rod) {
			rod = cnt;
			ans = cnt;
		} else if (cnt == rod){
			ans += cnt;
		}
	}
	cout << ans << endl;
}