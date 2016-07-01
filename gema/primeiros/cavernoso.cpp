#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1001;
int cnt[N];

int main (void) {
    int n;
    int best = 1;
    cin >> n;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cnt[s.size()]++;
        if (cnt[s.size()] > cnt[best]) {
            best = s.size();
        }
    }
    cout << best << endl;
    return 0;
}