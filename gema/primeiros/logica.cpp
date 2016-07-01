#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if ((x > 0 and x%2 == 0) or (x < 0 and x%2 == 0)) {
			ans++;
                }
	}
	printf("%d\n", ans);
}


	return 0;
}