#include <bits/stdc++.h>

using namespace std;

int main(void) {

	string s;
	cin >> s;
	stack <char> S;

	for(auto c : s) {
		if (c== '(') s.push(c);
		else {
			if (S.empty()) {
				cout << "Mal formado" << endl;
				return 0;
			}
			S.pop();
		}
	}
	if(S.empty()) {
		cout << "Mal formado" << endl;
	} else {
	cout << "Bem formado" << endl;
	}
}