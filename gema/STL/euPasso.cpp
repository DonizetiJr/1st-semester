#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int n, tamanho;

	cin >> n;
	vector <string> v;
	tamanho =n;

	string x;
		cin >> x;
		v.push_back(x);
	
	for (int i=1; i<n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
		
		for(int j = 1; j<v.size(); j++) {
			if(v[j-1] == x) {
				tamanho--;
				break;
			}
		}

	}
	
	
		cout << tamanho << endl;
}